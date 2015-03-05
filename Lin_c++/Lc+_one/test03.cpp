/*************************************************************************
	> File Name: test03.cpp
	> Author: Arwen
	> Mail:745529725@qq.com 
	> Created Time: Thu 05 Mar 2015 11:03:55 AM CST
 ************************************************************************/

#include<iostream>
//using namespace std;
int a[]={0,1,2,3,4,5,6,7,8};
int  & func(int index)
{
	return a[index];
}
int main()
{
	bool bval;
	bval = 100;
	std::cout <<"bval = "<<bval<<std::endl;
	std::cout <<sizeof(bool) <<std::endl;
	func(3) = 100;
	std::cout<< a[3]<<std::endl;
	return 0;
}
