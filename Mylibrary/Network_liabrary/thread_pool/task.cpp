/*************************************************************************
  > File Name: task.cpp
  > Author: Arwen
  > Mail:745529725@qq.com 
  > Created Time: Tue 31 Mar 2015 09:57:18 AM CST
 ************************************************************************/

#include"task.h"
#include<string.h>
#include<unistd.h>

/* the word len */
std::size_t length(const std::string &str)
{
	std::size_t ilen = 0;
	for(std::size_t index = 0; index != str.size(); ++index)
	{
		if(str[index] & ( 1 << 7 ))
			index += 2;
		++ilen;
	}
	return ilen;
}




/*
 * 构造函数
 * */
	Task::Task(const std::string &msg, int sockfd, MyConf &conf, Cache &cache)
	:m_msg(msg) ,
	m_sockfd(sockfd), 
	m_ve(conf.get_vec()), 
	m_idx(conf.get_index()),
	m_ca(cache.is_mapped())
{

}
/*
 * 查词函数
 * 先从缓存中找 若没有 在去查
 *
 * */

void Task::execute()
{
	/*1.//get from Redis
	 *
     *size_t sz = m_msg.size();
     *string msg = m_msg.substr(0, sz - 1);
	 *string str = r->get(msg);
	 *if(str != "NO"){
	 *	write(m_sockfd, str.c_str(), str.size());
	 *	return ;
	 * }
	 * */

	//2.get from cache
	size_t sz = m_msg.size();
	string msg = m_msg.substr(0, sz - 1);

	map<string, string >::iterator  str = (*m_ca).find(msg);

	if(str != m_ca->end()){
		write(m_sockfd, str->second.c_str(), (str->second).size());
		std::cout << "+++++++++" << std::endl;
		return ;
	}

	/*3.find from map_list*/
	find_word_from_map();
	send_msg();
	std::cout << "------" << std::endl;
}



/*find the char from map and seach the subscrite of vector*/
void Task::find_word_from_map()
{
	string word;
	size_t it = 0;
	for(; it != m_msg.size(); ++it)
	{	

		if(m_msg[it] & (1 << 7)){

			word = m_msg.substr(it, 3);
			it += 2;
		}else{
			word = m_msg.substr(it, 1);
		}

		map<string, set<int> >::const_iterator iter = (*m_idx).find(word);
		if(iter != (*m_idx).end())
		{
			Task::satistic(&(iter->second));
		}				
	}

}



/*get the word from vector 
 * calculation text distance
 * is distance small 3 
 * gave to Result*/
void Task::satistic(const set<int> *m_set)
{
	set<int>::const_iterator i = m_set->begin();
	for(; i != m_set->end(); ++i)
	{

		pair<string, string> iter = (*m_ve)[*i];

		size_t len1 = length(m_msg);
		size_t len2 = length(iter.first);
		size_t sz = m_msg.size();
		string ps1 = m_msg.substr(0, sz - 1);
		string ps2 = iter.first;
		//edit
		size_t num = edit(ps1, len1, ps2, len2);
	
		//save to pri_queue
		if(num < 3){
			//save result
			Result result(iter.first, iter.second, num);
			Task::get_result(result);
		}
	}
}






/*calculation tow  word's Text distance
 * is support English  Chinese utf-8
 * */
size_t Task::edit(const string &pstr1, size_t len1, const string &pstr2, size_t len2)
{

	size_t dp[len1 + 1][len2 + 1];
	for(size_t i = 0; i <= len1; ++i)
		dp[i][0] = i;
	for(size_t i = 0; i <= len2; ++i)
		dp[0][i] = i;
	
	string sublhs, subrhs;
	for(size_t i = 1, lhs_i = 0; i <= len1; ++i, ++lhs_i)
	{
		if(pstr1[lhs_i] & (1 << 7)){
			sublhs = pstr1.substr(lhs_i, 3);
			lhs_i += 2;
		}else{
			sublhs = pstr1.substr(lhs_i, 1);
		}

		for(size_t j = 1, rhs_j = 0; j <= len2; ++j, ++rhs_j)
		{
			if(pstr2[rhs_j] & (1 << 7)){
				subrhs = pstr2.substr(rhs_j, 3);
				rhs_j += 2;
			}else{
				subrhs = pstr2.substr(rhs_j, 1);
			}
			

			if(sublhs == subrhs)
				dp[i][j] = dp[i - 1][j - 1] ;
			else
			{
				size_t t1 = dp[i-1][j];
				t1 = t1 < dp[i][j-1] ? t1 : dp[i][j-1];
				t1 = t1 < dp[i-1][j-1] ? t1 : dp[i-1][j-1];
				dp[i][j] = t1 + 1;
			}
		}
	}
	return dp[len1][len2];
}


/* Let the Result push in priority_queue*/
void Task::get_result(Result &a)
{
	m_result.push(a);
}


/*get the msg from Priority_queue send to Client */
void Task::send_msg()
{
	/*send one******************************************/
	string strr;
	if(m_result.empty()){

		strr = "no similar word!";
		write(m_sockfd, strr.c_str(), strr.size());
	}else{

		/*get Result from prioirty_queue*/
		Result str = m_result.top();
		m_result.pop();
		
		/*send to Client*/
		strr = str.get_word();
		write(m_sockfd, strr.c_str(), strr.size());
	}


	/*let the word in m_cache*/
	size_t sz = m_msg.size();
	string msg = m_msg.substr(0, sz - 1);
	(*m_ca).insert(make_pair(msg, strr));
	
	/*//Redis
	 * r->set(msg, strr); */
}	



	/*send more*****************************************

	if(m_result.empty()){
		string str = "no similar word!";
		write(m_sockfd, str.c_str(), str.size());
	}
	else{
		//get from queue
		Result str = m_result.top();
		m_result.pop();
		//add to acche

		size_t sz = m_msg.size();
		string msg = m_msg.substr(0, sz - 1);
		(*m_ca).insert(make_pair(msg, strr));
		//get infor
		const char *word = str.get_word().c_str();
		const char *fre = str.get_frequence().c_str();		
		int sz = str.get_dist();
	    //save to msg
		char msg[] = {0};
		sprintf(msg, "%s: %d  %s\n", word, sz, fre);
		int len = strlen(msg);		
		write(m_sockfd, msg, len);
 	}*/

	
