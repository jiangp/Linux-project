/*************************************************************************
	> File Name: Test_ClientSock.cpp
	> Author: Arwen
	> Mail:745529725@qq.com 
	> Created Time: Sat 28 Mar 2015 09:23:18 PM CST
 ************************************************************************/

#include"ClientSocket.h"
#include"InetAddress.h"
#include"SocketIO.h"
#include<string.h>
#include<stdlib.h>

int main(int argc, char **argv)
{
	InetAddress addr(argv[1], atoi(argv[2]));
	ClientSocket cltSock;
	cltSock.init(IPPROTO_TCP);
	cltSock.Connect(addr);
	SocketIO sio(cltSock.get_socket());
	while(1)
	{
		char sendbuf[1024] = "word";
		int len = sio.writen(sendbuf, strlen(sendbuf));
		printf("send %d baty data\n", len);
		sio.readn(sendbuf, sizeof(sendbuf));
	}
	return 0;
}
