/*************************************************************************
	> File Name: Socket.h
	> Author: Arwen
	> Mail:745529725@qq.com 
	> Created Time: Fri 27 Mar 2015 09:49:41 PM CST
 ************************************************************************/

#ifndef _SOCKET_H
#define _SOCKET_H

#include"InetAddress.h"

class Socket
{
public:
	explicit Socket(int sockfd);
	Socket();
	~Socket();

	int fd() const {return m_sockfd; }
	void bindAddress(const InetAddress &addr);
	void listen();
	int accept();
	int init(int protocol);
	void shutdownWrite();

	void setTcpNoDelay(bool on);
	void setReueseAddr(bool on);
	void setReuesePort(bool on);
	void setKeepAlive(bool on);

	//static
	static InetAddress getLocalAddress(int sockfd);
	static InetAddress getpeerAddress(int sockfd);

private:
	int m_sockfd;
};

#endif

