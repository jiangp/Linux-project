/*************************************************************************
	> File Name: epoll.cpp
	> Author: Arwen
	> Mail:745529725@qq.com 
	> Created Time: Sat 28 Mar 2015 10:38:36 PM CST
 ************************************************************************/

#include"epoll.h"
#include"sysutil.h"

void epoll_init(epoll_t *et, int listenfd, callback_t callback)
{
	et->m_epoll_fd = epoll_create(2048);
	if(et->m_epoll_fd == -1)
		ERR_EXIT("epoll_create\n");
	et->m_listenfd = listenfd;
	memset(&et->m_events, 0,sizeof(et->m_events));
	et->m_callback = callback;
	//let listenfd in epoll
	epoll_addr_fd(et, listenfd);
}

