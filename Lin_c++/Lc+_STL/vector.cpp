/*************************************************************************
	> File Name: vector.cpp
	> Author: Arwen
	> Mail:745529725@qq.com 
	> Created Time: Thu 12 Mar 2015 05:30:02 PM CST
 ************************************************************************/

#include<iostream>
//using namespace std;
#include<vector>
int main()
{
	int num[5] = {1,2,3,4,5};
	std::vector<int> vec_num(num,num+5);
	std::vector<int>::iterator it = vec_num.begin();
	for(;it != vec_num.end(); ++it)
	{
		std::cout << (*it) << " ";
	}
	std::cout << std::endl;
	//+-
	vec_num.pop_back();//delete
	vec_num.push_back(7);//create
	///+++
	std::vector<int>::iterator in = vec_num.end();// the point position
    in =vec_num.insert(in,9);//+1
	vec_num.insert(in, 3, 0);//+ n=3 
	vec_num.insert(in, num,num+3);//+  first~ last3
////////out
	std::vector<int>::iterator ix = vec_num.begin();
	for(;ix != vec_num.end(); ++ix)
	{
		std::cout << (*ix) << " ";
	}
	std::cout << std::endl;
////out  first  end
    std::cout << vec_num.front() << std::endl;//first element
	std::cout << vec_num.back() << std::endl; //last element
////delete

	std::vector<int>::iterator iq = vec_num.begin();
	for(; iq != vec_num.end(); ++iq)
	{
		if(*iq == 4)
		{
		   // vec_num.erase(iq);//delete iq
		   vec_num.erase(iq,iq+3);//delete iq~iq+n
		}
		std::cout << (*iq) << " "; 
	}
	//clear
	vec_num.clear();
	std::vector<int>::iterator iw = vec_num.begin();
	for(; iw != vec_num.end(); ++iw)
	{
		std::cout << (*iw) << " "; 
	}

	return 0;
}
