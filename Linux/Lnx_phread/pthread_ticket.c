/*************************************************************************
	> File Name: pthread_ticket.c
	> Author: Arwen
	> Mail:745529725@qq.com 
	> Created Time: Fri 06 Feb 2015 05:03:43 PM CST
 ************************************************************************/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<unistd.h>
#include<pthread.h>
pthread_mutex_t mutex ;
pthread_cond_t cond_pro, cond_con ;
void* handle(void* arg)
{
	int* pt = (int*)arg ;
	int soldn = 0 ;
    int tmp ;
    while(1)
	{
		pthread_mutex_lock(&mutex);
		while(*pt == 0)
		{
			printf("no ticket!\n");
			pthread_cond_signal(&cond_pro);
			pthread_cond_wait(&cond_con,&mutex);
		}

		tmp = *pt ;
		tmp -- ;
		*pt = tmp ;
		soldn ++ ;
		printf("%u:sold a ticket,%d,  left :%d\n",pthread_self(),soldn,*pt);
		pthread_mutex_unlock(&mutex);
		sleep(1);
	}
	pthread_mutex_unlock(&mutex);
	pthread_exit((void*)soldn);

}
void* handle1(void* arg)
{
   int* pt = (int*)arg ;
   while(1)
   {
	   pthread_mutex_lock(&mutex);
	   while(*pt>0)
	   
		   pthread_cond_wait(&cond_pro, &mutex);

		   *pt = rand() % 20 +1;
		   printf("new tickets: %d\n",*pt);
		   pthread_mutex_unlock(&mutex);
		   pthread_cond_broadcast(&cond_con);
	   
   }
}
int main(int argc, char *argv[])
{
	int i,sum=0;
	int nthds = atoi(argv[1]);
	int ntickets = atoi(argv[2]);
	int total = ntickets;
	pthread_t thd_bak;
	pthread_mutex_init(&mutex,NULL);
	pthread_cond_init(&cond_pro,NULL);
	pthread_cond_init(&cond_con,NULL);
	pthread_t* thd_arr = (pthread_t*)calloc(nthds,sizeof(pthread_t));
	int* thd_tickets = (int*)calloc(nthds,sizeof(int));

	for(i = 0;i <nthds; i++ )
	{
		pthread_create( thd_arr +i, NULL, handle, (void*)&ntickets );
	}
    pthread_create(&thd_bak, NULL,handle1, (void*)&ntickets );
	for(i =0; i <nthds; i ++)
	{
		pthread_join(thd_arr[i],(void*)(thd_tickets + i));
	}

	for( i = 0; i < nthds; i ++)
	{
		sum += thd_tickets[i];
	}
	printf("sold: %d, total :%d ,current:%d\n",sum,total,ntickets);
	pthread_mutex_destroy(&mutex);
	pthread_cond_destroy(&cond_pro);
	pthread_cond_destroy(&cond_con);
}
