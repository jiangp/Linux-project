/*************************************************************************
	> File Name: find.cpp
	> Author: Arwen
	> Mail:745529725@qq.com 
	> Created Time: Sat 14 Mar 2015 02:27:23 PM CST
 ************************************************************************/

#include<iostream>
//using namespace std;
#include<map>
int main()
{
	int a[] ={1,2,3,4,5,6};
	std::map<int ,int> word(a);
	std::map<int ,int>::iterator it= word.begin() ;
	for(; it != word.end(); ++it)
	{
		std::cout <<((*it).second) <<std::endl;
	}
	return 0;
}
