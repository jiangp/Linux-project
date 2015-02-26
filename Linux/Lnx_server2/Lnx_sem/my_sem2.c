/*************************************************************************
	> File Name: my_sem2.c
	> Author: Arwen
	> Mail:745529725@qq.com 
	> Created Time: Wed 04 Feb 2015 11:16:17 AM CST
 ************************************************************************/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/ipc.h>
#include<sys/shm.h>
#include<sys/sem.h>
typedef struct tag
{
	int m_flag;
	char m_buf[ 1024];
}MBUF,*pMBUF;
void P(int semid);
void V(int semid);
int main(int argc,char *argv[ ])
{
	key_t shm_key,sem_key;
	
	int my_shm,my_sem;
	char line[ 1024];
	pMBUF p;
	shm_key=atoi(argv[ 1]);
	sem_key=atoi(argv[ 2]);

	my_shm = shmget(shm_key,sizeof(MBUF),0666);
    my_sem = semget(sem_key,1,0666);
    semctl(my_sem,0,SETVAL,1);
    
	p=(pMBUF)shmat(my_shm,NULL,0);
	memset(p,0,sizeof(MBUF));
	while(1)
	{
		while(P(my_sem),p->m_flag ==0)
		{
			V(my_sem);
			sleep(1);
		}
	   printf("%d :%s\n",getpid(),p->m_buf);
       
	   if(strcmp(p->m_buf,"over")==0)
    	 {
	    	printf("OK!");
        	V(my_sem);
            break;
      	 }

	     printf("OK2222!");
		 p->m_flag =0;
		 V(my_sem);
	}
	shmdt(p);
	return 0;
}
void P(int semid)
{
	struct sembuf my_buf;
	memset(&my_buf,0,sizeof(my_buf));
	my_buf.sem_num= 0;
	my_buf.sem_op= -1;
	my_buf.sem_flg = SEM_UNDO;
	semop(semid,&my_buf,1);
}
void V(int semid)
{
	struct sembuf my_buf;
	memset(&my_buf,0,sizeof(my_buf));
	my_buf.sem_num= 0;
	my_buf.sem_op= 1;
	my_buf.sem_flg = SEM_UNDO;
	semop(semid,&my_buf,1);

}
