/*************************************************************************
	> File Name: pthread_mutex.c
	> Author: Arwen
	> Mail:745529725@qq.com 
	> Created Time: Thu 05 Feb 2015 03:40:28 PM CST
 ************************************************************************/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<pthread.h>
pthread_mutex_t lock;
int i=0;
void *child_main(void* arg)
{

    int cnt=10000;
	while(0<cnt)
		{
			pthread_mutex_lock(&lock);
			i++;
            pthread_mutex_unlock(&lock);
			cnt--;
		}
		pthread_exit(NULL);
}

int main(int argc,char* argv[])
{

   int cnt=10000;

   pthread_mutex_init(&lock,NULL);
	pthread_t thid,thid1;
    pthread_create(&thid,NULL,child_main,NULL);
   // pthread_create(&thid1,NULL,child_main,NULL);
	while(0<cnt)
		{
			i++;
			cnt--;
		}

  // sleep(2);
   // printf("%d\n",i);
	pthread_join(thid,NULL);
	pthread_join(thid1,NULL);
   pthread_mutex_destroy(&lock);
    printf("%d\n",i);

	return 0;
}
