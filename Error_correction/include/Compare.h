/*************************************************************************
	> File Name: ./include/Compare.h
	> Author: Arwen
	> Mail:745529725@qq.com 
	> Created Time: Wed 01 Apr 2015 05:35:46 PM CST
 ************************************************************************/

#ifndef _COMP_H
#define _COMP_H

#include<string.h>
#include<stdio.h>
#include"Result.h"

class Compare //优先级队列 比较的类
{
public:
	bool operator()(const Result &left, const Result &right);
};

#endif
