/*************************************************************************
	> File Name: test06.cpp
	> Author: Arwen
	> Mail:745529725@qq.com 
	> Created Time: Thu 05 Mar 2015 05:39:12 PM CST
 ************************************************************************/

#include<iostream>
#include<string>
//using namespace std;
int main()
{
/*	//////////////one
	int i;
	std::string s1 = "HelloWord!";
	for(i=0; i<10;++i)
	{
		if(s1[i]<=122 && s1[i]>=97)
		{
			s1[i] = s1[i] - 32;
		}else if(s1[i]<=90 && s1[i]>=65)
		{
			s1[i] = s1[i] + 32;
		}
	}
	std::cout<<s1<<std::endl;
	//////////////////// */
	//two

	std::string msg;
	std::string str;
	std::string s1 = "$";
	std::string s2 = "asd";
	while(std::cin>>str)
	{
		msg=msg+s1;
		msg+=str;
		if(str == s2)
			break;
	}
	std::cout<<msg<<std::endl;

	//
	return 0;
}

