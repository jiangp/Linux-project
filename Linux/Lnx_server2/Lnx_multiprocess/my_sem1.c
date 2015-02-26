/*************************************************************************
	> File Name: my_sem1.c
	> Author: Arwen
	> Mail:745529725@qq.com 
	> Created Time: Wed 04 Feb 2015 11:16:17 AM CST
 ************************************************************************/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<unistd.h>
#include<sys/types.h>
#include<fcntl.h>
#include<sys/stat.h>
#include<sys/ipc.h>
#include<sys/shm.h>
#include<sys/sem.h>
#define PATH "/home/arwen/yawen/pipe"
#define SERVER "server.fifo"
typedef struct tag
{
	int m_flag;
	char m_buf[ 1024];
}MBUF,*pMBUF;
void P(int semid);
void V(int semid);
int main(int argc,char *argv[ ])
{
	char server_name[128]="" ;
	char read_file[128], write_file[128] ;
	char msg[32]= "" ;
	int fd_r, fd_w ;
	sprintf(server_name, "%s/%s", PATH, SERVER);
	int fd_server = open(server_name, O_WRONLY);
						
	memset(read_file, 0, 128);
	memset(write_file, 0, 128);
								
	sprintf(read_file, "%s/%d_r.fifo", PATH, getpid());
	sprintf(write_file, "%s/%d_w.fifo", PATH, getpid());
										
	mkfifo(read_file, 0666);
	mkfifo(write_file, 0666);
												
	sprintf(msg, "%d\n", getpid());
	write(fd_server, msg, strlen(msg));
														
	fd_r=open(read_file, O_RDONLY);
	fd_w=open(write_file, O_WRONLY);
															
	key_t shm_key,sem_key;	
	int my_shm,my_sem;

	char line[ 1024];
	pMBUF p;
	shm_key=atoi(argv[ 1]);
	sem_key=atoi(argv[ 2]);

	my_shm = shmget(shm_key,sizeof(MBUF),0666|IPC_CREAT);

    my_sem = semget(sem_key,1,0666|IPC_CREAT);
    semctl(my_sem,0,SETVAL,1);
    
	p=(pMBUF)shmat(my_shm,NULL,0);
	memset(p,0,sizeof(MBUF));

	while(memset(line,0,1024),fgets(line,1024,stdin)!=NULL)
	{
		write(fd_w,line,strlen(line));
		memset(line ,0, 1024);
		read(fd_r,line,1204);
		while(P(my_sem),p->m_flag ==1)
		{
			V(my_sem);
			sleep(1);
		}
		strcpy(p->m_buf,line);
		p->m_flag =1;
		V(my_sem);

	}
	while(P(my_sem),p->m_flag ==1)
	{
		V(my_sem);
		sleep(1);
	}
	strcpy(p->m_buf,"over");
	p->m_flag =1;
	V(my_sem);
	sleep(3);

	shmdt(p);
	shmctl(my_shm,IPC_RMID,NULL);
	semctl(my_sem,0,IPC_RMID);
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
