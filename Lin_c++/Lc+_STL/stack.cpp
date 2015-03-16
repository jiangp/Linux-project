/*************************************************************************
	> File Name: stack.cpp
	> Author: Arwen
	> Mail:745529725@qq.com 
	> Created Time: Mon 16 Mar 2015 03:29:37 PM CST
 ************************************************************************/

#include<iostream>
#include<stdio.h>
//using namespace std;
#include<stack>
#include<string>
int main()
{
	int i = 0;
	std::stack<int> st;
	for(int index = 0; index != 10; ++index)
	{
		st.push(index);
		std::cout << st.top() <<"have in stack" <<std::endl;
	}
	std::cout << "the size " << st.size()<< std::endl;
	for(int index = 0; index !=  10; ++index)
	{
		std::cout << st.top() << "out" <<std::endl;
		st.pop();
	}
	std::cout << "the size " << st.size() << std::endl;

	return 0;
}
