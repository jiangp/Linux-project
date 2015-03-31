/*************************************************************************
	> File Name: Task.cpp
	> Author: Arwen
	> Mail:745529725@qq.com 
	> Created Time: Tue 31 Mar 2015 09:57:18 AM CST
 ************************************************************************/

#include"Task.h"

Task::Task(const std::string &msg, int sockfd)
	:m_msg(msg) , m_sockfd(sockfd)
{

}

Task::Task(const char *msg, int sockfd)
	:m_msg(msg), m_sockfd(sockfd)
{
}

void Task::execute(MyConf &conf)
{

	string::iterator it = m_msg.begin();
	for(; it != m_msg.end(); ++it)
	{
		map<string, set<int> >::iterator iter = conf.m_index.begin();
		for(; iter != conf.m_index.end(); ++iter)
		{
			if((iter->first) == (*it))
			{
				set<int>::iterator i = iter->second.begin();
				for( ; i != iter->second.end(); ++i)
				{
					std::cout << " 1 " << std::endl;
				//	satistic(*i);
				}				
				break;
			}else if(!isalpha(*it))
			{
				break;
			}
		}
	}
}

/*

char* Task::satistic(int ch)
{
	 return m_vec[ch];
}

int Task::editdistance(m_vec[ch])
{
	cmp(m_vec[ch].first, m_msg);

	return num;
}
void Task::get_result
{
	m_result.push(priority_queue<str, vector<string, string> , int>)
}

*/
