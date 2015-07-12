/*************************************************************************
	> File Name: socket.cpp
	> Author: Arwen
	> Mail:745529725@qq.com 
	> Created Time: Fri 27 Mar 2015 10:23:01 PM CST
 ************************************************************************/
#include"socket.h"
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<stdlib.h>
#include<unistd.h>
#include<errno.h>
#include<sys/types.h>
#include<sys/socket.h>
#include<netinet/in.h>
#include<arpa/inet.h>
#include<netinet/tcp.h>
#include<netdb.h>

Socket::Socket(int sockfd)
	:m_sockfd(sockfd)
{
}

Socket::Socket()
{}

Socket::~Socket()
{
	::close(m_sockfd);
}

int Socket::init(int protocol)
{

	if(protocol == 0)
	{
		m_sockfd = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
		if(-1 == m_sockfd)
		{
			perror("create socket error");
			exit(EXIT_FAILURE);
		}
		return m_sockfd;
	}else
	{
		m_sockfd = socket(AF_INET, SOCK_DGRAM, IPPROTO_UDP);
		if(-1 == m_sockfd)
		{
			perror("create socket error");
			exit(EXIT_FAILURE);
		}
		return m_sockfd;
	}
}

void Socket::bindAddress(const InetAddress &addr)
{
	if(::bind(m_sockfd, (SA*)addr.getSockAddrInet(), sizeof(addr)) == -1)//地址绑定
	{
		perror("bind address error");
		exit(EXIT_FAILURE);
	}
}
void Socket::listen()
{
	if(::listen(m_sockfd, SOMAXCONN) == -1)
	{
		perror("listen address error");
		exit(EXIT_FAILURE);
	}
}

int Socket::accept()
{
	int fd = ::accept(m_sockfd, NULL, NULL);
	if(fd == -1)
	{
		perror("accept error");
		exit(EXIT_FAILURE);
	}
	return fd;
}

