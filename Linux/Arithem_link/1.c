/*************************************************************************
	> File Name: 1.c
	> Author: Arwen
	> Mail:745529725@qq.com 
	> Created Time: Sun 01 Mar 2015 08:26:35 PM CST
 ************************************************************************/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int main()
{
	char buf[10]= "hello";
	char msg[10] ;
	msg[10] =buf;
	printf("%s\n", msg);
	return 0;
}
