/*************************************************************************
	> File Name: getpid.c
	> Author: Arwen
	> Mail:745529725@qq.com 
	> Created Time: Wed 28 Jan 2015 09:30:19 AM CST
 ************************************************************************/

#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
int main(int argc,char *argv[ ])
{
	printf("pid :%d   ppid :%d\n",getpid(),getppid());
	return 0;
}
