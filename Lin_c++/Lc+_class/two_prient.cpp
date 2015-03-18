/*************************************************************************
	> File Name: two_prient.cpp
	> Author: Arwen
	> Mail:745529725@qq.com 
	> Created Time: Wed 18 Mar 2015 04:57:19 PM CST
 ************************************************************************/

#include<iostream>
//using namespace std;
class A
{
public:
	void print()
	{
		std::cout << "this A" <<std::endl;
	}
};
class B
{
public:
	void print()
	{
		std::cout << "this B" <<std::endl;
	}
};
class C :public A, public B
{
public:
	void disp()
	{
		A::print();
	}
	void print()
	{
		if(false)
			A::print();
		else
			B::print();
	}
};
int main()
{
	C c;
	c.disp();
	c.A::print();//调用A 的输出
	c.print();//成员函数的覆盖
	return 0;
}
