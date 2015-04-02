/*************************************************************************
	> File Name: ./src/pool_child.c
	> Author: Arwen
	> Mail:745529725@qq.com 
	> Created Time: Thu 19 Mar 2015 10:55:30 PM CST
 ************************************************************************/

#include"head.h"
static void child_main(int fd);
void make_child(pchild_t childs, int nchild)
{
	int index = 0;
	while(nchild > 0)
	{
		int fds[2];
		if(-1 == socketpair(AF_LOCAL, SOCK_STREAM, 0, fds))
		{
			perror("socketpair");
			exit(1);
		}
		pid_t pid = fork();
		if(pid == 0) //0
		{
			close(fds[1]);
			child_main(fds[0]);
			exit(1);
		}
		close(fds[0]);
		childs[index].ch_fd = fds[1];
		childs[index].ch_pid = pid ;
		childs[index].ch_busy = 0 ;
		index ++;
		nchild --;
	}
}
static void child_main(int fd)
{
	int fd_client ;
	int flag = 1;
	while(1)
	{
		recv_fd(fd, &fd_client);//recv  from father fork //wait
		handle_request(fd_client);//seng msg
		write(fd, &flag, sizeof(flag));
	}
}

