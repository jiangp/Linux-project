/*************************************************************************
	> File Name: class.h
	> Author: Arwen
	> Mail:745529725@qq.com 
	> Created Time: Fri 06 Mar 2015 02:54:12 PM CST
 ************************************************************************/
#ifndef _STU_H
#define _STU_H
#include<iostream>
#include<string>
//using namespace std;
class person 
{
public:
	person(int id ,std::string &name, int age);
	person(){}
	void print();
	void print() const;
	void setname(std::string &name);
	void setid(int id);
	void setage(int age);
private:
	std::string m_name;
	int m_id;
	int m_age;
};
#endif
