/*************************************************************************
	> File Name: init_.cpp
	> Author: Arwen
	> Mail:745529725@qq.com 
	> Created Time: Sun 08 Mar 2015 11:44:44 PM CST
 ************************************************************************/

#include<iostream>
//using namespace std;
#include<string>
#include<vector>
int main()
{
	std::vector<std::string> svec(10);
	std::vector<std::string> *psvec1 = new std::vector<std::string>(10);
	//std::vector<std::string> **psvec2 =new std::vector<std::string>[10];
//	std::vector<std::string> *p1=pvec1;
	std::vector<std::string> *p = &svec;
	delete psvec1;
	return 0;
}
