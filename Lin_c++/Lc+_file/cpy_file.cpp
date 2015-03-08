/*************************************************************************
	> File Name: cpy_file.cpp
	> Author: Arwen
	> Mail:745529725@qq.com 
	> Created Time: Sun 08 Mar 2015 10:54:26 AM CST
 ************************************************************************/

#include<iostream>
//using namespace std;
#include<string>
#include<fstream>
#include<vector>
int main()
{
	std::ifstream ifs("1.txt");
	std::ofstream ofs("2.txt");
	
	std::vector<std::string> str ;
	std::string line;
	while(getline(ifs,line))
	{
		str.push_back(line);
	}
	std::vector<std::string>::iterator sit = str.begin();
	for(; sit != str.end(); ++sit)
	{
		ofs << *sit << std::endl;
	}
	return 0;
}
