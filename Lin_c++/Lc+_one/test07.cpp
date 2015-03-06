/*************************************************************************
	> File Name: test07.cpp
	> Author: Arwen
	> Mail:745529725@qq.com 
	> Created Time: Thu 05 Mar 2015 08:07:29 PM CST
 ************************************************************************/

#include<iostream>
//using namespace std;
#include<string>
#include<sstream>
#include<fstream>
int main()
{
//	std::string str;

 //  getline(std::cin,str);
//    std::cin>>str;
//	std::cout<<str<<str.size()<<std::endl;
    std::string s("HelloWorld!!");
/*	for(int index = 0; index!=s.size(); ++index)
	{
		s[index] = tolower(s[index]);
	}
	std::cout<<s<<std::endl;*/

	int ival= 512;
	int ival2 = 1024;
	std::stringstream ss;
	ss << "ival=" <<ival<< "ival2=" << ival2 <<std::endl;
	std::string str = ss.str();
	//std::cout<<str<<std::endl;
	while(ss>>str)
	{
		std::cout << str <<std::endl;
	}


	while(std::cin>> ival, !std::cin.eof())
	{
		if(std::cin.bad())
		{
			std::cout << "IO stream corrupted ! " <<std::endl;
			return -1;
		}
		if(std::cin.fail())
		{
			std::cout << "data illegal, try again ! " <<std::endl;
			std::cin.clear();
			std::cin.ignore(1024, '\n');
			continue ;
		}
		std::cout << "ival = " <<ival<<std::endl;
	}



	return 0;
}

