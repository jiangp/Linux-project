/*************************************************************************
	> File Name: InetAddress.cpp
	> Author: Arwen
	> Mail:745529725@qq.com 
	> Created Time: Fri 27 Mar 2015 05:30:11 PM CST
 ************************************************************************/

#include"InetAddress.h"
#include<string.h>
#include<stdio.h>
#include<stdlib.h>
#include<sys/socket.h>
#include<netinet/in.h>
#include<arpa/inet.h>

InetAddress::InetAddress(uint16_t port)
{
	::memset(&m_addr, 0, sizeof(m_addr));
	m_addr.sin_family = AF_INET;
	m_addr.sin_addr.s_addr = INADDR_ANY;
	m_addr.sin_port = htons(port);
}
InetAddress::InetAddress(const std::string &ip, uint16_t port)
{
	::memset(&m_addr, 0, sizeof(m_addr));
	m_addr.sin_family = AF_INET;
	m_addr.sin_port = htons(port);
	if(inet_aton(ip.c_str(), &m_addr.sin_addr) == 0)
	{
		fprintf(stderr, "ip invalid\n");
		exit(EXIT_FAILURE);
	}
}

InetAddress::InetAddress(const struct sockaddr_in &addr)
	: m_addr(addr)
{
}

std::string InetAddress::toIP() const
{
	return inet_ntoa(m_addr.sin_addr);
}

uint16_t InetAddress::toPORT() const
{
	return ntohs(m_addr.sin_port);
}
