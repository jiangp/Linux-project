/*************************************************************************
	> File Name: my_shm2.c
	> Author: Arwen
	> Mail:745529725@qq.com 
	> Created Time: Wed 04 Feb 2015 09:45:22 AM CST
 ************************************************************************/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/ipc.h>
#include<sys/shm.h>
int main(int argc ,char *argv[ ])
{
	key_t my_key;
	int my_shm;
	char *pstr;
	my_key=ftok("./my_shm1.c",123);
    my_shm = shmget(my_key,1024,0666);
	if(my_shm == -1)
	{
		perror("shmget");
		exit(1);
	}
   pstr =	(char*)shmat(my_shm,NULL,0);
   puts(pstr);
   memset(pstr,0,1024);
   strcpy(pstr,"hellossssssssssssssssd!\n");
   sleep(30);
   shmctl(my_shm,IPC_RMID,NULL);



	return 0;
}
