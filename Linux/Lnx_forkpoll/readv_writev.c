/*************************************************************************
	> File Name: readv_writev.c
	> Author: Arwen
	> Mail:745529725@qq.com 
	> Created Time: Sat 28 Feb 2015 10:48:26 AM CST
 ************************************************************************/

#include<stdio.h>
#include<sys/stat.h>
#include<sys/types.h>
#include<fcntl.h>
#include<unistd.h>
#include<stdlib.h>
#include<string.h>
#include<sys/uio.h>
int main()
{
	int fd =open("1.txt", O_RDONLY);
	//int fd2 = open ("2.txt",O_WRONLY |O_CREAT);
	char buf1[10] = "0",buf2[10]= "0";
	struct iovec bufs[2];
	bufs[0].iov_base = buf1;
	bufs[0].iov_len = 7 ;
	bufs[1].iov_base =buf2;
	bufs[1].iov_len = 5;
	readv(fd, bufs, 2);
	printf("buf1 :%s  buf2 :%s\n",buf1,buf2);
	//struct iovec bufw[2];
//	bufw[0].iov_base =buf1;
//	bufw[0].iov_len = 7;
//	bufw[1].iov_base = buf2;
  //  bufw[1].iov_len = 5;
   // writev(fd2, bufw,2);
//	printf("buf1 :%s  buf2 :%s\n",buf1,buf2);


	return 0;
}
