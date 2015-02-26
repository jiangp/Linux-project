/*************************************************************************
	> File Name: ./src/1.c
	> Author: Arwen
	> Mail:745529725@qq.com 
	> Created Time: Mon 26 Jan 2015 08:32:49 PM CST
 ************************************************************************/

#include"c.h"
int main(int argc, char* argv[])
{
	int mon ;
	int year ;
	while(scanf("%d%d", &mon, &year) == 2)
	{
		system("clear");
		print_month(mon, year);
	}
	return 0 ;
}

