/*************************************************************************
	> File Name: 1.c
	> Author: Arwen
	> Mail:745529725@qq.com 
	> Created Time: Mon 02 Feb 2015 10:06:48 PM CST
 ************************************************************************/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<unistd.h>
int main(int argc ,char* argv[ ])
{
	system("clear");
	execl("./2","8","5","4",NULL);
 // char* arglist[ ]={"./2","2","hello","whild",NULL};
//	int execl("./2","2","hello","whold",NULL);
//  execvp(arglist[ 0],arglist);
    printf("---------------------------------\n");
	return 0;
}
