/*************************************************************************
	> File Name: my_system.c
	> Author: Arwen
	> Mail:745529725@qq.com 
	> Created Time: Mon 02 Feb 2015 04:22:59 PM CST
 ************************************************************************/

#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>

int main()
{
   system("clear");
   printf("uid :%d   gid :%d   euid :%d   egid :%d\n",getuid(),getgid(),geteuid(),getegid());
   printf("Parent process id:%d\n",getpid());

   pid_t iRet = fork();
   if(iRet == 0)
   {
	   system("ls -l");
   }
   else if(iRet > 0)
   {
      printf("parent process success  child id:%d\n",iRet);
   }else
   {
      printf("Create child process fail !\n");
   }
   printf("OK!\n");

 
   return 0;
}
