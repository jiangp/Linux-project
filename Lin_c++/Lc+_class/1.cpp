/*************************************************************************
	> File Name: 1.cpp
	> Author: Arwen
	> Mail:745529725@qq.com 
	> Created Time: Tue 10 Mar 2015 11:24:17 AM CST
 ************************************************************************/

#include<iostream>
//using namespace std;
class A
{
public:
	A(int n)
	{
		value = n;
	}
	A(const A &other)
	{
		value = other.value;
	}
	void print()
	{
		std::cout << " value = " <<value <<std::endl;
	}
private:
	int value;
};
int main()
{
	A a=10;
	A b=a;
	b.print();

	return 0;
}
