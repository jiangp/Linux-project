/*************************************************************************
	> File Name: ClientSocket.h
	> Author: Arwen
	> Mail:745529725@qq.com 
	> Created Time: Sat 28 Mar 2015 08:50:41 PM CST
 ************************************************************************/

#ifndef _CLIENTSCK_H
#define _CLIENTSCK_H

class InetAddress;

class ClientSocket
{
public:
	ClientSocket();
	~ClientSocket();

	void init(int protocol);
	void Connect(InetAddress &addr);
	int get_socket() const;
private:
	int m_sockfd;
};

#endif

