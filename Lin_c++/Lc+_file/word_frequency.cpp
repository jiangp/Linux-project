/*************************************************************************
  > File Name: word_frequency.cpp
  > Author: Arwen
  > Mail:745529725@qq.com 
  > Created Time: Sun 08 Mar 2015 11:14:54 AM CST
 ************************************************************************/

#include<iostream>
//using namespace std;
#include<string>
#include<fstream>
#include<vector>
#include<cctype> 
#include<sstream>
struct Node//detemind a struct
{
	int m_num;
	std::string m_word;
};
int main()
{
	int num = 0,all_num = 0, l = 0;
	int max = 0;
	std::ifstream ifs("1.txt", std::ifstream::in); //open file"1.txt"use read
	if(!ifs.good())
	{
		std::cout << " error " << std::endl;
	}
	std::vector<Node> str;//definition a vector
	std::string line,max_word;
	while(getline(ifs,line)) //read one line
	{
        l++;
		for(int i=0; i !=line.size(); ++i)
		{
			if(ispunct(line[i]))//punct
			{
				line[i] =' ';
			}
			else if(line[i]=tolower(line[i]))//big char
			{			
			}else
			{
			}
		}
		Node node;//defi node
		std::istringstream stream(line);//从line中继承 一个流
		while(stream>>node.m_word)//write to m_word
		{
			std::vector<Node>::iterator ix = str.begin();//迭加器
			for(; ix !=str.end(); ++ix)
			{
				if(node.m_word == ix->m_word)//判断重词
				{
					(ix->m_num)++;
					break;
				}
			}
			if(ix == str.end())//到最后 没有相同
			{
				str.push_back(node);
			}
			all_num++;
			std::cout << node.m_word << std::endl;
		}
	}


	std::vector<Node>::iterator it = str.begin();
	for(; it != str.end(); ++it)
	{
		if(max < it->m_num)
		{
			max = it->m_num;
			max_word = it->m_word;
		}

		num++;
	}
	std::cout << "word = " << num+1 << std::endl;
	std::cout << "line_num = " << l << std::endl;
	std::cout << "most of the word is : " << max_word << " : " << max+1 <<std::endl;

	return 0;
}

