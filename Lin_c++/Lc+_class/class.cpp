/*************************************************************************
	> File Name: class.cpp
	> Author: Arwen
	> Mail:745529725@qq.com 
	> Created Time: Fri 06 Mar 2015 02:53:31 PM CST
 ************************************************************************/
#include"class.h"
#include<iostream>
//using namespace std;
#include<string>
 

person::person(int id , std::string &name, int age)
    :m_id(id),m_name(name),m_age(age)
{

}
void person::print()
{
	std::cout << "name = :"<<m_name<<std::endl;
	std::cout << "id   = :"<<m_id<<std::endl;
	std::cout << "age  = :"<<m_age<<std::endl;
}
void person::print() const
{

	std::cout << "name = :"<<m_name<<std::endl;
	std::cout << "id   = :"<<m_id<<std::endl;
	std::cout << "age  = :"<<m_age<<std::endl;
}
void person::setname(std::string &name)
{
	m_name = name ;
}
void person::setid(int id)
{
	m_id = id ;
}
void person::setage(int age)
{
	m_age = age ;
}

/*
int main()
{
	person s1;
	std::string name ="lilei";
	s1.setname(name);//  here
	s1.setage(21);
	s1.print();
//	const person *ps = &s1;
//    *ps->print();
	return 0;
}*/

int main()
{
	std::string name = "lilei";
	person s1(1, name, 23);//same above
	person s;
	s1.print();
	return 0;
}
