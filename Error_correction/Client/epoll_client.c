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
//#define SER_IP "192.168.1.128"
//#define SER_PORT 1235
#define MY_ASSERT(flag, msg) do{flag || (printf("%s\n",msg), exit(1), 0);}while(0) //判断机制
int main(int argc ,  char *argv[])
{
	int fd_client;
	char buf[1024];
	MY_ASSERT((fd_client = socket(AF_INET,SOCK_STREAM ,0))!=-1 ,"listen socket init"); //执行Socket 函数

	struct sockaddr_in cliaddr;
	memset(&cliaddr, 0, sizeof(cliaddr));
	cliaddr.sin_family = AF_INET;
	cliaddr.sin_port = htons( atoi(argv[2]) );
	cliaddr.sin_addr.s_addr = inet_addr(argv[1]);

    MY_ASSERT(connect(fd_client, (struct sockaddr*)&cliaddr, sizeof(cliaddr)) ==0,"connect");   //客户端连接函数
	while(1)
	{
		memset(buf ,0 , 1024);
		fgets(buf ,1024, stdin);
		write(fd_client, buf, sizeof(buf));    //write
		memset(buf, 0, 1024);
		read(fd_client, buf, sizeof(buf));    //read
		printf(">:%s\n", buf);

	}
	return 0;
}
