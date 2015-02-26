/*************************************************************************
	> File Name: fork.c
	> Author: Arwen
	> Mail:745529725@qq.com 
	> Created Time: Tue 03 Feb 2015 10:20:09 AM CST
 ************************************************************************/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<unistd.h>
int main (int argc ,char *argv[ ])
{
	pid_t pid;
	int a ;
	FILE* fp = fopen("my_system.c","r");

	if( (pid=fork() ) ==0 )
	{
		char line[ 1024];
		fgets(line,1024,fp);
		printf("child :%s\n",line);
//		while(1);
	}else if(pid > 0)
	{
//		while(1);
        if (fork() ==0)
		{
			printf("child %d\n",getpid());
		}
		sleep(10);
        pid_t pid;
		int ret;
		pid = wait(&ret);
		printf("child %d   %04x\n",pid ,ret);
		while(1);
	}
}
