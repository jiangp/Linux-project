/*************************************************************************
	> File Name: ./src/pol_handle.c
	> Author: Arwen
	> Mail:745529725@qq.com 
	> Created Time: Thu 19 Mar 2015 11:33:19 PM CST
 ************************************************************************/

#include"head.h"
void handle_request(int sockfd)
{
	MSG send_msg;
	memset(&send_msg, 0, sizeof(MSG));
	strcpy(send_msg.msg_buf, FILE_NAME);
	send_msg.msg_len = strlen(send_msg.msg_buf);

	send_n(sockfd, (char*)&send_msg, 4 + send_msg.msg_len);
	int fd_file = open(FILE_NAME, O_RDONLY);
	char buf[32];
	int readn;
	while(memset(&send_msg, 0, sizeof(MSG)), (send_msg.msg_len = read(fd_file, send_msg.msg_buf, sizeof(send_msg.msg_buf))) > 0)
	{
		send_n(sockfd, (char*)&send_msg, 4 + send_msg.msg_len);
	}
	send_n(sockfd, (char*)&send_msg, 4 + send_msg.msg_len);
	sleep(rand()%5 + 1);
	close(fd_file);
	close(sockfd);
}

