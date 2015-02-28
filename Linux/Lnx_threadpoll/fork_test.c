/*************************************************************************
	> File Name: fork_test.c
	> Author: Arwen
	> Mail:745529725@qq.com 
	> Created Time: Sat 28 Feb 2015 09:51:08 AM CST
 ************************************************************************/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<sys/types.h>
#include<unistd.h>
#include<fcntl.h>
#include<sys/stat.h>
int main(int argc ,char *argv[])
{
	int fds[2];
	//pipe(fds);
	if (-1 == socketpair(AF_LOCAL, SOCK_STREAM, 0 ,fds))
	if(fork() == 0 )
	{
		int fd_recv ;
		char buf[1024] = "";
		close(fds[1]);
		sleep(3);
		read(fds[0], &fd_recv , 4);
		if(read(fd_recv, buf , 1024) == -1)
		{
			printf("child read error!\n");
		}else
		{
			printf("read from p:%s\n",buf);
		}
		exit(1);
	}
	close(fds[0]);
    int fd = open(argv[1], O_RDONLY) ;
    char msg[1024]="";
	fgets(msg ,1024, stdin);
	send(fd, buf, 1024);
	wait(NULL);
    
	return 0;
}
/* void sendfd(int sfd, int fd)
{
	struct msghdr mymsg;
	char buf1[] ="hello";
    struct iovec bufs[2];
	bufs[0].iov_base = buf1;
	bufs.iov_len = strlen(buf1);

}*/
