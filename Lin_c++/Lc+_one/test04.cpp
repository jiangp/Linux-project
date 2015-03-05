/*************************************************************************
	> File Name: test04.cpp
	> Author: Arwen
	> Mail:745529725@qq.com 
	> Created Time: Thu 05 Mar 2015 11:15:37 AM CST
 ************************************************************************/

#include<iostream>
//using namespace std;
/*
int add(int a, int b)
{
	return a + b ;
}
double add(double a, double b)
{
	return a + b ;
}
inline int max(int a, int b)
{
	return a >b ? a : b ;
}*/
inline int add(int a,int b = 3)
{
	return a+b;
}
int main()
{
	int *pval = new int ;
	std::cout<< "*pval =" <<*pval<<std::endl;
//	int *pval = new int [10];
//	delete *pval;
//	std::cout<<"add(3.3 +4.4) ="<< add(3.3,4.4)<<std::endl;
//	std::cout<< "add(3+4) =" << add(3,4)<<std::endl;
	std::cout<< " add(4+2) ="<<add(4)<<std::endl;
	return 0;
}
