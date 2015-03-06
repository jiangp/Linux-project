/*************************************************************************
	> File Name: struct.cpp
	> Author: Arwen
	> Mail:745529725@qq.com 
	> Created Time: Fri 06 Mar 2015 11:12:57 AM CST
 ************************************************************************/

#include<iostream>
//using namespace std;
#include<string>

/*
 //
struct Student
{
public:	
	int m_id;
	std::string m_name;
	int m_age;
	void print()
	{
		std::cout<<"number: "<<m_id<< "  "
			<<"name: "<<m_name<< "  "
			<<"age: "<<m_age<<"  "<<std::endl;
	}
};

int main()
{
	Student s1;
	s1.m_id = 1;
	s1.m_name = "sdfs";
	s1.m_age = 21;
	Student *ps1 = &s1;
	std::cout<< "id  :"<<ps1->m_id <<std::endl;
	std::cout<<"name :"<<ps1->m_name <<std::endl;
	std::cout<< "age :"<<ps1->m_age <<std::endl;
	s1.print();
	return 0;
}*/

class Persen
{
private:
	int m_id;
	std::string m_name;
	int m_age;
public:
	void print()
	{
		std::cout<<"number: "<<m_id<< "  "
	    		 <<"name: "<<m_name<< "  "
    			 <<"age: "<<m_age<<"  "<<std::endl;
	}
	void setid(int id)
	{
		m_id = id;
	}
	void setname(std::string &name)
	{
		m_name = name;
	}
	void setage(int age)
	{
		m_age = age;
	}
};
int main()
{

	Persen s;
	std::string name = "lilei";
	s.setname(name);
	s.setid(1);
	s.setage(21) ;
	s.print();
	return 0;
}
