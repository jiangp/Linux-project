/*************************************************************************
	> File Name: ./src/handle.cpp
	> Author: Arwen
	> Mail:745529725@qq.com 
	> Created Time: Tue 31 Mar 2015 04:09:03 PM CST
 ************************************************************************/

#include"handle.h"

void func_handle(const char *buf, size_t cnt, int peerfd)
{
	std::cout << ">: " << buf << std::endl;
	write(peerfd, buf, cnt);
}

