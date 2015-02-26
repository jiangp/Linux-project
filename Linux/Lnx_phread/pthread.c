/*************************************************************************
	> File Name: phread.c
	> Author: Arwen
	> Mail:745529725@qq.com 
	> Created Time: Thu 05 Feb 2015 03:40:28 PM CST
 ************************************************************************/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<pthread.h>
void *child_main(void* arg)
{
	int i=0;
	printf("hello i am child pthread:%d\n",pthread_self());
		while(i<5)
		{
			printf("modou !\n");
			sleep(2);
			i++;
		}
		pthread_exit((void*)1);
}

int main(int argc,char*argv[])
{
	int index,k=0;
	printf("I am the main :%d\n",pthread_self());
	pthread_t thid;
   index= pthread_create(&thid,NULL,child_main,NULL);
   if(index==0)
   {
	   printf("success!\n");
   }
	printf("the child main:%d\n",thid);
	pthread_join(thid,(void**)&k);
	printf("%d\n",k);
	return 0;
}
