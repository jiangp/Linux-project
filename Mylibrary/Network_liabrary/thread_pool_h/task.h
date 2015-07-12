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
#include"myconf.h"
#include"result.h"
#include"compare.h"
#include"cache.h"
//#include"redis.h"
using namespace std;



class Task 
{
public:
	Task(const std::string &msg, int sockfd, MyConf &conf, Cache &cache);

	size_t edit(const string &pstr1, size_t len1, const string &pstr2, size_t len2);
	void execute();
	void get_result(Result &rst);
    void find_word_from_map();
	void satistic(const set<int> *m_set);
	void send_msg();
private:
	const std::string m_msg;
	int m_sockfd;
	vector<pair<string, string> > *m_ve;
	map<string, set<int> > *m_idx;
	priority_queue<Result, vector<Result>, Compare> m_result;
	map<string, string> *m_ca;
	//Redis *r;
};

#endif
