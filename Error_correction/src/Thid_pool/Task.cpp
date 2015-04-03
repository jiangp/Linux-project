/*************************************************************************
  > File Name: Task.cpp
  > Author: Arwen
  > Mail:745529725@qq.com 
  > Created Time: Tue 31 Mar 2015 09:57:18 AM CST
 ************************************************************************/

#include"Task.h"
#include<string.h>
#include<unistd.h>

	Task::Task(const std::string &msg, int sockfd, MyConf &conf)
:m_msg(msg) , m_sockfd(sockfd), m_ve(conf.get_vec()), m_idx(conf.get_index())
{

}

void Task::execute()
{

	string::const_iterator it = m_msg.begin();
	for(; it != m_msg.end(); ++it)
	{	

		map<char, set<int> >::const_iterator iter = (*m_idx).find(*it);
		if(iter != (*m_idx).end())
		{
			set<int>::iterator i = iter->second.begin();
			for( ; i != iter->second.end(); ++i)
			{

				Task::satistic(*i);
			}				

		}
	}
	send_msg();
	std::cout << "------" << std::endl;
}





void Task::satistic(int ch)
{

	size_t sz = m_msg.size();
	string str = m_msg.substr(0, sz - 1);

	pair<string, string> iter = (*m_ve)[ch];

	int len1 = str.size();
	int len2 = iter.first.size();
	const char *ps1 = str.c_str();
	const char *ps2 = iter.first.c_str();
	//edit
	int num = edit(ps1, len1, ps2, len2);
	//save result
	Result result(iter.first, iter.second, num);

	Task::get_result(result);
}










int Task::edit(const char *pstr1, int len1, const char *pstr2, int len2)
{

	int dp[len1 + 1][len2 + 1];
	for(int i = 0; i <= len1; ++i)
		dp[i][0] = i;
	for(int i = 0; i <= len2; ++i)
		dp[0][i] = i;
	for(int i = 1; i <= len1; ++i)
	{
		for(int j = 1; j <= len2; ++j)
		{
			if(pstr1[i - 1] == pstr2[j - 1])
				dp[i][j] = dp[i - 1][j - 1] ;
			else
			{
				int t1 = dp[i-1][j];
				t1 = t1 < dp[i][j-1] ? t1 : dp[i][j-1];
				t1 = t1 < dp[i-1][j-1] ? t1 : dp[i-1][j-1];
				dp[i][j] = t1 + 1;
			}
		}
	}
	return dp[len1][len2];
}




void Task::get_result(Result &a)
{
	m_result.push(a);
}

void Task::send_msg()
{

	/*send one******************************************/
	char msg[] = {0};
	Result str = m_result.top();
	m_result.pop();
	const char *word = str.get_word().c_str();
	const char *fre = str.get_frequence().c_str();		
	int sz = str.get_dist();

	sprintf(msg, "%s: %d  %s\n", word, sz, fre);
	int len = strlen(msg);		
	write(m_sockfd, msg, len);

}
