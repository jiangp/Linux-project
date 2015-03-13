/*************************************************************************
	> File Name: file_wd_search.cpp
	> Author: Arwen
	> Mail:745529725@qq.com 
	> Created Time: Fri 13 Mar 2015 08:43:53 PM CST
 ************************************************************************/

#include<iostream>
#include<stdio.h>
#include<stdlib.h>
//using namespace std;
#include<string>
#include<fstream>
#include<sstream>
#include<vector>
#include<map>

void home_page_print();
void list_file_print();
void home_page_print1();
void open_search_file();
int main()
{
	home_page_print();
	list_file_print();
	home_page_print1();
	open_search_file();

	return 0;
}
void open_search_file()
{
	std::string file_name, line, word;  
	std::cin >> file_name;
	std::ifstream ifs(file_name.c_str());
	if(!ifs.good())	
		std::cout << "open error..." << std::endl;
	int len = 0;
//	std::map<std::string ,std::set<int> > word_space;
	while(getline(ifs , line))
	{
		++len;
		for(std::string::iterator it = line.begin(); it != line.end(); ++it)
		{
			if(ispunct(*it))
				(*it) = ' ';
			else if(isupper(*it))
				(*it) = tolower(*it);
		}
		std::cout << "." ;
	//	std::sstringstream word_stream(line);
	//	while(word_stream >> word)
	//	{
		//	std::pair<std::string, std::set<int> > ret(word,len);
		//	word_space.insert(ret);
	//		if(!ret.first)
	//			insert(ret->second)

	//	}
	}

}
void list_file_print()
{
	std::string dir_name;
	std::ifstream ifs("file.txt");
	if(!ifs.good())	
		std::cout << "open error..." << std::endl;
	std::vector<std::string> dir_space;
	while(getline(ifs , dir_name))
	{
		dir_space.push_back(dir_name);
	}
	int i = 0;
	std::vector<std::string>::iterator read_out = dir_space.begin();
	for(;read_out != dir_space.end();++read_out)
	{
		std::cout<< ++i << " : " << (*read_out) << std::endl;
	}
}



void home_page_print()
{
	system("clear");
	std::cout << "***********************************" <<std::endl;
	std::cout << std::endl;
	std::cout << std::endl;
	std::cout << ">: Now you enter the word search..." <<std::endl;
	std::cout << std::endl;
	std::cout << std::endl;
	std::cout << std::endl;
	getchar();
	system("clear");
	std::cout << "***********************************" <<std::endl;
	std::cout << ">: The dir list for search...      " <<std::endl;
	std::cout << std::endl;

}
void home_page_print1()
{
	std::cout << "***********************************" <<std::endl;
	std::cout << std::endl;
	std::cout << std::endl;
	std::cout << ">: please input the flie's name..." <<std::endl;
	std::cout << std::endl;
	std::cout << ">file name: ";
}
