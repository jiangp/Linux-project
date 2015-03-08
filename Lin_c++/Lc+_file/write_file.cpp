/*************************************************************************
	> File Name: write_file.cpp
	> Author: Arwen
	> Mail:745529725@qq.com 
	> Created Time: Sun 08 Mar 2015 09:13:21 AM CST
 ************************************************************************/

#include<iostream>
//using namespace std;
#include<fstream>
#include<sstream>
#include<string>
#include<vector>
int main()
{
	std::ofstream ofs("1.txt");
	if(!ofs.good())
	{
		return -1;
		
	}
	std::string line;
	std::vector<std::string> str ;
	while(std::cin>>line)
	{
		str.push_back(line);
	}
	
	std::vector<std::string>::iterator sit = str.begin();
    for(;sit != str.end();++sit)
	{
		ofs << *sit << std::endl;
	}

	return 0;
}
