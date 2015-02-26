/*************************************************************************
	> File Name: client_udp.c
	> Author: Arwen
	> Mail:745529725@qq.com 
	> Created Time: Tue 24 Feb 2015 03:51:13 PM CST
 ************************************************************************/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<sys/types.h>
#include<sys/socket.h>
#include<netinet/in.h>
#include<unistd.h>
#include<fcntl.h>
#include<sys/stat.h>
#include<arpa/inet.h>
#define ser_IP "192.168.1.124"
#define ser_PORT 1234
int main(int argc, char *argv[])
{
	int fd_client = socket(AF_INET, SOCK_STREAM, 0);
	if(-1 == fd_client)
	{
		perror("socket\n");
		close(fd_client);
		exit(1);
	}
	struct sockaddr_in clientaddr;
	bzero(&clientaddr,sizeof(clientaddr));
	clientaddr.sin_family = AF_INET;
	clientaddr.sin_port = htons(ser_PORT);
	clientaddr.sin_addr.s_addr = inet_addr(ser_IP);

    sendto(fd_client, "hello", 10, 0, (struct sockaddr*)&clientaddr,sizeof(struct sockaddr));
	printf("1111111111\n");
	char buf[1024] = {0};
	struct sockaddr_in fromaddr;
	bzero(&fromaddr, sizeof(fromaddr));
	int fromaddr_len = sizeof(fromaddr);
    if(-1 == recvfrom(fd_client, buf, sizeof(buf),0,(struct sockaddr*)&fromaddr,&fromaddr_len))
	 {
			perror("recvfrom\n");
			close(fd_client);
			exit(1);
	}
	printf("receive from %s %d,the message is %s \n",inet_ntoa(fromaddr.sin_addr),ntohs(fromaddr.sin_port),buf);

	close(fd_client);	
	return 0;
}
