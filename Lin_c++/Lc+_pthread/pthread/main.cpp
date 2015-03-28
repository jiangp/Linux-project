/*************************************************************************
	> File Name: main.cpp
	> Author: Arwen
	> Mail:745529725@qq.com 
	> Created Time: Tue 24 Mar 2015 04:29:30 PM CST
 ************************************************************************/

#include"pthread_pool.h"

int main(int argc, char **argv)
{
	MyThread myth;	
	myth.start();
	myth.join();

	return 0;
}

