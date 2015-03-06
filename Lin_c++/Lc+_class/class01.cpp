/*************************************************************************
	> File Name: class01.cpp
	> Author: Arwen
	> Mail:745529725@qq.com 
	> Created Time: Fri 06 Mar 2015 04:01:25 PM CST
 ************************************************************************/
#include"class01.h"
#include<iostream>
//using namespace std;
#include<string>
person::person(int id, std::string &name, int age)
	:m_id(id),m_name(name),m_age(age)
{
}

void person::print()
{
	std::cout << "name : " <<m_name <<std::endl
	          << "id  : " <<m_id <<std::endl
       		  << "age : " <<m_age << std::endl;
}
void person::print() const
{
	std::cout << "name : " <<m_name <<std::endl
      		  << "id  : " <<m_id <<std::endl
		      << "age : " <<m_age << std::endl;
}
person &person::setid(int id)
{
	m_id = id ;
	return *this;
}
person &person::setname(std::string &name)
{
	m_name = name;
	return *this;
}
person &person::setage(int age)
{
	m_age = age ;
	return *this;
}

int main()
{
	std::string name = "lilei";
	{
		person s;
		s.setid(1).setname(name).setage(15);
		s.print();
	}
	std::string name = "zhangsan";

	while(1)
	{}
	return 0;
	
}

