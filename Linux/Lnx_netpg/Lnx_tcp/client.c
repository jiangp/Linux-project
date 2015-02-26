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
#define SER_IP "192.168.1.124"
#define SER_PORT 1234
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
   char* p= "very good!\n";
   send(fd_client,p,strlen(p),0);
   //
   char recv_buf[1024];
   recv(fd_client,recv_buf,1024,0);

   printf("from server :%s\n",recv_buf);
   close(fd_client);

   return 0;

}
