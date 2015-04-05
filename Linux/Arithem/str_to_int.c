/*************************************************************************
	> File Name: str_to_int.c
	> Author: Arwen
	> Mail:745529725@qq.com 
	> Created Time: Thu 02 Apr 2015 10:41:11 PM CST
 ************************************************************************/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int str_to_int(char *str)
{
	if(str == NULL)
	{
		perror("str is NULL");
		exit(1);
	}
	int num = 0;
	int flag = 0;
	char* p = str;
	if((*p) == '-')
	{
		p++;
		flag = 1;
	}else if((*p) == '+')
		p++;

	while( *p != '\0')
	{
		if(*p >'0' && *p <='9')
		{
			num =num*10 + (*p - '0');
			if(num > 0x7fffffff)
				exit(1);
			p++;
		}
	}
	if(flag)
		num = 0 - num;
	return num;
}
int main()
{
	char str[] = "-23456";
	int a = str_to_int(str);
	printf("%d",a);
	return 0;
}
