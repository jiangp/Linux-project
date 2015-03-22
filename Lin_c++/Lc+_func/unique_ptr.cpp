/*************************************************************************
	> File Name: unique_ptr.cpp
	> Author: Arwen
	> Mail:745529725@qq.com 
	> Created Time: Tue 17 Mar 2015 03:20:19 PM CST
 ************************************************************************/

#include<iostream>
//using namespace std;
#include<memory>
//	std::unique_ptr<int> GetVal(){
//		std::unique_ptr<int> up(new int(88));
//		return up;
//	}
int main()
{
	std::unique_ptr<int> ap(new int(77));
	std::cout << "*ap = " << (*ap) << std::endl;
	std::unique_ptr<int> uPtr2 = std::move(ap);
//	int a = 3;
	std::cout << "*uPtr2 = " << (*uPtr2) <<std::cout;
//	std::unique_ptr<int>uPtr = GetVal();
	return 0;
}
