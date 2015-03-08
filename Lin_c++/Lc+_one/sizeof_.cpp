/*************************************************************************
	> File Name: sizeof_.cpp
	> Author: Arwen
	> Mail:745529725@qq.com 
	> Created Time: Sun 08 Mar 2015 11:10:43 PM CST
 ************************************************************************/

#include<iostream>
//using namespace std;
#include<string>
int main()
{
	int i,j,k,l;
	i = sizeof(wchar_t);
	j = sizeof(short);
	k = sizeof(long double);
	l = sizeof(long);
	std::cout << i << j << k << l << std::endl;
	return 0;
}
