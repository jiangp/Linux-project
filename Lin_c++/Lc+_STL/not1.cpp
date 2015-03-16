/*************************************************************************
	> File Name: not1.cpp
	> Author: Arwen
	> Mail:745529725@qq.com 
	> Created Time: Mon 16 Mar 2015 04:18:24 PM CST
 ************************************************************************/

#include<iostream>
//using namespace std;
#include<string>
#include<vector>
#include<functional>
#include<algorithm>
typedef std::vector<int> Vec_space;
typedef std::vector<int>::iterator iter;

int main()
{
	int sz[] = {1,2,3,4,5,6};
	Vec_space ob(sz, sz + 6);
	std::less<int> lt;
	replace_if(ob.begin(), ob.end(),std::not1(bind1st(lt, 3)),7);// let 7 bind on first777456 // bind2nd(lt, 3) ,7   127777

	for(iter it = ob.begin(); it != ob.end(); ++it)
	{
		std::cout << (*it) << " ";
	}

	return 0;
}
