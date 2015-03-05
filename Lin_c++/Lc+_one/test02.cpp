/*************************************************************************
	> File Name: test02.cpp
	> Author: Arwen
	> Mail:745529725@qq.com 
	> Created Time: Thu 05 Mar 2015 10:30:53 AM CST
 ************************************************************************/

#include<iostream>
//using namespace std;
int test0(void)
{
	int ival = static_cast<int>(3.14159);
	std::cout<<ival <<std::endl;
}
int main(void)
{
	const int ival = 10 ;
	int *pival = const_cast<int*>(&ival);
	*pival = 20 ;
	std::cout<< "*pival = "<<*pival <<std::endl;
	std::cout<< "ival = " <<ival<<std::endl;
	test0();
}
