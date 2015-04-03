/*************************************************************************
	> File Name: Test_Socket.cpp
	> Author: Arwen
	> Mail:745529725@qq.com 
	> Created Time: Sat 28 Mar 2015 08:19:41 PM CST
 ************************************************************************/

#include"InetAddress.h"
#include"Socket.h"
#include"SocketIO.h"
#include<string.h>
#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>

int main(int argc, char **argv)
{
	InetAddress addr(argv[1], atoi(argv[2]));
	Socket  sock;
	sock.init(0);
	sock.bindAddress(addr);
	sock.listen();
	
	int peerfd = sock.accept();
	SocketIO sio(peerfd);
	while(1)
	{
		char recvbuf[1024] = {0};
		sio.readn(recvbuf, sizeof(recvbuf));
		printf("recv mag : %s", recvbuf);
		sio.writen(recvbuf, strlen(recvbuf));

	}
	return 0;

}
