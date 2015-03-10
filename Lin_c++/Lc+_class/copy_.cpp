/*************************************************************************
	> File Name: copy_.cpp
	> Author: Arwen
	> Mail:745529725@qq.com 
	> Created Time: Mon 09 Mar 2015 10:06:42 AM CST
 ************************************************************************/

#include<iostream>
#include<string.h>
//using namespace std;
class computer
{
public:
	computer(const char *brand, float price)
	{
		m_psBrand = new char[strlen(brand) + 1];
		strcpy(m_psBrand, brand);
		m_fPrice = price;
		m_fTotalPrice += m_fPrice;
	}//构造函数赋指
	computer() : m_psBrand(NULL) , m_fPrice(0.0){}//赋初值
	computer(const computer &rhs)//复制构造函数
	{
		m_psBrand = new char[strlen(rhs.m_psBrand)+ 1];
		if(NULL == m_psBrand)
		{
			std::cout << "memory allocated fail" << std::endl;
			return ;
		}
		m_fPrice = rhs.m_fPrice;
	}
	computer &operator= (const computer &rhs)//算术重铸函数
	{
		if(this == &rhs)
			return (*this);
		if(m_psBrand){
			delete [] m_psBrand;
			m_psBrand = NULL;
		}//防止内存泄露
		m_psBrand = new char[strlen(rhs.m_psBrand)+1];
		if(NULL == m_psBrand){
			std::cout << "memory allocated fail" <<std::endl;
			return (*this);
		}
		strcpy(m_psBrand , rhs.m_psBrand);
		m_fPrice = rhs.m_fPrice;
		std::cout << "diaoyong A" << std::endl;
		return *this;
	}
	~computer()//析构函数
	{
		delete[] m_psBrand;
		m_psBrand = NULL;
		//std::cout << "clear " <<std::endl;
	}
	void print()//输出函数
	{
		std::cout << "computer name : " << m_psBrand <<std::endl;
		std::cout << "price : " << m_fPrice <<std::endl;
	}
	static void price_total()//类函数
	{
		std::cout << "total price : " << m_fTotalPrice << std::endl;
	}
	static void print(computer &com);//	赋值输出函数

private:
    char *m_psBrand;
	float m_fPrice;
	static float m_fTotalPrice;
};

float computer::m_fTotalPrice =0.0;

void computer::print(computer &com)
{
	std::cout << "my computer_name : " << com.m_psBrand <<std::endl;
	std::cout << "my computer price : " << com.m_fPrice <<std::endl;
}
int main()
{
	
	computer pc("IBM" , 7000);
	pc.print();
	pc.price_total();

	std::cout << std::endl;
	computer pc2("mac", 10000);
	pc.print();
	pc2.price_total();

	std::cout << std::endl;
	computer pc3;
	pc3 = pc2 ;
	std::cout << std::endl;
	pc3.print(pc3);
	return 0;
}
