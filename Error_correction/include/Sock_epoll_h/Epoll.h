/*************************************************************************
	> File Name: Epoll.h
	> Author: Arwen
	> Mail:745529725@qq.com 
	> Created Time: Tue 31 Mar 2015 10:00:52 AM CST
 ************************************************************************/

#ifndef _EPOLL_H
#define _EPOOL_H

#include<sys/epoll.h>
#include<iostream>
#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/socket.h>
#include<sys/types.h>
#include<string.h>
#include"Pool.h"

class Pool_t;

class Epoll
{
private:
	int m_epoll_fd; 
	int m_listenfd;
	struct epoll_event m_events[2048]; 
	int m_ready; //have ready infor


public:
	Epoll(int listenfd);
	void epoll_loop();
	void epoll_handle_fd (Pool_t &thp,MyConf &conf);
	void epoll_destroy();
	void epoll_add_fd(int fd);

};

#endif

