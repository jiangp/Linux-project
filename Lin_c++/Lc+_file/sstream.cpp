/*************************************************************************
	> File Name: sstream.cpp
	> Author: Arwen
	> Mail:745529725@qq.com 
	> Created Time: Fri 06 Mar 2015 05:19:19 PM CST
 ************************************************************************/

#include<iostream>
//using namespace std;
#include<string>
#include<fstream>
#include<sstream>
#include<vector>
int main()
{
	std::ifstream ifs("sstream.cpp");
	if(!ifs.good())
	{
		return -1;
	}

	std::vector<std::string> vec_str;
	std::string line;
	while(ifs>>line)
	{
		vec_str.push_back(line);
	}

	std::stringstream ss;

	std::vector<std::string>::iterator sit = vec_str.begin();//vec_str.begin
	for(;sit != vec_str.end(); ++sit)
	{
		ss<<*sit <<std::endl;
	}

	std::string str;
	while(ss >>str)
	{
		std::cout <<str<<std::endl;
	}
	return 0;
}
