/*************************************************************************
	> File Name: function.cpp
	> Author: Arwen
	> Mail:745529725@qq.com    8
	> Created Time: Sat 21 Mar 2015 10:47:56 AM CST
 ************************************************************************/

#include<iostream>
//using namespace std;
#include<functional>
struct Foo
{
	Foo(int num) :m_num(num)
	{}
	void print_add(int i) const
	{
		std::cout << m_num + i <<std::endl;
  	}
	int m_num;
};

void print_num(int i)
{
	std::cout << i << std::endl;
}

struct printnum
{
	void operator()(int i) const
	{
		std::cout << i <<std::endl;
	}
};

int main()
{
	std::function<void(int)> f = print_num;
	f(2);
	std::function<void(const Foo &, int)> f2 = &Foo::print_add;
	const Foo foo(12139);
//	f2(foo, 1);
	f = std::bind(&Foo::print_add, foo, std::placeholders::_1);//bind
	f(3);
	return 0;

}

