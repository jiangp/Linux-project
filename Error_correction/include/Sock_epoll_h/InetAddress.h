/*************************************************************************
	> File Name: InetAddress.h
	> Author: Arwen
	> Mail:745529725@qq.com 
	> Created Time: Fri 27 Mar 2015 05:29:34 PM CST
 ************************************************************************/

#ifndef _INETADDR_H
#define _INETADDR_H

#include<string>
#include<netinet/in.h>
#include"Noncopyable.h"

typedef struct sockaddr SA;
typedef struct sockaddr_in SAI;

class InetAddress : private Noncopyable
{
public:
	explicit InetAddress(uint16_t port);
	InetAddress(const std::string &, uint16_t);
	InetAddress(const struct sockaddr_in &addr);
	
	//set get
	void setSockAddrInet(const struct sockaddr_in &addr)
	{ m_addr = addr; }
	const struct sockaddr_in *getSockAddrInet() const
	{ return &m_addr; }
	
	//ip port 
	std::string toIP() const;
	uint16_t toPORT() const;
	
private:
	struct sockaddr_in m_addr;
};
#endif
