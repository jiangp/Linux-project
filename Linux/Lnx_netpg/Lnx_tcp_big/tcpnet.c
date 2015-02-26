/*************************************************************************
  > File Name: tcpnet.c
  > Author: Arwen
  > Mail:745529725@qq.com 
  > Created Time: Sun 08 Feb 2015 11:47:54 AM CST
 ************************************************************************/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<sys/types.h>
#include<sys/socket.h>
#include<netinet/in.h>
#include<arpa/inet.h>
#include<unistd.h>
#define ser_IP "192.168.1.48"
#define ser_PORT  1234
//void child_main(int sfd);
int recv_buf(int sfd,char* buf ,int len );
int main(int argc, char* argv[])
{
	//socket
	int sockfd;
	sockfd = socket(AF_INET,SOCK_STREAM,0);
	if(sockfd == -1)
	{
		perror("socket!\n");
		exit(1);
	}


	//bind
	struct sockaddr_in my_addr;
	memset(&my_addr,0,sizeof(my_addr));
	my_addr.sin_family = AF_INET;
	my_addr.sin_port = htons(ser_PORT);
	my_addr.sin_addr.s_addr = inet_addr(ser_IP);
	if(bind(sockfd, (struct sockaddr*)&my_addr, sizeof(my_addr)) == -1)
	{
		perror("bind!\n");
		close(sockfd);
		exit(1);
	}
	//listen
	if(listen(sockfd,5)==-1)
	{
		perror("listen!\n");
		close(sockfd);
		exit(1);
	}

	//accept
	while(1)
	{
		struct  sockaddr_in clientaddr;
		socklen_t len = sizeof(clientaddr);
		memset(&clientaddr,0,sizeof(clientaddr));
		int new_fd = accept(sockfd,(struct sockaddr*)&clientaddr, &len );
		if(new_fd == -1 )
		{
			perror("accept!\n");
			close(sockfd);
		}

	//recv
	char buf[1024];
    int recv_len;
    memset(buf,0,1024);


   if(	-1==recv(new_fd,buf,sizeof(buf),0))//recv_len
   {
       perror("error!!!!!!!!!!\n");
	   exit(1);
    }

    printf("%s\n",buf);

    int a=  sscanf(buf,"%d",recv_len);////sscanf  error
	if(a==-1)
	{
		perror("error!\n");
		exit(1);
	}

	printf("recv_len :%d\n",recv_len);


	int *parr = (int* )calloc(recv_len,sizeof(int));
	int recvn = recv_buf(new_fd,(char*)parr,recv_len);
	printf("recvn :%d\n",recvn);

    
	//send
	memset(buf,0,1024);
	strcpy(buf,"!!!!!\n");
	send(new_fd,buf,strlen(buf),0);
	while(1);
	close(sockfd);
	close(new_fd);
		
	}
		return 0;
}


int  recv_buf(int sfd,char* buf ,int len )
	{
		int recv_sum = 0;
		int recv_ret ;
		int recv_cnt = 0;
		while(recv_sum<len)
		{
			recv_ret = recv(sfd, buf + recv_sum ,len - recv_sum,0 );
			recv_cnt ++;
			recv_sum += recv_ret ;
	    //	printf("recv :%d\n",recv_ret);
		}
		printf("recv_cnt:%d\n",recv_cnt);
		return recv_sum;

	}
