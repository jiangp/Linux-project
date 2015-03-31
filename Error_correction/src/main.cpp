/*************************************************************************
	> File Name: main.cpp
	> Author: Arwen
	> Mail:745529725@qq.com 
	> Created Time: Sun 29 Mar 2015 09:09:42 PM CST
 ************************************************************************/

#include<string>
#include<iostream>
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<unistd.h>
#include<time.h>
#include<errno.h>
#include<sys/epoll.h>
#include"MyConf.h"
#include"Pool.h"
#include"InetAddress.h"
#include"Socket.h"
#include"SocketIO.h"
#include"Epoll.h"
#include"handle.h"

int main(int argc, char **argv)
{
	//conf
	MyConf a(argv[1]);
	a.save_to_vector();
	a.index_to_map();

	//pool
	Pool_t pool(10, 10);
	pool.start();

	//inetAddress
	InetAddress addr(a.get_IP(), a.get_PORT());
	
	//socket
	int fd_listen;
	Socket sock;
	fd_listen = sock.init(0);
	sock.bindAddress(addr);
	sock.listen();

	//epoll
	
	Epoll init(fd_listen, &func_handle);

	while(1)
	{
		init.epoll_loop();
		init.epoll_handle_fd(pool);
	}
	init.epoll_destroy();
	return 0;
}
