/*************************************************************************
	> File Name: sv_hd.h
	> Author: Arwen
	> Mail:745529725@qq.com 
	> Created Time: Mon 02 Feb 2015 09:47:43 AM CST
 ************************************************************************/

#ifndef __SER_H_
#define __SER_H_
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<systypes.h>
#include<sys/atst.h>
#include<fcntl.h>
#include<unistd.h>
#include<sys/time.h>
#include<sys/select.h>
#define PINE_PATH "/home/arwen/program/Lnuix/Lnx_server/fifo"
#define PINE_NAME "server.fifo"
typedef struct tag
{
	int m_id;
	int m_send;
	int m_recv;
	struct tag *m_next;
}CLIENT,*pCLIENT;
void dispatch_msg(pCLIENT phead,char *msg);
#endif
