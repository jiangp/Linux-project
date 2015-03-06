/*************************************************************************
	> File Name: 1.cpp
	> Author: Arwen
	> Mail:745529725@qq.com 
	> Created Time: Fri 06 Mar 2015 10:20:04 PM CST
 ************************************************************************/

#include<iostream>
//using namespace std;
int main()
{
	int i = 1024;
	int *pi =&i;
	int **ppi = &pi;
	std::cout << "i = " <<i
		<< "*pi = " <<*pi
		<< " **ppi = " <<**ppi<<std::endl;
	//int ia3[] =ivec;
	return 0;
}
