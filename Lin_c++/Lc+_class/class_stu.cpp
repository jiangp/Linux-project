/*************************************************************************
	> File Name: class_stu.cpp
	> Author: Arwen
	> Mail:745529725@qq.com 
	> Created Time: Tue 10 Mar 2015 02:22:47 PM CST
 ************************************************************************/

#include<iostream>
#include<cstring>
//using namespace std;
class Computer
{
public:
	Computer(const char *brand, float price)
	{
		m_psBrand = new char[strlen(brand) + 1];
		strcpy(m_psBrand, brand);
		m_fPrice = price ;
		m_fTotalPrice += m_fPrice;
	}
	Computer(): m_psBrand(NULL),m_fPrice(0.0){}

	~Computer()
	{
		delete[] m_psBrand;
		m_psBrand = NULL;
		std::cout << " clear it" <<std::endl;
	}
	void print()
	{
		std::cout << "name" << m_psBrand <<std::endl;
		std::cout << "price" << m_fPrice <<std::endl;
	}
	static void print_total()
	{
		std::cout << "total price" << m_fTotalPrice << std::endl;
	}
	static void print(Computer &com);
private:
		char *m_psBrand;
		float m_fPrice;
		static float m_fTotalPrice;
};

float Computer::m_fTotalPrice =0.0;
void Computer::print(Computer &com)
{
	std::cout << "m_name" << com.m_psBrand <<std::endl;
	std::cout << "price" << com.m_fPrice <<std::endl;
}
int add(int x, int y)
{
	return x+y;
}
int main()
{
	Computer pc("IBM" , 7000);
	pc.print(pc);
	pc.print_total();

	Computer pc2("mac", 10000);
	Computer::print(pc2);
	pc2.print_total();

	Computer *ppc = new Computer("ACER", 4999);

	char *pstr = "hello,world";
	return 0;
}
