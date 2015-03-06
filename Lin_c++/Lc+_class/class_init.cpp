/*************************************************************************
	> File Name: class_init.cpp
	> Author: Arwen
	> Mail:745529725@qq.com 
	> Created Time: Fri 06 Mar 2015 03:35:55 PM CST
 ************************************************************************/

#include<iostream>
//using namespace std;
#include<string>
class X
{
public://                  3                null
	X(int ival):  m_ival2(ival), m_ival1(m_ival2){}

	void print()
	{
		std::cout << "m_ival1 = " << m_ival1 <<std::endl
			      << "m_ival2 = " << m_ival2 <<std::endl;
	}
private:
	int m_ival1 ;//first m_ival2= NULL  so 
	int m_ival2 ;//second m_ival1 = 3
};
int main(void)
{
	X x1(3);
	x1.print();//print 32767  3
	return 0;
}
