/*************************************************************************
	> File Name: Socket.cpp
	> Author: Arwen
	> Mail:745529725@qq.com 
	> Created Time: Fri 27 Mar 2015 10:23:01 PM CST
 ************************************************************************/
#include"Socket.h"
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
	int socketfd;
	if(protocol == 0)
	{
		m_sockfd = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
		if(-1 == m_sockfd)
		{
			perror("create socket error");
			exit(EXIT_FAILURE);
		}
	}else
	{
		m_sockfd = socket(AF_INET, SOCK_DGRAM, IPPROTO_UDP);
		if(-1 == m_sockfd)
		{
			perror("create socket error");
			exit(EXIT_FAILURE);
		}
	}
}

void Socket::bindAddress(const InetAddress &addr)
{
	if(::bind(m_sockfd, (SA*)addr.getSockAddrInet(), sizeof(addr)) == -1)
	{
		fprintf(stderr, "bind address error\n");
		exit(EXIT_FAILURE);
	}
}
void Socket::listen()
{
	if(::listen(m_sockfd, SOMAXCONN) == -1)
	{
		fprintf(stderr, "listen address error\n");
		exit(EXIT_FAILURE);
	}
}

int Socket::accept()
{
	int fd = ::accept(m_sockfd, NULL, NULL);
	if(fd == -1)
	{
		fprintf(stderr, "accept error\n");
		exit(EXIT_FAILURE);
	}
	return fd;
}


void Socket::shutdownWrite()
{
	if(::shutdown(m_sockfd, SHUT_WR) == -1)
	{
		fprintf(stderr, "shutdown error\n");
		exit(EXIT_FAILURE);
	}
}
void Socket::setTcpNoDelay(bool on)
{
	int optval = on ? 1 : 0 ;
	if(::setsockopt(m_sockfd, IPPROTO_TCP, TCP_NODELAY, &optval, static_cast<socklen_t>(sizeof(optval)) == -1))
	{
		fprintf(stderr, "setTcpNodelay error\n");
		exit(EXIT_FAILURE);
	}
}

void Socket::setReueseAddr(bool on)
{
	int optval = on ? 1 : 0;
	if(::setsockopt(m_sockfd,
					SOL_SOCKET,
					SO_REUSEADDR,
					&optval,
					static_cast<socklen_t>(sizeof(optval)) == -1))
	{
		fprintf(stderr, "setReuesAddr error\n");
		exit(EXIT_FAILURE);
	}
}

void Socket::setReuesePort(bool on)
{
#ifdef SO_REUSEPORT
	int optval = on ? 1 : 0 ;
	int ret = ::setsockopt(m_sockfd,
					SOL_SOCKET,
					SO_REUSEPORT,
					&optval,
					static_cast<socklen_t>(sizeof(optval)) == -1);
	if(ret < 0)
	{
		fprintf(stderr, "setReusePort error\n");
		exit(EXIT_FAILURE);
	}
#else
	if(on)
	{
		fprintf(stderr, "SO_REUSEPORT is not supported.\n");
	}
#endif
}


void Socket::setKeepAlive(bool on)
{
	int optval = on ? 1 : 0 ;
	if(::setsockopt(m_sockfd,
					SOL_SOCKET,
					SO_KEEPALIVE,
					&optval,
					static_cast<socklen_t>(sizeof(optval)) == -1))
	{
		fprintf(stderr, "setTcpNodelay error\n");
		exit(EXIT_FAILURE);
	}
}

//static  

InetAddress Socket::getLocalAddress(int sockfd)
{
	struct sockaddr_in addr;
	socklen_t len = sizeof(addr);
	if(::getsockname(sockfd, (SA*)&addr, &len) == -1)
	{
		fprintf(stderr, "getPeerAddress\n");
		exit(EXIT_FAILURE);
	}
	return InetAddress(addr);
}
InetAddress Socket::getpeerAddress(int sockfd)
{
	struct sockaddr_in addr;
	socklen_t len = sizeof(addr);
	if(::getpeername(sockfd, (SA*)&addr, &len) == -1)
	{
		fprintf(stderr, "getPeerAddress\n");
		exit(EXIT_FAILURE);
	}
	return InetAddress(addr);
}
