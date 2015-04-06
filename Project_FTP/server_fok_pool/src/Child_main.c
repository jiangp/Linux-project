/*************************************************************************
	> File Name: ./src/Child_main.c
	> Author: Arwen
	> Mail:745529725@qq.com 
	> Created Time: Mon 06 Apr 2015 02:02:15 PM CST
 ************************************************************************/

#include"FTP_server.h"
void child_main(int fd)
{
	int fd_client;
	int flag = 1;
	while(1)
	{
		recv_fd(fd, &fd_client);
		
		handle(fd_client);
	
		write(fd, &flag, sizeof(flag));	
	
	}
}
