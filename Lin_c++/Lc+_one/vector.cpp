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
	/*
	std::vector<int> vec;//demind member

	vec.push_back(10);
	vec.push_back(20);
	vec.push_back(30);
	vec.push_back(40);
	vec.push_back(50);

	//std::cout <<vec.capacity() <<std::endl;
	std::cout <<vec.size() <<std::endl;
	//vec  nolmor
	for(int index = 0; index!=vec.size();index++ )
	{
		std::cout<<vec[index]<<std::endl;
	}
	//vec  vector
	std::vector<int>::iterator it = vec.begin();
	for(; it!= vec.end(); it++)
	{
		std::cout<<*it<<std::endl;
	}
	//vec2 from vec
	std::cout<<std::endl;
	std::vector<int>vec2(vec);
	std::vector<int>::iterator it2 = vec2.begin();
	for(; it2!= vec2.end(); it2++)
	{
		std::cout<<*it2<<std::endl;
	}
	//vec3  from begin to  end;
	std::cout<<std::endl;
	std::vector<int>vec3(vec.begin(),vec.end());
	std::vector<int>::iterator it3 = vec3.begin();
	for(; it3!= vec3.end(); it3++)
	{
		std::cout<<*it3<<std::endl;
	}
*/
	std::vector<int> ivec;//ivec(10);
	for(std::vector<int>::size_type ix = 0; ix != 10; ++ix)
	{
		//ivec[ix] = ix;
		ivec.push_back(ix);//init  0
	}

	std::vector<int>::iterator it = ivec.begin();
	for(;it != ivec.end(); ++it )
	{
	    ivec[*it] = 2*ivec[*it];
	
	}
	for(std::vector<int>::size_type ix = 0; ix != ivec.size(); ++ix)
    	std::cout<< "ivec[ix] = "<<ivec[ix]<<std::endl;//cout
//	ivec.push_back(42);
//	std::cout << ivec[0] <<std::endl;
	return 0;
}
