/*************************************************************************
	> File Name: myconf.h
	> Author: Arwen
	> Mail:745529725@qq.com 
	> Created Time: Sun 29 Mar 2015 03:09:47 PM CST
 ************************************************************************/


#ifndef _MYCONF_H
#define _NYCONF_H


#include<iostream>
#include<string>
#include<map>
#include<vector>
#include<set>
#include<fstream>
#include<sstream>
#include"noncopyable.h"


using namespace std;

class MyConf : private Noncopyable      //配置文件类
{
	map<string, string> m_map;            //保存配置文件
	vector<pair<string, string> > m_vec;    //用于保存单词 和词频
	map<string, set<int> > m_index;                  //保存字母与 在vector中的下标
	ifstream ifs;
	
public:
	MyConf(const string &name);
	void index_to_map();					//存入 map
	void save_to_vector();					//度入 vector
	map<string, string> &get_map();
	string get_IP();
	int get_PORT();
	vector<pair<string, string>> *get_vec() { return &m_vec;}
	map<string, set<int> > *get_index() {return &m_index; }
};
#endif
