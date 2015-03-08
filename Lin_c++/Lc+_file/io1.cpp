/*************************************************************************
	> File Name: io1.cpp
	> Author: Arwen
	> Mail:745529725@qq.com 
	> Created Time: Sat 07 Mar 2015 07:53:04 PM CST
 ************************************************************************/

#include<iostream>
//using namespace std;
#include<string>
void print()
{
	std::cout << "bad = " << std::cin.bad() << std::endl;
	std::cout << "fail = " << std::cin.fail() << std::endl;
	std::cout << "eof = " << std::cin.eof() << std::endl;
	std::cout << "good = " << std::cin.good() << std::endl;
}
int main()
{
	int num;
	print();
	while(std::cin>>num)
	{
		std::cout << num << std::endl;
	}
	print();

	std::cin.clear();// file end use this
	std::cin.ignore(1024, '\n');//  fflush(stdin)

	std::string s;
	std::cin >> s;
	std::cout << s << std::endl;
	return 0;
}
