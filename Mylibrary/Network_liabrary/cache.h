/*************************************************************************
	> File Name: cache.h
	> Author: Arwen
	> Mail:745529725@qq.com 
	> Created Time: Sun 05 Apr 2015 04:05:53 PM CST
 ************************************************************************/

#ifndef _CACHE_H
#define _CACHE_H
#include<iostream>
#include<stdio.h>
#include<unistd.h>
#include<map>
#include<sstream>
#include<string>
#include<fstream>
#include"mutex.h"

using namespace std;
class Cache
{
	
	static void *cache_write(void *);
	pthread_t m_ptid;
	Mutex mutex;
public:
	Cache();
    ~Cache();
	map<string, string> m_cache;
	map<string, string > *is_mapped();
	void write_to_file();
	void read_from_file();
};

/*
// hash_map

class Cache
{
	hash_map<string, string, Hash_cmp> m_cache;
	Mutex mutex;
public:
	Cache(const int &num = 100);
	hash_map<string, string, Hash_cmp>::iterator is_mapped(const string &word);
	void write_to_file(ostream &fout);
	void read_from_file(const string &file_name);
};


class Hash_cmp : public hash_compare<CString>
{
public:
	size_t operator()(const string &str)
	{
		size_t value = _HASH_SEED;
		size_t size = str.gitLength();
		if(size > 0)
		{
			size_t temp = (size/16) + 1;
			size -= temp;
			for(size_t idx = 0; idx <= size; idx += temp)
			{
				value +=(size_t)str[(int)idx];
			}
		}
		return (value);
	}
};
*/
#endif

