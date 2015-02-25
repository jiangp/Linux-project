/*************************************************************************
	> File Name: server_file.c
	> Author: Arwen
	> Mail:745529725@qq.com 
	> Created Time: Mon 09 Feb 2015 03:20:15 PM CST
 ************************************************************************/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/socket.h>
#include<fcntl.h>
#include<sys/stat.h>
#include<netinet/in.h>
#include<arpa/inet.h>
#include<signal.h>
#define SER_IP "192.168.1.124"
#define SER_PORT 1234
int recv_buf(int sfd, char* buf,int len );
int send_buf(int sfd, char* buf,int len );
void child_main(int fd_client);
void child_handle(int signum)
{
   wait(NULL);

}

int main(int argc,char *argv[])
{
	int fd_listen;
	int fd_client;
	signal(17,child_handle);
	fd_listen = socket(AF_INET, SOCK_STREAM, 0);
	if(fd_listen == -1)
	{
		perror("error\n");
		close(fd_listen);
		exit(1);
	}
	struct sockaddr_in seraddr,clientaddr;
	socklen_t sock_len = sizeof(clientaddr);
	memset(&seraddr, 0 ,sizeof(seraddr));
    seraddr.sin_family = AF_INET ;
	seraddr.sin_port = htons(SER_PORT);
	seraddr.sin_addr.s_addr = inet_addr(SER_IP);

	if(-1 == bind(fd_listen, (struct sockaddr*)&seraddr, 16))
	{
		perror("bind!");
		close(fd_listen);
		exit(1);
	}

	if(-1 == listen(fd_listen, 5))
	{
		perror("listen");
		close(fd_listen);
		exit(1);
	}
	while(1)
	{
       sock_len = sizeof(clientaddr);
	   memset(&clientaddr , 0, sock_len);
	   fd_client = accept(fd_listen, (struct sockaddr*)&clientaddr, &sock_len);
	   printf("client %s:%d connect !\n",inet_ntoa(clientaddr.sin_addr),ntohs(clientaddr.sin_port));
	   if(fork() == 0)
	   {
		   close(fd_listen);
		   child_main(fd_client);
		   close(fd_client);
		   exit(1);
	   }
	   close(fd_client);
	}
	return 0;
}

int send_buf(int sfd, char* buf,int len )
{
	int send_sum = 0;
	int send_ret ;
	while(send_sum <len)
	{
		send_ret = send(sfd, buf + send_sum, len - send_sum, 0);
        send_sum += send_ret ;
	}
	return send_sum;
}
 
int recv_buf(int sfd, char* buf,int len )
{
	int recv_sum = 0;
	int recv_ret ;
	while(recv_sum <len)
	{
		recv_ret = recv(sfd, buf + recv_sum, len - recv_sum, 0);
        recv_sum += recv_ret ;
	}

	return recv_sum;
    
}
void child_main(int fd_client)
{
	int recv_len;
	int send_len;
	char file_name[128];
	char msg[1024];
	memset(file_name, 0, 128);
	recv_buf(fd_client, (char*)&send_len, 4);
	printf("%d\n",send_len);
//	recv(fd_client, file_name, send_len, 0) ;
   	recv_buf(fd_client, file_name, send_len);
	printf("file_name: %s\n",file_name);
	int fd_file = open(file_name,O_RDONLY);
	if(fd_file == -1)
	{
      memset(msg, 0 ,1024);
	  strcpy(msg, "error");
	  send_len = strlen(msg);
	  send_buf(fd_client, (char*)&send_len, 4);
	  send_buf(fd_client, msg, send_len);
	  return ;
	}
	memset(msg, 0, 1024);
	strcpy(msg, "OK");
	send_buf(fd_client, (char*)&send_len, 4);
    send_buf(fd_client, msg, send_len);
	while(memset(msg, 0 ,1024),(send_len=read(fd_file,msg, 1024)) != 0)
	{
		send_buf(fd_client, (char*)&send_len, 4);
		send_buf(fd_client, msg, send_len);
	}
	send_len = 0;
	send_buf(fd_client, (char*)&send_len, 4);
}
