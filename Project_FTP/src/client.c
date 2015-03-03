/*************************************************************************
  > File Name: client.c
  > Author: Arwen
  > Mail:745529725@qq.com 
  > Created Time: Fri 27 Feb 2015 10:43:15 AM CST
 ************************************************************************/

#include<stdio.h>
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<unistd.h>
#include<sys/socket.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<arpa/inet.h>
#include<netinet/in.h>
#include<sys/epoll.h>
#include<dirent.h>
#include<fcntl.h>
#define SER_IP "192.168.1.124"
#define SER_PORT 1234
#define ADDR "/home/arwen/project/Project_FTP/src"
#define MY_ASSERT(flag, msg) do{flag || (printf("%s\n",msg), exit(1), 0);}while(0)	
void client_gets(int fd_client);
void client_puts(int fd_client);
void client_remove(int fd_client);
int send_buf(int sfd, char* buf, int len);
int recv_buf(int sfd, char* buf, int len);
int main(int argc ,  char *argv[])
{
	int fd_client;
	char buf[1024];
	char line[128]= "0";
	char name[128]= "0";
	char stat;
	unsigned long size ;
	MY_ASSERT((fd_client = socket(AF_INET,SOCK_STREAM ,0))!=-1 ,"listen socket init");
	struct sockaddr_in cliaddr ,seraddr;
	memset(&seraddr, 0, sizeof(seraddr));
	memset(&cliaddr, 0, sizeof(cliaddr));
	cliaddr.sin_family = AF_INET;
	cliaddr.sin_port = htons(SER_PORT);
	cliaddr.sin_addr.s_addr = inet_addr(SER_IP);

	MY_ASSERT(connect(fd_client, (struct sockaddr*)&cliaddr,sizeof(cliaddr)) ==0,"connect");
	while(1)
	{
		memset(buf ,0 , 1024);
		fgets(buf ,1024, stdin);
		send(fd_client, buf, 1024, 0);
		if(strncmp(buf,"ls",2)==0)//ls
		{
			system("clear\n");
			while(memset(buf,0 ,sizeof(buf)),recv(fd_client, buf, sizeof(buf),0)!=-1)
			{
				if(strncmp(buf,"OK",2)!=0)
				{
					sscanf(buf, "%s %c %lu",name,&stat,&size);
					if(stat & DT_DIR)
						printf("    \033[34m%-10s\033[0m -------- %lu b\n",name,size);
					else
						printf("    %-10s -------- %lu b\n",name,size);
				}else{
					break;
				}
			}
		}
		else if(strncmp(buf,"cd",2)==0)//cd
		{
			printf("cd\n");
		}else if(strncmp(buf,"pwd",3)==0)//pwd
		{

			recv(fd_client, line, sizeof(line), 0);
			printf("%s\n",line);
		}else if(strncmp(buf,"gets",4)==0)//gets
		{
			client_gets(fd_client);
		}else if(strncmp(buf,"puts",4)==0)
		{
            client_puts(fd_client);
		}else if(strncmp(buf,"remove",6)==0)
		{
			
			client_remove(fd_client);
		}else
		{
			printf("error command!\n");
		}
	}
	return 0;
}
//client_remove
void client_remove(int fd_client)
{
	int send_len ;
	char file_name[128] = "0";
	printf("please input dele file_name:\n");
	fflush(stdin);
	fgets(file_name, 128, stdin);

    send_len = strlen(file_name);
	send_buf(fd_client, (char*)&send_len, 4);
	send_buf(fd_client, file_name, send_len);

	printf("remove over!\n");
	send_len = 0;
	send_buf(fd_client,(char*)&send_len,4);
}
//client_gets
void client_gets(int fd_client)
{
	int recv_len ;
	int send_len ;
	char name[128]="0";
	char msg[1024];
	char down_file[128]="0";
	memset(&name, 0 ,128);
	printf("please input the down filed:\n");
	fflush(stdin);
	fgets(msg ,128, stdin);
	send_len = strlen(msg);
	send_buf(fd_client,(char*)&send_len,4);
	send_buf(fd_client, msg, send_len);
	printf("pleace call in down_file:\n");
	fflush(stdin);
    fgets(down_file,128 , stdin);
	int fd_file = open (down_file,O_WRONLY | O_CREAT,0666);
	if(fd_file == -1)
	{
		perror("open\n");
		exit(1);
	}
	int recv_sum = 0 ;
	while(1)
	{
		memset(msg, 0 , 1024);
		recv_buf(fd_client, (char*)&recv_len, 4);
		if(recv_len == 0)
		{
			close(fd_file);
			break;
		}
		recv_sum += recv_buf(fd_client, msg, recv_len);
		write(fd_file, msg, recv_len );
		system("clear");
		printf("downloading...%.2fkbs\n",(double)recv_sum /1024);
	}
	printf("recv complient!\n");

}
//client_puts
void client_puts(int fd_client)
{
	int send_len ;
	char name[128] = "0";
	char msg[1024] = "0";
	char file_name[128] = "0";
	memset(&name, 0 ,128);
	printf("please input the up file;\n");
	fflush(stdin);
	fgets(file_name, 128, stdin);
    send_len = strlen(file_name);
	send_buf(fd_client, (char*)&send_len, 4);
	send_buf(fd_client, file_name, send_len);
	sprintf(name,"%s/%s",ADDR,file_name);
	name[strlen(name) - 1] = '\0';
	int fd_file = open(name,O_RDONLY);
	if(fd_file == -1)
	{
		perror("fd_file\n");
		exit(1);
	}
	while(memset(&msg,0,1024), (send_len = read(fd_file, msg, 1024) )!= 0)
	{
		if(send_len ==-1)
		{
			perror("read\n");
			exit(1);
		}
	
		send_buf(fd_client, (char*)&send_len,4);
		send_buf(fd_client,msg,send_len);
	}
	send_len = 0;
	send_buf(fd_client, (char*)&send_len,4);


}



int send_buf(int sfd, char* buf, int len)
{
	int send_sum = 0;
	int send_ret ;
	while(send_sum<len)
	{
		send_ret = send(sfd, buf + send_sum, len - send_sum, 0);
		send_sum += send_ret ;
	}
	return send_sum;
}
int recv_buf(int sfd, char* buf, int len)
{
	int recv_sum = 0;
	int recv_ret ;
	while(recv_sum<len)
	{
		recv_ret = recv(sfd, buf + recv_sum, len - recv_sum, 0);
		recv_sum += recv_ret ;
	}
	return recv_sum;
}


