/*************************************************************************
	> File Name: map.cpp
	> Author: Arwen
	> Mail:745529725@qq.com 
	> Created Time: Fri 13 Mar 2015 02:09:52 PM CST
 ************************************************************************/

#include<iostream>
//using namespace std;
#include<map>
#include<vector>
#include<fstream>
#include<sstream>
#include<time.h>
int main()
{
	std::ifstream ifs("The_Holy_Bible.txt");
	std::string line ,word;
	std::map<std::string, int> witer;
	time_t str, end;

	std::string::iterator iter;
	int len = 0, word_cnt = 0;
	str = clock();
	while(getline(ifs, line))
	{
		++len;
		for(iter = line.begin(); iter != line.end() ; ++iter)
		{
			if(ispunct(*iter))
				(*iter) = ' ';
			else if(isupper(*iter))
				(*iter) = tolower(*iter);

		}
		std::istringstream iss(line);
		while(iss>>word)
		{
			++word_cnt;
			
		//		std::pair<const std::string ,int>opr(word, 1);
		//		witer.insert(opr);
		//		if(!opr.second)
		//		  ++opr.second;
			
			++witer[word];//ease
		}
	}
	end = clock();
	std::map<std::string, int>::iterator ix ;
	std::cout << "the len =  " << len << "  the word cnt = " << word_cnt << std::endl;
	std::cout << std::endl;
	for(ix = witer.begin(); ix != witer.end() ; ++ix)
	{
//		std::cout << ((*ix).first) << " :" << (*ix).second << "      " ;
	}
	std::cout << std::endl;
	std::cout << "-----time-----" << std::endl
		      << (static_cast<double>(end - str) / CLOCKS_PER_SEC) << "s" << std::endl;
	return 0;
}

