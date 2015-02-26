/*************************************************************************
	> File Name: select_ser.c
	> Author: Arwen
	> Mail:745529725@qq.com 
	> Created Time: Thu 26 Feb 2015 09:29:09 AM CST
 ************************************************************************/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<sys/select.h>
#include<sys/time.h>
#include<sys/types.h>
#include<unistd.h>
#include<fcntl.h>
#include<sys/stat.h>
#define FILENAME1 "1.txt"
#define FILENAME2 "dir.c"
int main()
{
	char buf[1024] = {0};
	int fd1 = open(FILENAME1, O_RDWR);
	int fd2 = open(FILENAME2, O_RDWR);
	int fd3 = open(FILENAME1, O_RDWR);
	int fd4 = open(FILENAME2, O_RDWR);
    
	if((fd1 == -1)||(fd2 == -1)||(fd3 == -1)||(fd4 == -1))
    {
		perror("error");
		exit(1);
	}

	fd_set fdrd,fdwr;
	FD_ZERO(&fdrd);
	FD_ZERO(&fdwr);
	FD_SET(fd1, &fdrd);
    FD_SET(fd2, &fdrd);
	FD_SET(fd3, &fdwr);
	FD_SET(fd4, &fdwr);
	int max1 = fd1>fd2 ? fd1 : fd2;
	int max2 = fd3>fd4 ? fd3 : fd4;
	int max = max1>max2 ? max1 :max2;
	struct timeval tm;
    tm.tv_sec = 2;
	tm.tv_usec = 0;
    while(1)
    {
    	if(select(max+1, &fdrd, &fdwr, NULL, &tm)== -1)
		{
			perror("select");
			exit(1);
		}

		if(FD_ISSET(fd1, &fdrd))
		{
			read(fd1, buf, sizeof(buf)-1);
			puts(buf);
			sleep(1);
		}
		if(FD_ISSET(fd2, &fdrd))
		{
			read(fd2, buf, sizeof(buf)-1);
			puts(buf);
			sleep(1);
		}
		if(FD_ISSET(fd3, &fdwr))
		{
			write(fd3, buf,sizeof(buf)-1);
			sleep(1);
		}
		if(FD_ISSET(fd4, &fdwr))
		{
			write(fd4, buf, sizeof(buf)-1);
			sleep(1);
		}
		
    }
	close(fd1);
	close(fd2);
	close(fd3);
	close(fd4);

}
