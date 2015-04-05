/*************************************************************************
	> File Name: ./src/Cache.cpp
	> Author: Arwen
	> Mail:745529725@qq.com 
	> Created Time: Sun 05 Apr 2015 04:17:58 PM CST
 ************************************************************************/
/*
#include"Cache.h"

Cache::Cache(const int &num = 100)
{
	read_from_file("../data/hash_map_word.txt");
}

map<string, string>::iterator Cache::is_maped(const string &word)
{
	m_cache.find(word);
	if(is_maped != m_cache.end())
	{
		write(m__sockfd, is_maped->second.c_str(), is_maped->second.size());
		return is_maped;
	}
	else
		return 0;
}


void Cache::writr_to_file(ostream &fout)
{
	mutex.lock();
	fout.open("../data/hash_map_word.txt");
	hash_map<string, string>::iterator iter = m_cache.begin();
	for(; iter != m_cache.end(); ++iter)
	{
		fout<< iter->first << " " << iter->second << endl;
	}
	mutex.unlock();
	fout.close();
}



void Cache::read_from_file(const string &file_name)
{
	ifsstream ifs(file_name.c_str());
	string line;
	while(getline(ifs, line))
	{
		unsigned int pos = line.find(' ');
		m_cache.insert(pair<string,string>(line.substr(0, pos),(line.substr(pos + 1))));
	}
	ifs.close();
}
*/
