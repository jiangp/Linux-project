/*************************************************************************
	> File Name: mem_fun_ref.cpp
	> Author: Arwen
	> Mail:745529725@qq.com 
	> Created Time: Mon 16 Mar 2015 04:45:55 PM CST
 ************************************************************************/

#include<iostream>
//using namespace std;

#include<string>
#include<vector>
#include<functional>
#include<algorithm>
class numval
{
	int val;
public:
	numval()
	{
		val = 0;
	}
	numval(int j)
	{
		val = j;
	}
	bool display()
	{
		std::cout << " ";
		return true;
	}
	bool iseven()
	{
		return(bool)!(val%2);
	}
	bool isprime()
	{
		for(int i = 2; i <= (val/2); ++i)
		{
			if(!(val%i)) return false;
		}
		return true;
	}
};
int main()
{
	std::vector<numval> num_sp(13);
	std::vector<numval>::iterator it1;
	for(int i = 0; i < 13; ++i)
	{
		num_sp[i] = numval(i+1);
	}

	std::cout << "num_sp value : " <<std::endl;
	for_each(num_sp.begin(), num_sp.end(), std::mem_fun_ref(&numval::display));

	it1 = remove_if(num_sp.begin(), num_sp.end(), std::mem_fun_ref(&numval::isprime));
	std::cout << "num_sp remove and other: " << std::endl;
	std::cout <<std::endl;
	for_each(num_sp.begin(), it1, std::mem_fun_ref(&numval::display));

	return 0;
}
