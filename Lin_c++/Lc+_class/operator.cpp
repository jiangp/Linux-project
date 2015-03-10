/*************************************************************************
	> File Name: operator.cpp
	> Author: Arwen
	> Mail:745529725@qq.com 
	> Created Time: Tue 10 Mar 2015 07:26:38 PM CST
 ************************************************************************/

#include<iostream>

using std::cout;
using std::endl;

class a
{
	int val;
public:
	a(int a = 0) : val(a) {  }
	a &operator+=(const int &x)
	{
		val += x;
	}
	void print() const
	{
		cout << val;
	}
};

int main(void)
{
	a i(5);
	i.print();
	cout << endl;
	i += 6;
	i.print();
	cout << endl;

	return 0;
}
