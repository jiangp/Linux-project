/*************************************************************************
	> File Name: bitset.cpp
	> Author: Arwen
	> Mail:745529725@qq.com 
	> Created Time: Fri 06 Mar 2015 09:06:13 PM CST
 ************************************************************************/

#include<iostream>
//using namespace std;
#include<vector>
#include<bitset>
int main()
{
	int j=1,k=2,t=0;
	std::bitset<32> bitval;
	for(int i = 0; i != 32; ++i)
	{
		if(i== j){
			bitval[i] = 1;
			t=j;
			j=k;
			k=t+k;
		}else
		{
     		bitval[i] = 0;
		}
	

	}
	bitval.flip();
//	std::vector<int> val(10,9);12 23 35v5

	std::cout << "bitval = " << bitval <<std::endl;
	return 0;
}
