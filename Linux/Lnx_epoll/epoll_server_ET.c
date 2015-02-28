/*************************************************************************
  > File Name: epoll_server_ET.c
  > Author: Arwen
  > Mail:745529725@qq.com 
  > Created Time: Fri 27 Feb 2015 05:24:37 PM CST
 ***********************************************************************/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<unistd.h>
#include<sys/socket.h>
#include<sys/types.h>
#include<arpa/inet.h>
#include<netinet/in.h>
#include<sys/epoll.h>
#include<sys/select.h>
#include<sys/time.h>
#include<fcntl.h>
#include<errno.h>
#define SER_IP "192.168.1.124"
#define SER_PORT 1234
#define MY_ASSERT(flag, msg) do{flag || (printf("%s\n",msg), exit(1), 0);}while(0)

void setnonblock(int sfd)
{
	int old_flag ;
	old_flag = fcntl(sfd, F_GETFL);
	old_flag = old_flag | O_NONBLOCK ;
	// old_flag &= ~O_NONBLOCK;
	fcntl(sfd, F_SETFL, old_flag);
}
int main(int argc ,  char *argv[])
{
	int fd_listen ,epoll_fd;
	int fd_client;
	MY_ASSERT((fd_listen = socket(AF_INET,SOCK_STREAM ,0))!=-1 ,"listen socket init");//socket

	struct sockaddr_in seraddr;
	memset(&seraddr, 0, sizeof(seraddr));
	seraddr.sin_family = AF_INET;
	seraddr.sin_port = htons(SER_PORT);
	seraddr.sin_addr.s_addr = inet_addr(SER_IP);
	MY_ASSERT(bind(fd_listen, (struct sockaddr*)&seraddr, sizeof(seraddr))==0, "bind");//bind

	MY_ASSERT(listen(fd_listen, 5) == 0, "listen");//listen

	MY_ASSERT((epoll_fd = epoll_create(1024)) != -1, "epoll create");//epoll_create
	struct epoll_event my_event, my_events[1024];
	char buf[1024] = "0";
	int ready_events, index;
	memset(&my_event, 0, sizeof(my_event));
	my_event.events = EPOLLIN;
	my_event.data.fd = fd_listen;
	MY_ASSERT(epoll_ctl(epoll_fd, EPOLL_CTL_ADD, fd_listen, &my_event) == 0, "epoll ctl");//epoll_ctl  people
	
	while(1)
	{
		memset(my_events, 0 ,sizeof(my_events));
		ready_events = epoll_wait(epoll_fd, my_events, 1024, -1);//epoll_wait

		for(index = 0 ; index < ready_events; index++)//send_pepple numbers
		{
			if(my_events[index].data.fd == fd_listen )//if   people or event
			{

				fd_client =accept(my_events[index].data.fd ,NULL ,NULL);//accept one connect
				printf("a client connect.\n");
				setnonblock(fd_client);
				memset(&my_event , 0 ,sizeof(my_event));
				my_event.events = EPOLLIN;
				my_event.data.fd = fd_client;
				MY_ASSERT(epoll_ctl(epoll_fd, EPOLL_CTL_ADD, fd_client, &my_event) == 0, "epoll  client"); // epoll_ctl events


			}else if(my_events[index].events & EPOLLIN)//  events
			{
				int recv_ret;
				int recv_sum = 0;
				memset(buf, 0 , 1024);
				while(1)
				{	
					recv_ret = recv(my_events[index].data.fd, buf + recv_sum, 1024 - recv_sum, 0) ; 
					if(recv_ret == -1 && errno ==EAGAIN)
					{
						printf("recv from client :%s\n",buf);
						break ;
					}
					else if(recv_ret > 0)
					{
						recv_sum+= recv_ret ;
					}
					else if(recv_ret == 0 )
					{
						printf("one client exit.\n");

						MY_ASSERT(epoll_ctl(epoll_fd, EPOLL_CTL_DEL, my_events[index].data.fd, NULL) == 0, "epoll over!");//over one people
						break;
					}
				}
			}
		}
	}
	return 0;
}
