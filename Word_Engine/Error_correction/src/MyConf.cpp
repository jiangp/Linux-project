/*************************************************************************
	> File Name: MyConf.cpp
	> Author: Arwen
	> Mail:745529725@qq.com 
	> Created Time: Sun 29 Mar 2015 03:22:40 PM CST
 ************************************************************************/

#include"MyConf.h"

using namespace std;

MyConf::MyConf(const string &name)
{
	ifs.open(name.c_str());
	string line;
	while(ifs >> line)
	{
		int pos = line.find('=');
		if(pos == string::npos)
			continue;
		else{
			m_map.insert(pair<string, string>(line.substr(0,pos),(line.substr(pos + 1))));
		}
	}

}


void MyConf::save_to_vector()
{
	ifstream ifs1 ;
	map<string, string>::iterator iter = m_map.begin();
	for(; iter != m_map.end(); ++iter)
	{
		if(iter->first == "word_dict_path")
		{
			ifs1.open(iter->second.c_str());
			string line;
			int num = 0;
			while(getline(ifs1, line))
			{
				int pos = line.find(' ');
				m_vec.push_back(pair<string, string>(line.substr(0,pos),(line.substr(pos + 1))));	
			}
			for(vector<pair<string, string> >::iterator it = m_vec.begin(); it != m_vec.end(); ++it)
			{
				cout << it->first << " " << it->second << endl;
			}
		}
	}
	ifs1.close();
}

void MyConf::index_to_map()
{
	vector<pair<string, string> >::iterator iter = m_vec.begin();
	string word;
	string::iterator it;
	for(; iter != m_vec.end(); ++iter)
	{
		word = iter->first;
		for(it =word.begin(); it !=word.end(); ++it)
		{
			++m_index((*it));
		}
	}
	for(map<string, set<> >::iterator ite = index.begin())

}


map<string, string> &MyConf::get_map()
{
	return m_map;
}
