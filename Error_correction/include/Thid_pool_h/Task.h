/*************************************************************************
	> File Name: Task.h
	> Author: Arwen
	> Mail:745529725@qq.com 
	> Created Time: Tue 31 Mar 2015 10:01:18 AM CST
 ************************************************************************/

#ifndef _TASK_H
#define _TASK_H

#include<string>
#include<iostream>
#include<map>
#include<vector>
#include<set>
#include<queue>
#include"MyConf.h"
#include"Result.h"
#include"Compare.h"


using namespace std;



class Task 
{
public:
	Task(const std::string &msg, int sockfd, MyConf &conf);

	void execute();
	int edit(const char *pstr1, int len1, const char *pstr2, int len2);
	void get_result(Result &rst);
	void satistic(int i);
	void send_msg();
private:
	const std::string m_msg;
	int m_sockfd;
	vector<pair<string, string> > *m_ve;
	map<char, set<int> > *m_idx;
	priority_queue<Result, vector<Result>, Compare> m_result;
};

#endif
