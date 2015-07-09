/*************************************************************************
	> File Name: thesize3.cpp
	> Author: Arwen
	> Mail:745529725@qq.com 
	> Created Time: Tue 10 Mar 2015 11:34:58 AM CST
 ************************************************************************/

#include<iostream>
//using namespace std;
class A{
	int a;
	static int b; //way static not use space 
};
class B
{
	int a;
	char b;

};
class C
{
	float a;
	char b;
};
class D
{
	float a;
	int b;
	char c;
};

class E
{
	double a ;
	float b;
	int c ;
	char d;
};
int main()
{
	std::cout << sizeof(A) <<std::endl;
	std::cout << sizeof(B) <<std::endl;
	std::cout << sizeof(C) <<std::endl;
	std::cout << sizeof(D) <<std::endl;
	std::cout << sizeof(E) <<std::endl;
	return 0;
}
