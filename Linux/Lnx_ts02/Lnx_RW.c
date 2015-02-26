/*************************************************************************
	> File Name: 012702.c
	> Author: Arwen
	> Mail:745529725@qq.com 
	> Created Time: Tue 27 Jan 2015 10:59:04 AM CST
 ************************************************************************/

#include<stdio.h>
#include<stdlib.h>
#include<sys/stat.h>
#include<sys/types.h>
#include<fcntl.h>
#include<unistd.h>
#include<string.h>
int main()
{
	
		int ssze_t;
		char buf[1024]={'\0'};
    	int fp_in = open( "./1.c",O_RDONLY);
		int fp_wr =open("./2.c",O_WRONLY);
		if(fp_in ==-1)
		{
			printf("fail  open !\n");
			exit (1);
		}
		printf("OK !\n");
		ssze_t=read(fp_in ,buf,1024);
		printf("%d \n%s",ssze_t,buf);
    	write(fp_wr,buf,strlen(buf));
		close(fp_wr);
		close(fp_in);
	return 0;
}
