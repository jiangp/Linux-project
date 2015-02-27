/*************************************************************************
	> File Name: client_epoll.c
	> Author: Arwen
	> Mail:745529725@qq.com 
	> Created Time: Fri 27 Feb 2015 10:43:15 AM CST
 ************************************************************************/

#include<stdio.h>
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<unistd.h>
#include<sys/socket.h>
#include<sys/types.h>
#include<arpa/inet.h>
#include<netinet/in.h>
#include<sys/epoll.h>
#define SER_IP "192.168.1.124"
#define SER_PORT 1234
#define MY_ASSERT(flag, msg) do{flag || (printf("%s\n",msg), exit(1), 0);}while(0)
int main(int argc ,  char *argv[])
{
	int fd_client;
	char buf[1024];
	MY_ASSERT((fd_client = socket(AF_INET,SOCK_STREAM ,0))!=-1 ,"listen socket init");
	struct sockaddr_in cliaddr;
	memset(&cliaddr, 0, sizeof(cliaddr));
	cliaddr.sin_family = AF_INET;
	cliaddr.sin_port = htons(SER_PORT);
	cliaddr.sin_addr.s_addr = inet_addr(SER_IP);

    MY_ASSERT(connect(fd_client, (struct sockaddr*)&cliaddr,sizeof(cliaddr)) ==0,"connect");
	while(1)
	{
		memset(buf ,0 , 1024);
		fgets(buf ,1024, stdin);
		send(fd_client, buf, 1024, 0);
	}
	return 0;
}
