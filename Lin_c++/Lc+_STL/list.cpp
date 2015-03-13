/*************************************************************************
	> File Name: list.cpp
	> Author: Arwen
	> Mail:745529725@qq.com 
	> Created Time: Thu 12 Mar 2015 10:26:35 PM CST
 ************************************************************************/

#include<iostream>
//using namespace std;
#include<list>
#include<fstream>
#include<vector>
#include<sstream>
#include<algorithm>
class Word
{
	int m_num;
	std::string m_str;
public:
	Word()
	{
		m_num = 0;
		m_str = "";
	}
	Word(const std::string &str, int num) : m_str(str), m_num(num) { }

	bool cmpWord(const std::string &s)
	{
		if(m_str == s)
		{
			++m_num;
			return true;
		}
		return false;
	}
	void setWord(const std::string &s, int num)
	{
		m_str = s;
		m_num = num;
	}
	int getNum()
	{
		return m_num;	
	}
	std::string getStr()
	{
		return m_str;
	}
};

bool cmp(Word a, Word b)
{
	return a.getNum() > b.getNum();
}

int main()
{
	Word cword;
	int word_cnt=0;
	int file_line=0;
	std::ifstream  ifs("The_Holy_Bible.txt");
	std::string line ,word;
	std::vector<Word> vword ;
	std::vector<Word>::iterator witer;
	while(getline(ifs,line))
	{
		++file_line;
		for(std::string::iterator iter = line.begin();iter != line.end();++iter)
		{
			if(ispunct(*iter))
				*iter = ' ';
			if(isupper(*iter))
				*iter = tolower(*iter);
		}
		std::istringstream istr(line);
		while(istr>>word)
		{
			++word_cnt;
			for( witer = vword.begin();witer !=vword.end() ; ++witer)
			{
				if(witer -> cmpWord(word))
					break;
			}
			if(witer == vword.end())
			{
     			cword.setWord(word, 1);
				vword.push_back(cword);
			}
			
		}
	}

	sort(vword.begin(), vword.end(), cmp);

	std::cout << "-----Top Ten -----" << std::endl;

	int i = 0;

	for(std::vector<Word>::iterator wwiter = vword.begin(); i!= 11;++wwiter)
		std::cout << ++i << "st word '" << wwiter -> getStr() << "' : " << wwiter -> getNum() << std::endl;

	ifs.close();
	std::cout << "line = " <<file_line << " ";
	std::cout << "wort = " << word_cnt <<std::endl;

}
