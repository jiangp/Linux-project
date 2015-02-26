/*************************************************************************
	> File Name: 2.c
	> Author: Arwen
	> Mail:745529725@qq.com 
	> Created Time: Mon 02 Feb 2015 11:17:15 PM CST
 ************************************************************************/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<unistd.h>
int main(int argc,char *argv[ ])
{
	int a =atoi(argv[ 0]);
	int b =atoi(argv[ 2]);

	printf("%d + %d = %d",a,b,a+b);

	return 0;
}

