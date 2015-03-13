/*************************************************************************
	> File Name: deque.cpp
	> Author: Arwen
	> Mail:745529725@qq.com 
	> Created Time: Thu 12 Mar 2015 09:53:36 PM CST
 ************************************************************************/

#include<iostream>
//using namespace std;
#include<deque>
int main()
{
	std::deque<std::string> de_str;
	de_str.push_back("hello0");
	de_str.push_back("hello1");
	de_str.push_back("hello2");
	de_str.push_back("hello3");
	de_str.push_back("hello4");
	de_str.push_back("hello5");
	de_str.push_back("hello6");
	de_str.push_back("hello7");
	de_str.push_back("hello8");

	std::deque<std::string>::iterator ix = de_str.begin(); 
	for(;ix != de_str.end() ; ++ix)
	{
		std::cout << (*ix) << " ";
	}
	std::cout << std::endl;
	de_str.pop_back();//delete last one
	de_str.pop_front();//delete first one
	de_str.push_front("word!");//add first one 
	std::deque<std::string>::iterator iw= de_str.begin(); 
	for(;iw != de_str.end() ; ++iw)
	{
		std::cout << (*iw) << " ";
	}
	std::cout << std::endl;
	std::cout << "first one is : "<< de_str.front() <<std::endl;
	std::cout << "last  one is : "<< de_str.back() <<std::endl;
	std::deque<std::string>::iterator ie = de_str.end();
	for(; ie != de_str.begin() ; --ie)
	{
		if(*ie =="hello2")
			de_str.insert(ie ,"sdad");//add
		else if(*ie == "hello5")//delete
			de_str.erase(ie);
		std::cout << (*ie) << " ";
	}
	de_str.clear();
	std::cout << std::endl;
	return 0;
}
