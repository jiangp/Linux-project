/*************************************************************************
	> File Name: ClientSocket.cpp
	> Author: Arwen
	> Mail:745529725@qq.com 
	> Created Time: Sat 28 Mar 2015 08:55:49 PM CST
 ************************************************************************/

#include"ClientSocket.h"
#include"InetAddress.h"
#include<sys/socket.h>
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<arpa/inet.h>
#include<errno.h>
#include<netinet/in.h>
#include<netinet/tcp.h>
#include<netdb.h>
#include<unistd.h>
#include<sys/types.h>

ClientSocket::ClientSocket()
{
}

ClientSocket::~ClientSocket()
{
}

void ClientSocket::init(int protocol)
{
	if(IPPROTO_TCP == protocol)
	{
		m_sockfd = socket(AF_INET, SOCK_STREAM, protocol);
		if(-1 == m_sockfd)
		{
			perror("create sockret error\n");
			exit(EXIT_FAILURE);
		}
	}else
	{
		m_sockfd = socket(AF_INET, SOCK_DGRAM, protocol);
		if(-1 == m_sockfd)
		{
			perror("create sockret error\n");
			exit(EXIT_FAILURE);
		}
	}
}

void ClientSocket::Connect(InetAddress &addr)
{
	if(-1 == connect(m_sockfd, (struct sockaddr *)addr.getSockAddrInet(), sizeof(struct sockaddr)))
	{
		perror("connect failed");
		exit(EXIT_FAILURE);
	}
}

int ClientSocket::get_socket() const
{
	return m_sockfd;
}
