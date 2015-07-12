/*************************************************************************
	> File Name: cache.cpp
	> Author: Arwen
	> Mail:745529725@qq.com 
	> Created Time: Sun 05 Apr 2015 04:17:58 PM CST
 ************************************************************************/

#include"cache.h"

/*init a cacahe
 * on begin read the file save to cache
 * Create one pthread to handle write */
Cache::Cache()
{
	read_from_file();
	pthread_create(&m_ptid, NULL, cache_write, this);
}


/*detach the thread*/
Cache::~Cache()
{
	pthread_detach(m_ptid);
} 

/*the func to wait and write*/
void *Cache::cache_write(void *arg)
{		
	Cache *pt = static_cast<Cache*>(arg);

	while(1){				
			sleep(1000);
    		pt->write_to_file();
		}
}
	

/*get the map*/
map<string, string> *Cache::is_mapped()
{
	
	return 	&m_cache;
}

/*when write the map must add lock*/
void Cache::write_to_file()
{

	mutex.lock();
	ofstream fout("../data/hash_map_word.txt");
	map<string, string>::iterator iter = m_cache.begin();
	for(; iter != m_cache.end(); ++iter)
	{
		fout<< iter->first << " " << iter->second << endl;
	}
	mutex.unlock();
	fout.close();

}


/*read from_file save to cache_map*/
void Cache::read_from_file()
{
	ifstream ifs("../data/hash_map_word.txt");
	string line;
	while(getline(ifs, line))
	{
		unsigned int pos = line.find(' ');
		m_cache.insert(pair<string,string>(line.substr(0, pos),(line.substr(pos + 1))));
	}
	ifs.close();
}


