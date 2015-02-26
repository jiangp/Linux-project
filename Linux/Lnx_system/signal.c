/*************************************************************************
	> File Name: signal.c
	> Author: Arwen
	> Mail:745529725@qq.com 
	> Created Time: Tue 03 Feb 2015 02:22:16 PM CST
 ************************************************************************/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<signal.h>
#include<unistd.h>
#include<sys/wait.h>
#include<sys/types.h>
void Signal(int is)
{
	printf("Capture signno :%d\n",is);
}

int main(int argc,char *argv[ ])
{

	
  //  signal(SIGINT,SignalL);//Ctrl c  xinghao
//    signal(SIGINT,SIG_IGN);//ignore signal
    signal(SIGINT,SIG_DFL);//on write singnal
	while(1)
	   sleep(3);
	return 0;
}
