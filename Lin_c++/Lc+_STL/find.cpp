/*************************************************************************
	> File Name: find.cpp
	> Author: Arwen
	> Mail:745529725@qq.com 
	> Created Time: Sat 14 Mar 2015 02:27:23 PM CST
 ************************************************************************/

#include<iostream>
//using namespace std;
#include<map>
#include<fstream>
int main()
{
	std::ifstream ifs("file.txt");
	std::map<std::string, int> word_space;
	std::string  word;
	while(ifs >> word){
		std::pair<std::string, int> wd(word,1);
		word_space.insert(wd);
		
		if(!wd.second)
			++wd.second;
	}
	std::map<std::string, int>::iterator it = word_space.find("map.cpp");
	
	if(it != word_space.end())
		std::cout << it->second << std::endl;
	return 0;
}
