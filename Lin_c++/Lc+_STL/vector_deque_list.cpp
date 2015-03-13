/*************************************************************************
	> File Name: vector_deque_list.cpp
	> Author: Arwen
	> Mail:745529725@qq.com 
	> Created Time: Thu 12 Mar 2015 04:40:42 PM CST
 ************************************************************************/

#include<iostream>
//using namespace std;
#include<vector>
#include<deque>
#include<list>
int main()
{
	std::vector<int> oby;
	double sz[5] = {1,2,3,4,5};
	std::deque<double> obD(sz,sz+5);
	for(int i = 0;i < obD.size();++i)
	{
		std::cout <<obD[i] << " ";
	}
	std::cout << std::endl;

	std::deque<double>::iterator id =obD.begin();
	for(; id !=obD.end();++id)
	{
		std::cout << *id << " ";
	}

	std::cout <<std::endl;
	std::list<float> obL(3,5);
	std::list<float>::iterator iter = obL.begin();
	for(;iter !=obL.end();++iter)
	{
		(*iter)+=2;
		std::cout << (*iter) << " " << std::endl;
	}
	std::list<float> obL2(4,9);
	obL.swap(obL2);

	for(iter =obL.begin(); iter !=obL.end(); iter++)
	{
		std::cout << (*iter) << " " <<std::endl;
	}
return 0;
	
}
