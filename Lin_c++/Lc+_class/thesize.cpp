/*************************************************************************
	> File Name: theSize.cpp
	> Author: Arwen
	> Mail:745529725@qq.com 
	> Created Time: Tue 10 Mar 2015 11:31:29 AM CST
 ************************************************************************/

#include<iostream>
//using namespace std;
class A
{
	bool a;
	int b;
	bool c;
};
class B
{
	int a;
	bool b;
	bool c;
};
int main()
{
	std::cout << sizeof(A) << std::endl;
	std::cout << sizeof(B) << std::endl;
	return 0;
}
