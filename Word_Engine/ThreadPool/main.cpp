/*************************************************************************
	> File Name: main.cpp
	> Author: Arwen
	> Mail:745529725@qq.com 
	> Created Time: Tue 24 Mar 2015 04:29:30 PM CST
 ************************************************************************/

#include"Pool.h"
#include<time.h>
#include<stdio.h>
#include<errno.h>

int a = 0;
void nano_sleep(double val);

void foo()
{
	a++;
	printf("foo : %d\n", a);
}
int main(int argc, char **argv)
{
	Tiny::Pool pool(100, 4);
	pool.start();

	while(1)
	{
		pool.addTask(&foo);
		nano_sleep(0.5);
	}
	return 0;
}

void nano_sleep(double val)
{
	struct timespec tv;
	tv.tv_sec = val;
	tv.tv_nsec = (val - tv.tv_sec)* 1000 *1000 *100;
	int ret;
	do
	{
		ret = nanosleep(&tv, &tv);
	}while(ret == -1 && errno == EINTR);
}
