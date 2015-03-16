/*************************************************************************
	> File Name: queue.cpp
	> Author: Arwen
	> Mail:745529725@qq.com 
	> Created Time: Mon 16 Mar 2015 04:10:03 PM CST
 ************************************************************************/

#include<iostream>
//using namespace std;
#include<queue>
int main()
{
	int num = 0;
	std::queue<int> que;
	for(int index = 0; index != 10; ++index)
	{
		que.push(index);
		std::cout << que.front() << " int queue" <<std::endl;
	}
	std::cout << "the queue size" << que.size() << std::endl;
	for(int index = 0; index != 10; ++index)
	{
		std::cout << que.front() << " out " <<std::endl;
		que.pop();
	}
	std::cout <<"the size" << que.size() << std::endl;
	return 0;
}
