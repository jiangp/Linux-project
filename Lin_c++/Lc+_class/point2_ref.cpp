/*************************************************************************
	> File Name: point2_ref.cpp
	> Author: Arwen
	> Mail:745529725@qq.com 
	> Created Time: Mon 09 Mar 2015 10:07:24 PM CST
 ************************************************************************/

#include<iostream>
//using namespace std;
#include<cstring>
class Point
{
public:
	Point(int ix, int iy, double& z) : m_ref1(m_ix),m_ref2(z)
	{
		m_ix = ix;
		m_iy = iy;
	}

	void print()
	{
		std::cout << m_ix << " " << m_iy << std::endl;
		std::cout << "m_ref1 = " << m_ref1 <<std::endl
			<< "m_ref2 = " << m_ref2 << std::endl;
	}
private:
	int m_ix;
	int m_iy;
	int &m_ref1;
	double &m_ref2;
};
int main ()
{
	double dval = 5.0;
	Point pt(3,4,dval);

	pt.print();

	std::cout << sizeof(Point) << std::endl;
	return 0;
}
