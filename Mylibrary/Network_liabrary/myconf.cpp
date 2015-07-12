/*************************************************************************
	> File Name: myconf.cpp
	> Author: Arwen
	> Mail:745529725@qq.com 
	> Created Time: Sun 29 Mar 2015 03:22:40 PM CST
 ************************************************************************/

#include"myconf.h"
#include<stdlib.h>

using namespace std;
/*
 * init the MyConf
 * and read the conf file  save int m_map
 * */
MyConf::MyConf(const string &name)
{
	ifs.open(name.c_str());
	string line;
	while(ifs >> line){
		unsigned int pos = line.find('=');
		
		if(pos == string::npos)
			continue;
		else{
			m_map.insert(pair<string, string>(line.substr(0,pos),(line.substr(pos + 1))));
		}
	}

}


/* 
 * read the addr of word_dict_path
 * open the file who is save word
 * and save into vector
 * */
void MyConf::save_to_vector()
{
	ifstream ifs1 ;
	ifstream ifs2 ;
	map<string, string>::iterator iter = m_map.begin();
	
	for(; iter != m_map.end(); ++iter){
		string line;
	
		/*read the English*/
		if(iter->first == "word_dict_path"){
			ifs1.open(iter->second.c_str());
			
			while(getline(ifs1, line)){
				int pos = line.find(' ');
				m_vec.push_back(pair<string, string>\
						(line.substr(0,pos),(line.substr(pos + 1))));	
			}
		}
		
		/*read the chinese*/
		if(iter ->first == "china_word_dict_path"){
			ifs2.open(iter->second.c_str());
			
			while(getline(ifs2, line)){

				int pos = line.find(' ');
				m_vec.push_back(pair<string, string>\
						(line.substr(0,pos),(line.substr(pos + 1))));	
			}
		}
			//test func***********************************************************************
	           	/*for(vector<pair<string, string> >::iterator it = m_vec.begin(); it != m_vec.end(); ++it)
			{
				cout << it->first << " " << it->second << endl;
			}*/
			//********************************************************************************
	
	}
	ifs1.close();
	ifs2.close();
}




/*
 * setup the list  to save first char or china word
 *
 * */
void MyConf::index_to_map()
{
	string key;
	vector<pair<string, string> >::size_type iter = 0;
	
	for(; iter != m_vec.size(); ++iter){
		string word = m_vec[iter].first;
		size_t it = 0;
		for(; it != word.size(); ++it){
			
			if(word[it] & (1 << 7)){
				key = word.substr(it, 3);
				it += 2;
			}
			else{
				key = word.substr(it, 1);
			}
			m_index[key].insert(iter);
		}
	}

	//*************************************************************************************
	/*for(map<char, set<int> >::iterator ite = m_index.begin(); ite != m_index.end(); ++ite)
	{
		cout << ite->first << " : ";
		for(set<int>::iterator i = ite->second.begin(); i != ite->second.end(); ++i)
			cout << (*i) << " ";
		cout << endl;
	}*/
	//**************************************************************************************

}


map<string, string> &MyConf::get_map()
{
	return m_map;
}


string MyConf::get_IP()
{
	map<string, string>::iterator IP_pos;
	IP_pos = m_map.find("IP");
	return IP_pos->second;
}

int MyConf::get_PORT()
{
	map<string, string>::iterator PORT_pos;
	PORT_pos = m_map.find("PORT");
	int PORT;
	stringstream ss(PORT_pos->second);
	ss >> PORT;
	return PORT;
}

