/*************************************************************************
	> File Name: ./include/my_msg.h
	> Author: Arwen
	> Mail:745529725@qq.com 
	> Created Time: Thu 19 Mar 2015 11:35:06 PM CST
 ************************************************************************/

#ifndef __MSG_H__
#define __MSG_H__
#define MAX_SIZE 1024
typedef struct msg_tag
{
	int msg_len ;
	char msg_buf[MAX_SIZE - sizeof(int)];
}MSG, *pMSG;
#endif

