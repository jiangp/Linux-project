/*************************************************************************
	> File Name: server.c
	> Author: Arwen
	> Mail:745529725@qq.com 
	> Created Time: Wed 04 Feb 2015 11:48:20 PM CST
 ************************************************************************/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<unistd.h>
#include<sys/stat.h>
#include<sys/types.h>
#include<fcntl.h>
#include<signal.h>
#define PATH "/home/arwen/yawen/pipe"
#define NAME "server.fifo"


void child_handle(int sig_num)
{
	printf("a child exit!\n");
	wait(NULL);
}
void reverse(char* str)
{
	int bg,end;
	char tmp;
	bg=0;
	end=strlen(str)-1;
	while(bg<end)
	{
		tmp=str[bg];
		str[bg]=str[end];
		str[end]=tmp;
		bg++;
		end--;
	}
}

void child_main(int fd_rd,int fd_wr)
{
	char buf[ 1024];
	while(memset(buf,0,1024),read(fd_rd,buf,1024)!=0)
	{
		reverse(buf);
		write(fd_wr,buf,strlen(buf));
	}
}

int main(int argc,char *argv[ ])
{

	signal(17,child_handle);
    char file_name[ 128] ="";
	char client_r[ 128],client_w[ 128];
	char line[ 32];
	int fd_read ,i;
	int client_id;
	int fd_cr,fd_cw;
	FILE* fp;



	sprintf(file_name,"%s/%s",PATH,NAME);//write fifo's name  and address
    i=	mkfifo(file_name,0666);//  set fifo(easy fail,carefull)
	if(i==0)//set cucccess return 0
	{
       printf("success!");
	}else if(i==-1)//set fail  return -1
	{
		printf("sorry you are foolish!");
	}
  


	fd_read = open(file_name,O_RDONLY);//open  fifo  for read
	open(file_name,O_WRONLY);//open fifo for write

	fp = fdopen(fd_read,"r");//get a had file descriptor   (offen use to pipe/fifo  and net communication channel func descriptor)
    printf("OK!\n");//test



	while(memset(line,0,32),fgets(line,32,fp)!=NULL)//"pid\n"read client_id from fifo
	{
		printf("OK@\n");
		sscanf(line,"%d",&client_id);// line wrint to client
		printf("client: %d request !\n",client_id);//out  client_id
		memset(client_r,0,128);
		memset(client_w,0,128);
		 
		sprintf(client_r,"%s/%d_r.fifo",PATH,client_id);

		sprintf(client_w,"%s/%d_w.fifo",PATH,client_id);

		fd_cw = open(client_r,O_WRONLY);
		fd_cr = open(client_w,O_RDONLY);
		if(fork()==0)
		{
			child_main(fd_cr,fd_cw);
			close(fd_cr);
			close(fd_cw);
			exit(1);
		}
		close(fd_cr);
		close(fd_cw);


	}

	memset(file_name,0,128);
	sprintf(file_name,"%s/%s",PATH,NAME);
	unlink(file_name);
	return 0;
}
