/*************************************************************************
	> File Name: pipe.c
	> Author: Arwen
	> Mail:745529725@qq.com 
	> Created Time: Tue 03 Feb 2015 03:48:04 PM CST
 ************************************************************************/
//parents and child communication
#include<stdio.h>
#include<string.h>
#include<unistd.h>
int main()
{
   int fds[ 2]={0};
   pipe(fds);
   char buf[ 1024]={'\0'};
   if(fork()==0)
   {
	   close(fds[ 1]);
	   if(read(fds[ 0],buf,sizeof(buf))>0)
		   puts(buf);
	   close(fds[ 0]);
	   exit(1);
   }else
   {
	   close(fds[ 0]);
	   write(fds[ 1],"hello",6);
	   waitpid(-1,NULL,0);
	   close(fds[ 1]);
	   exit(1);
   }
   return 0;
}

