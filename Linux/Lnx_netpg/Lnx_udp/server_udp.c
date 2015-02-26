/*************************************************************************
	> File Name: server_udp.c
	> Author: Arwen
	> Mail:745529725@qq.com 
	> Created Time: Tue 24 Feb 2015 02:44:12 PM CST
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
	int fd_listen = socket(AF_INET, SOCK_STREAM, 0);
	if(fd_listen == -1)
	{
		perror("socket!\n");
		close(fd_listen);
		exit(1);
	}
	struct sockaddr_in my_addr;
    memset(&my_addr, 0, sizeof(my_addr));
	my_addr.sin_family = AF_INET;
	my_addr.sin_port = htons(ser_PORT);
	my_addr.sin_addr.s_addr = inet_addr(ser_IP);

	if(-1 == bind(fd_listen, (struct sockaddr*)&my_addr, sizeof(my_addr)))
	{
	    perror("bind\n");
		close(fd_listen);
		exit(1);
	}
    char buf[512] = {0};
	while(1)
	{
		struct sockaddr_in clientaddr;
		memset(&clientaddr, 0, sizeof(clientaddr));
		int clientaddr_len = sizeof(struct sockaddr);
		printf("12\n");
        if(-1 == recvfrom(fd_listen, buf, sizeof(buf),0,(struct sockaddr*)&clientaddr,&clientaddr_len))
		{
			perror("recvfrom\n");
			close(fd_listen);
			exit(1);
		}
		printf("receive from %s %d,the message is :%s\n",inet_ntoa(clientaddr.sin_addr),ntohs(clientaddr.sin_port),buf);
		sendto(fd_listen, "success", 10, 0, (struct sockaddr*)&clientaddr, sizeof(struct sockaddr)  );
	}
	close(fd_listen);
	return 0;
}
