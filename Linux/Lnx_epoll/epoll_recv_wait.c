/*************************************************************************
	> File Name: epoll_recv_time.c
	> Author: Arwen
	> Mail:745529725@qq.com 
	> Created Time: Fri 27 Feb 2015 06:54:41 PM CST
 ************************************************************************/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<unistd.h>
#include<fcntl.h>
#include<sys/types.h>
#include<sys/socket.h>
#include<sys/epoll.h>
#include<arpa/inet.h>
#include<netinet/in.h>
#include<errno.h>
#include<sys/time.h>
#include<sys/select.h>
#define ser_IP "192.168.1.124"
#define ser_PORT 1234
#define MY_ASSERT(flag , str) do{flag ||(printf("%s\n",str ), exit(1), 0);}while(0)
void setnonblock(int sfd);
void setblock(int sfd);
int recvtimeout(int sfd, void* buf ,int len ,int secs );
int main(int argc ,char *argv[])
{
	int fd_listen ,fd_client;
	int recv_ret;
	MY_ASSERT((fd_listen = socket(AF_INET, SOCK_STREAM, 0)) != -1, "socket");

	struct sockaddr_in seraddr;
	memset(&seraddr, 0 , sizeof(seraddr));
	seraddr.sin_family = AF_INET;
	seraddr.sin_port = htons(ser_PORT);
	seraddr.sin_addr.s_addr = inet_addr(ser_IP);

	MY_ASSERT(bind(fd_listen, (struct sockaddr*)&seraddr, sizeof(seraddr)) == 0, "bind");

	MY_ASSERT(listen(fd_listen, 5) == 0, "listen");
    
	struct sockaddr_in clientaddr;
	memset(&clientaddr, 0 , sizeof(clientaddr));
	int addr_len = sizeof(clientaddr);

    fd_client = accept(fd_listen, (struct sockaddr*)&clientaddr, &addr_len);
	//setnonblock(fd_client);
	char buf[1024];
	while(1)
	{
		memset(buf , 0, sizeof(buf));

		printf("recv.............\n");

		recv_ret = recvtimeout(fd_client, buf , sizeof(buf), 5);
		if(recv_ret == -1 &&errno == EAGAIN)
		{
			continue;
		}else if(recv_ret >0)
		{
			puts(buf);
            // setblock(fd_client);
		}else if(recv_ret == 0)
		{
			printf("client close !\n");
			break ;
		}
	}
	return 0;
}
void setnonblock(int sfd)
{
	int old_flag ;
	old_flag = fcntl(sfd, F_GETFL);
	old_flag = old_flag | O_NONBLOCK ;
	fcntl(sfd, F_SETFL, old_flag);
}
void setblock(int sfd)
{
	int old_flag ;
	old_flag = fcntl(sfd, F_GETFL);
	old_flag &= ~O_NONBLOCK ;
	fcntl(sfd, F_SETFL, old_flag);
}
int recvtimeout(int sfd, void* buf ,int len ,int secs )
{
	fd_set rdsets ;
	int ret ;
	struct timespec tm;
	FD_ZERO(&rdsets);
	FD_SET(sfd, &rdsets);
	tm.tv_sec= secs ;
	tm.tv_nsec = 0;

	ret = pselect(sfd + 1, &rdsets, NULL, NULL, &tm,NULL);
	if(ret == 0)
	{
		printf("time out !\n");
		errno =EAGAIN ;
		return -1;
	}else if(ret == -1)
	{
		printf("error\n");
	}else 
	{
		return recv(sfd, buf, len, 0);
	}
}
