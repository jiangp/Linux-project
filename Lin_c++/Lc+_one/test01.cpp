/*************************************************************************
	> File Name: test01.cpp
	> Author: Arwen
	> Mail:745529725@qq.com 
	> Created Time: Thu 05 Mar 2015 08:44:21 AM CST
 ************************************************************************/

#include<iostream>
namespace std
{
	int iva2 =20 ;
	//const int val1 ;
	double val3;
	int max(int  a, int b)
	{
		return a>b?a:b;
	}

}
void swap(int &a, int &b)
{
	int temp = a;
	a = b ;
	b = temp ;
}

int main()
{
	int ival = 10;
	int &refval = ival;
	int ival2 = 25;
//	refval = ival2;
	swap(ival, ival2);
//	std::cout << "ival = " <<ival <<std::endl;
//	std::cout << "ival2 = " <<ival2 <<std::endl;
	std::cout << "refval = "<<refval <<std::endl;//20
//	std::cout << "ival =" <<ival <<std::endl;
	//d
/*	for(int i = 0; i<2000 ; i++)
	{
		val += i ;
	}

//	std::val1++;//const can't chang;
	std::cout<<"hello World!"
		<<val<<" "
		<<std::max(3,8)
		<<std::val1
		<<std::val3<<std::endl;*/
	return 0;
}
