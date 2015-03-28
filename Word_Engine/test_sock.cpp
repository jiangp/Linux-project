/*************************************************************************
	> File Name: test_sock.cpp
	> Author: Arwen
	> Mail:745529725@qq.com 
	> Created Time: Fri 27 Mar 2015 05:22:32 PM CST
 ************************************************************************/

#include<iostream>
#include<string.h>
#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include"Socket.h"
int main(int argc, char **argv)
{
	int fd = ::socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
	if(fd == -1)
	{
		perror("socket error!!!");
		exit(EXIT_FAILURE);
	}
	InetAddress addr(argv[1], atoi(argv[2]));
	std::cout << "1" << std::endl;
	Socket sock(fd);
	std::cout << "2" << std::endl;

//	sock.setTcpNoDelay(false);
//	sock.setReuesePort(true);
//	sock.setReueseAddr(true);
//	sock.setKeepAlive(false);

	sock.bindAddress(addr);
	sock.listen();
	int peerfd = sock.accept();
	while(1)
	{
		char recvbuf[1024] = {0};
		::read(peerfd, recvbuf, sizeof(recvbuf));
		printf("recve msg :%s",recvbuf);
		::write(peerfd, recvbuf,strlen(recvbuf));
	}
	return 0;
}

