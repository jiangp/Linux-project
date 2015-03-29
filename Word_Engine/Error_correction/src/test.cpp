/*************************************************************************
	> File Name: ../test.cpp
	> Author: Arwen
	> Mail:745529725@qq.com 
	> Created Time: Sun 29 Mar 2015 09:09:42 PM CST
 ************************************************************************/

#include"MyConf.h"
int main(int argc, char**argv)
{
	MyConf a(argv[1]);
	a.save_to_vector();
	return 0;
}

