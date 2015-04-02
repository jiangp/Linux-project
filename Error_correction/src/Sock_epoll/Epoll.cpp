/*************************************************************************
	> File Name: Epoll.cpp
	> Author: Arwen
	> Mail:745529725@qq.com 
	> Created Time: Tue 31 Mar 2015 09:56:43 AM CST
 ************************************************************************/

#include"Epoll.h"
void Epoll::epoll_add_fd(int fd)
{
	struct epoll_event ev;
	ev.data.fd = fd;
	ev.events = EPOLLIN;
	if(epoll_ctl(m_epoll_fd, EPOLL_CTL_ADD, fd, &ev) == -1)
	{
		std::cout << "epoll_ctl" << std::endl;
	    exit(1);
	}
}

Epoll::Epoll(int listenfd)          //初始化  create epoll
	: m_listenfd(listenfd)
{
	m_epoll_fd = epoll_create(2048);
	if(m_epoll_fd == -1){
	   std::cout << "epoll_create" << std::endl;
	   exit(1);
	}
	memset(&m_events, 0, sizeof(m_events));
	epoll_add_fd(listenfd);
}

void Epoll::epoll_loop()   //wait 函数
{
	int nready;
	do{
		nready = epoll_wait(m_epoll_fd, m_events, sizeof(m_events), 10000);
	}while(nready == -1 && errno == EINTR);

	if(nready == -1)
	{

	   std::cout << "epoll_wait!" << std::endl;
	   exit(1);
	}else if(nready == 0)
	{
		m_ready = 0;
	}else
		m_ready = nready;
}

void Epoll::epoll_handle_fd(Pool_t &thp, MyConf &conf)       //执行监听
{
	for(int i = 0; i < m_ready; ++i)
	{
		int fd = m_events[i].data.fd;
		if(fd == m_listenfd)             //监听是否为客户端连接
		{
			if(m_events[i].events &EPOLLIN)
			{
				 int perrfd = accept(m_listenfd, NULL, NULL);     //accept
				 if(perrfd == -1)
				 {
					 std::cout << "epoll_accept!" << std::endl;
					 exit(1);
				 }
				 epoll_add_fd(perrfd);              //事件注册  ，监听类型         
				 std::cout << " one client connect!"<<std::endl;
			}
		}else
		{
			if(m_events[i].events & EPOLLIN)
			{
				char recvbuf[1024] = {0};
				size_t nread = read(fd, recvbuf, sizeof(recvbuf)); //接收msg
				if(nread == 0)
				{
					struct epoll_event ev;
					ev.data.fd = fd;
					epoll_ctl(m_epoll_fd, EPOLL_CTL_DEL, fd, &ev);//删除事件
					std::cout << "one client leave" << std::endl;
					close(fd);
					continue;
				}

				Task task(recvbuf, fd, conf);			
				thp.addTask(task);
			}
		}
	}
}

void Epoll::epoll_destroy()
{
	close(m_epoll_fd); //关闭监听
}
