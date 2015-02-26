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
#define ser_IP "192.168.1.124"
#define ser_PORT  1234
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
  int new_fd;
	while(1)
	{
		//accept
		struct  sockaddr_in clientaddr;
		socklen_t len = sizeof(clientaddr);
		memset(&clientaddr,0,sizeof(clientaddr));
		 new_fd = accept(sockfd,(struct sockaddr*)&clientaddr, &len );
		if(new_fd == -1 )
		{
			perror("accept!\n");
			close(sockfd);
			exit(1);
		}
		printf("%s :%d success connect\n",inet_ntoa(clientaddr.sin_addr),ntohs(clientaddr.sin_port));

		//recv
		char buf[1024]={0};
		if(recv(new_fd,buf,sizeof(buf),0) == -1)
		{
			perror("recv!\n");
			close(new_fd);
			exit(1);
		}
		puts(buf);
	}
	//send

	if(send(new_fd,"hello world!\n",20,0)== -1)
	{
		perror("send!\n");
		close(new_fd);
		close(sockfd);
		exit(1);
	}

	return 0;

}
