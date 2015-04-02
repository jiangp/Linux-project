/*************************************************************************
	> File Name: main.cpp
	> Author: Arwen
	> Mail:745529725@qq.com 
	> Created Time: Sun 29 Mar 2015 09:09:42 PM CST
 ************************************************************************/

#include<string>
#include<iostream>
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<unistd.h>
#include<time.h>
#include<errno.h>
#include<sys/epoll.h>
#include"MyConf.h"
#include"Pool.h"
#include"InetAddress.h"
#include"Socket.h"
#include"SocketIO.h"

//typedef void (*callback_t)(const char*, size_t cnt, int fd);
void foo(const char* buf, size_t cnt ,int peerfd)
{
	std::cout << buf << std::endl;	
	write(peerfd, buf, cnt);
}

int main(int argc, char **argv)
{
	//conf
	MyConf a(argv[1]);
	a.save_to_vector();
	a.index_to_map();

	//pool
	Tiny::Pool pool(10, 10);
	pool.start();

	//inetAddress
	InetAddress addr(a.get_IP(), a.get_PORT());
	
	std::cout << a.get_IP() << " " << a.get_PORT() <<std::endl;
	//socket
	int fd_listen, Client_fd;
	Socket sock;
	fd_listen = sock.init(0);
	sock.bindAddress(addr);
	sock.listen();

	//epoll
	int epfd = epoll_create(2048);
	struct epoll_event ev, m_events[1024];
	int ready_events, index;
	memset(&m_events, 0, sizeof(m_events));
	ev.events = EPOLLIN;
	ev.data.fd = fd_listen;
	epoll_ctl(epfd, EPOLL_CTL_ADD, fd_listen, &ev);

	while(1)
	{
		memset(m_events, 0, sizeof(m_events));
		ready_events = epoll_wait(epfd, m_events, 1024, -1);
		for(index = 0; index < ready_events; ++index)
		{
			if(m_events[index].data.fd == fd_listen)
			{
				int Client_fd = sock.accept();
				printf("a client connect!\n");
				memset(&ev, 0, sizeof(ev));
				ev.events = EPOLLIN;
				ev.data.fd = Client_fd;
				epoll_ctl(epfd, EPOLL_CTL_ADD, Client_fd, &ev);
				
			}else if(m_events[index].events & EPOLLIN)
			{
				printf("recv\n");
				char msg[1024] ={0};
				if(recv(m_events[index].data.fd, msg, sizeof(msg), 0) == -1)
				{
					std::cout << "one client exit.\n" << std::endl;
					epoll_ctl(epfd, EPOLL_CTL_DEL,m_events[index].data.fd, NULL);
				}
				else{
				
					foo(msg, ready_events, m_events[index].data.fd);// pool not handle
					Task task(msg, m_events[index].data.fd);
					pool.addTask(task);

				}
			}
		}
	}
	return 0;
}
