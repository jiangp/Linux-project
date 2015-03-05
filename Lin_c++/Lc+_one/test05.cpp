/*************************************************************************
	> File Name: test05.cpp
	> Author: Arwen
	> Mail:745529725@qq.com 
	> Created Time: Thu 05 Mar 2015 02:10:39 PM CST
 ************************************************************************/

#include<iostream>
//using namespace std;
#include<string>
#include<sstream>
int main()
{
/*std::string s1 = " asd asdf";
	std::string s2 = "hello.world!";
	std::string s4= "E";
	std::string s3 = s1+s2;//merge（合并）
	std::string s5 = s4+s2;
	std::string s6 = s2.substr(0,5);//gut out 0~5 char
	std::string s7 = s2.substr(6,10);
	std::cout<<s6<<std::endl;
	std::cout<<s7<<std::endl;
//cout chars取词输出单个字符
	std::string::iterator it =s2.begin();
	for(; it != s2.end();it ++)//
	{
		std::cout<<*it<<std::endl;
	}*/
////////////////////////////////////////////////
	std::string s1;
//输入输出（空格换行）
	/*while(std::cin>>s1)
	{
		std::cout<< s1<<std::endl;
	}*/
//空格换行输出字符串
	while(getline(std::cin,s1))
	{
		std::istringstream iss(s1);
		while(iss>>s1)
		{
			std::cout<<s1<<std::endl;
		}
	}
//空格不换行   按行输出字符串
/*	while(getline(std::cin , s1))
	{
		std::cout<<s1<<std::endl;
	}*/

	return 0;
}
