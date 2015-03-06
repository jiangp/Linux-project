/*************************************************************************
	> File Name: class01.h
	> Author: Arwen
	> Mail:745529725@qq.com 
	> Created Time: Fri 06 Mar 2015 04:02:29 PM CST
 ************************************************************************/
#ifndef _STU_H
#define _STU_H

#include<string>
#include<iostream>
//using namespace std;
class person
{
public:
	person(int id, std::string &name, int age);
	person(){
		std::cout << "student construct " <<std::endl;
	}
	~person(){
		std::cout << "student destroy " <<std::endl;
	}
	void print();
	void print() const;
	person &setid(int id);
	person &setname(std::string &name);
	person &setage(int age);
private:
	int m_id;
	std::string m_name;
	int m_age;

};
#endif
