/*************************************************************************
	> File Name: ./src/Compare.cpp
	> Author: Arwen
	> Mail:745529725@qq.com 
	> Created Time: Wed 01 Apr 2015 05:39:55 PM CST
 ************************************************************************/
#include"Compare.h"

bool Compare::operator()(const Result &left, const Result &right)
{
	if(left.get_dist() == right.get_dist())
		return left.get_frequence() < right.get_frequence();
	else
		return left.get_dist() > right.get_dist();

	
}
