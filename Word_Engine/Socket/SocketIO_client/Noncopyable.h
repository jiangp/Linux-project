/*************************************************************************
	> File Name: Noncopyable.h
	> Author: Arwen
	> Mail:745529725@qq.com 
	> Created Time: Tue 24 Mar 2015 05:38:37 PM CST
 ***********************************************************************/
#ifndef _NONCOPYABLE_H
#define _NONCOPYABLE_H

#include<iostream>
class Noncopyable
{
protected:
	Noncopyable(){}
	~Noncopyable(){}
private:
	Noncopyable(const Noncopyable &);
	void operator=(const Noncopyable &);
};

#endif
