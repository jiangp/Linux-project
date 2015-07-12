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
#include<set>
#include<vector>
void home_page_print();
int list_file_print();
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
	int find_line;
	std::string file_name, line, word;  
	std::string sc_word;

	std::cin >> file_name;
	std::cout << ">" <<std::endl;
	std::cout << ">:Now you have in the file" <<std::endl;
	getchar();
	getchar();

	system("clear");
	std::ifstream ifs(file_name.c_str());
	if(!ifs.good())	
		std::cout << "open error..." << std::endl;
	int len = 0;
	std::set<int> word_line;
	std::map<std::string ,std::set<int> > word_space;
	std::vector<std::string> save_line;
	while(getline(ifs , line)){
		++len;
		save_line.push_back(line);
		
		for(std::string::iterator it = line.begin(); it != line.end(); ++it){
			if(ispunct(*it))
				(*it) = ' ';
			else if(isupper(*it))
				(*it) = tolower(*it);
		}
	
		std::istringstream word_stream(line);
		while(word_stream >> word){
	     	word_space[word].insert(len);
		}
	}
	
	std::cout << std::endl;
	std::cout << std::endl;
	std::cout << ">:please input the word you search" <<std::endl;
	std::cout << ">: ";
	std::cin >> sc_word;
	std::cout << ">: the word is :'";
	std::map<std::string, std::set<int> >::iterator pt_out = word_space.find(sc_word);
	if(pt_out !=word_space.end()){
		std::cout << pt_out->first << " ': ";
		
		std::set<int>::iterator put_line = pt_out->second.begin();
		for(; put_line != pt_out->second.end(); ++put_line){
			std::cout << (*put_line) << ",";
		}
	}
	std::cout << std::endl;
	std::cout << std::endl;
	std::cout << ">: input the line you find" <<std::endl;
	std::cout << std::endl;
	while(std::cout << ">: ",std::cin >> find_line ){
		std::cout << std::endl;
		if(0 < find_line && find_line <= len){
			std::cout << ">:the line:" << save_line[find_line-1] <<std::endl;
			std::cout << std::endl;
			std::cout << ">: please input other or back.." <<std::endl;
		}
		else{
			std::cout << ">:input error "<< std::endl;
			std::cout << ">:please input or back.."<< std::endl;
		}

	}
}
int  list_file_print()
{
	std::string dir_name;
	std::ifstream ifs("file");
	
	if(!ifs.good()){
		std::cout << "open error..." << std::endl;
		return -1;
	}
	
	std::vector<std::string> dir_space;
	while(getline(ifs , dir_name)){
		dir_space.push_back(dir_name);
	}
	
	int i = 0;
	std::cout << "list:" << std::endl;
	std::vector<std::string>::iterator read_out = dir_space.begin();
	for(;read_out != dir_space.end(); ++read_out){
		std::cout << ++i << " : " << (*read_out) << std::endl;
	}
	return 0;
}



void home_page_print()
{
	system("clear");
	std::cout << "***********************************" <<std::endl;
	std::cout << std::endl;
	std::cout << std::endl;
	std::cout << ">: Now you enter the wordSearch..." <<std::endl;
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
