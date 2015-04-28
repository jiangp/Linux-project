/*************************************************************************
	> File Name: client_file.c
	> Author: Arwen
	> Mail:745529725@qq.com 
	> Created Time: Fri 13 Feb 2015 03:45:20 PM CST
 ************************************************************************/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/socket.h>
#include<fcntl.h>
#include<sys/stat.h>
#include<netinet/in.h>
#include<arpa/inet.h>
#include<signal.h>
#define SER_IP "192.168.122.1"
#define SER_PORT 1234
int send_buf(int sfd, char* buf,int len );
int recv_buf(int sfd, char* buf,int len );
int main(int argc, char * argv[])
{
    int fd_client;
	int send_len, recv_len ;
	char msg[1024] ;
	fd_client = socket(AF_INET, SOCK_STREAM, 0);
	if(fd_client == -1)
	{
		perror("error");
		close(fd_client);
		exit(1);
	}
	struct sockaddr_in seraddr;
	socklen_t sock_len = sizeof(seraddr);
	memset(&seraddr, 0 , 1024);
	seraddr.sin_family = AF_INET ; 
	seraddr.sin_port = htons(SER_PORT);
	seraddr.sin_addr.s_addr = inet_addr(SER_IP);

	if(-1 == connect (fd_client, (struct sockaddr*)&seraddr, 16))
	{
		perror("conneet!");
		close(fd_client);
		exit(1);
	}	
	char buf[128] = "0";
    memset( msg, 0, 1024 );
	strcpy( msg, "./client_file.c");
	send_len = strlen(msg);
	printf("%s\n",msg);

    send_buf(fd_client, (char*)&send_len, 4);
	printf("2222\n");
	fgets(buf, 128, stdin);
	send_buf(fd_client, (char*)&msg, send_len);

	printf("%s\n",msg);
	memset(msg , 0 , 1024);
	recv_buf(fd_client, (char*)&recv_len, 4);
	recv_buf(fd_client, msg, recv_len);
	if(strcmp(msg, "OK") == 0)
	{
		printf("begin recv file!\n");
	}else
	{
		printf("error file addr!\n");
		close(fd_client);
		return 0;
	}
	int fd_file = open(argv[1],O_WRONLY |O_CREAT,0666);
	if(fd_file == -1)
	{
		perror("open!");
		close(fd_client);
		exit(1);
	}
	int recv_sum = 0;
	while(1)
	{
		memset(msg , 0, 1024);
		recv_buf(fd_client , (char*)&recv_len ,4);
		if(recv_len == 0)
		{
			close(fd_file);
			break;
		}
		recv_sum += recv_buf(fd_client, msg, recv_len);
		write(fd_file, msg, recv_len);
		system("clear");
		printf("downloading... %.2fkbs\n",(double)recv_sum / 1024);
	} 
    printf("recv complient!\n"); 
	return 0;
}


int send_buf(int sfd, char* buf,int len )
{
	int send_sum = 0;
	int send_ret ;
	while(send_sum <len)
	{
		send_ret = send(sfd, buf + send_sum, len - send_sum, 0);
        send_sum += send_ret ;
	}
	return send_sum;
}
 
int recv_buf(int sfd, char* buf,int len )
{
	int recv_sum = 0;
	int recv_ret ;
	while(recv_sum <len)
	{
		recv_ret = recv(sfd, buf + recv_sum, len - recv_sum, 0);
        recv_sum += recv_ret ;
	}
	return recv_sum;

}
