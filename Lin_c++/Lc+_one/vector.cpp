/*************************************************************************
	> File Name: vector.cpp
	> Author: Arwen
	> Mail:745529725@qq.com 
	> Created Time: Thu 05 Mar 2015 03:41:43 PM CST
 ************************************************************************/

#include<iostream>
//using namespace std;
#include<vector>
int main()
{
	std::vector<int> vec;

	vec.push_back(10);
	vec.push_back(20);
	vec.push_back(30);
	vec.push_back(40);
	vec.push_back(50);

	//std::cout <<vec.capacity() <<std::endl;
	std::cout <<vec.size() <<std::endl;
	for(int index = 0; index!=vec.size();index++ )
	{
		std::cout<<vec[index]<<std::endl;
	}
	//
	std::vector<int>::iterator it = vec.begin();
	for(; it!= vec.end(); it++)
	{
		std::cout<<*it<<std::endl;
	}
	//
	std::cout<<std::endl;
	std::vector<int>vec2(vec);
	std::vector<int>::iterator it2 = vec2.begin();
	for(; it2!= vec2.end(); it2++)
	{
		std::cout<<*it2<<std::endl;
	}
	//
	std::cout<<std::endl;
	std::vector<int>vec3(vec.begin(),vec.end());
	std::vector<int>::iterator it3 = vec3.begin();
	for(; it3!= vec3.end(); it3++)
	{
		std::cout<<*it3<<std::endl;
	}
	return 0;
}
