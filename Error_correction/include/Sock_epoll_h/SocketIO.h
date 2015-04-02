/*************************************************************************
	> File Name: SocketIO.h
	> Author: Arwen
	> Mail:745529725@qq.com 
	> Created Time: Sat 28 Mar 2015 07:32:32 PM CST
 ************************************************************************/
#ifndef SOCKIO_H
#define SOCKIO_H

#include"Noncopyable.h"
#include<sys/types.h>
#include<unistd.h>
#include<errno.h>
#include<stdio.h>
#include<stdlib.h>
#include<sys/socket.h>

class SocketIO : private Noncopyable
{
public:
	explicit SocketIO(int sockfd)
		: m_sockfd(sockfd)
	{
	}

	ssize_t readn(char *buf, size_t count);
	ssize_t writen(const char *buf, size_t count);
	ssize_t readline(char *usrbuf, size_t count);
private:
	ssize_t recv_peek(char *buf, size_t len);
	const int m_sockfd;
};

#endif

