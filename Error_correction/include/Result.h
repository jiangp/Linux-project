/*************************************************************************
	> File Name: ./include/Result.h
	> Author: Arwen
	> Mail:745529725@qq.com 
	> Created Time: Wed 01 Apr 2015 05:02:34 PM CST
 ************************************************************************/
#ifndef _RESULT_H
#define _RESULT_H

#include<iostream>
class Result
{
	std::string m_word;         //单词

	std::string m_frequence; //词频
	int m_dist;                //编辑距离
public:
	Result(std::string word, std::string fre, int dist)
		:m_word(word), m_frequence(fre), m_dist(dist)
	{}
	std::string get_word()const            //取出接口
		{return m_word ; }
	int get_dist() const
	{return m_dist; }
	std::string get_frequence()const
	{return m_frequence; }
};

#endif


