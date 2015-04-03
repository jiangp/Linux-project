/*************************************************************************
	> File Name: Epoll.h
	> Author: Arwen
	> Mail:745529725@qq.com 
	> Created Time: Sat 28 Mar 2015 10:20:45 PM CST
 ************************************************************************/
#ifndef _EPOLL_H
#define _EPOOL_H

#include<sys/epoll.h>

typedef void (*callback_t) (const char*, size_t cnt, int fd);

typedef struct{
	int m_epoll_fd;
	int m_listenfd;
	struct epoll_event m_events[2048];
	int m_nready;
	callback_t m_callback;
}epoll_t;

void epoll_init(epoll_t *et, int listenfd, callback_t callback);
void epoll_loop(epoll_t *et);
void epoll_handle_fd(epoll_t *et);
void epoll_destroy(epoll_t *et);

#endif

