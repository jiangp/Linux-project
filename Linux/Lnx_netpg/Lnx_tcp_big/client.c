/*************************************************************************
	> File Name: client.c
	> Author: Arwen
	> Mail:745529725@qq.com 
	> Created Time: Sun 08 Feb 2015 04:22:11 PM CST
 ************************************************************************/

#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/socket.h>
#include<sys/types.h>
#include<netinet/in.h>
#include<arpa/inet.h>
#define SER_IP "192.168.1.48"
#define SER_PORT 1234
#define SIZE 1024*400
int send_buf(int sfd, char* buf,int len);
int main(int argc,char* argv[])
{

   int fd_client = socket(AF_INET,SOCK_STREAM,0);
   struct sockaddr_in seraddr;
   memset(&seraddr,0,sizeof(seraddr));
   seraddr.sin_family = AF_INET;
   seraddr.sin_port = htons(SER_PORT);
   seraddr.sin_addr.s_addr = inet_addr(SER_IP);
   if(-1== connect(fd_client,(struct sockaddr*)&seraddr,sizeof(seraddr)))
   {
	   perror("connect!");
	   exit(1);
   }
   //send
   char *buf[1024];
   memset(buf,0,1024);
   
   int* parr = (int* )calloc(SIZE,sizeof(int));
   send(fd_client,"SIZE",16,0);
 
   send_buf(fd_client,(char*)parr,SIZE);
   //recv
 

   recv(fd_client,buf,20,0);
   printf("from server :%s\n",buf);
   close(fd_client);

   return 0;

}



int send_buf(int sfd, char* buf,int len)
{
	int send_sum = 0;
	int send_ret;
	int send_cnt =0;
	while(send_sum < len)
	{
       send_ret = send(sfd,buf+send_sum,len- send_sum , 0 );
	   send_cnt++;

	   send_sum+=send_ret;
	}
	printf("send_cnt :%d\n",send_cnt);
	return send_sum;
}
