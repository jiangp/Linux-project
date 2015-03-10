/*************************************************************************
	> File Name: complex.cpp
	> Author: Arwen
	> Mail:745529725@qq.com 
	> Created Time: Tue 10 Mar 2015 09:29:49 PM CST
 ************************************************************************/
// 函数调用   //成员函数 调用   // friend 函数使用
#include<iostream>
//sing namespace std;
#include<string.h>
class Complex
{
public:
	Complex(double x=0.0 ,double y=0.0) : m_real(x), m_imag(y){}
	void print() const
	{
		std::cout << m_real << " + " << m_imag << "i*" << std::endl;
	}

/*	Complex operator+(const Complex &rhs)
	{
		return Complex(m_real + rhs.m_real, m_imag + rhs.m_imag);
	}*/
   friend Complex operator+(const Complex &num1,const Complex &num2);

private:
	double m_real;
	double m_imag;
};

Complex operator+(const Complex &num1,const Complex &num2)
{
	 Complex cx = Complex(num1.m_real + num2.m_real , num1.m_imag + num2.m_imag );
	 return cx;
}
/*
Complex operator+(const Complex &num1,const Complex &num2)
{
	 Complex cx = Complex(num1.m_real + num2.m_real , num1.m_imag + num2.m_imag );
	 return cx;
}*/
int main()
{
	Complex num1(1.0 ,2.0);
	num1.print();

	std::cout << std::endl;
	Complex num2(3.0 ,4.0);
	num2.print();
	std::cout << std::endl;

	Complex num3;
	num3 = num1 + num2;
	num3.print();
	return 0;
}
