/*************************************************************************
	> File Name: derivation.cpp
	> Author: Arwen
	> Mail:745529725@qq.com 
	> Created Time: Wed 18 Mar 2015 03:27:02 PM CST
 ************************************************************************/

#include<iostream>
//using namespace std;
class Point 
{
private:
	int m_x;
	int m_y;
public:
	Point(int x= 0,int y = 0){
		m_x = x;
		m_y = y;
	}
	int getx()
	{
		return m_x;
	}
	int gety()
	{return m_y;}
	void print()
	{
		std::cout << "(" << m_x << " , " << m_y << ")" << std::endl;
	}
};
class Point3D : public Point
{
public:
	Point3D(int x, int y, int z) :Point(x , y){
		m_zi = z;
	}
	void print()
	{
		std::cout << "(" << getx() << gety() << m_zi << ")" << std::endl;
	}
	int CalcSum()
	{
		return getx() + gety() + m_zi;
	}
private:
	int m_zi;
};

int main()
{
	Point x = (7,9);
	x.print();

	Point3D z(3,4,5);
	z.print();

	int res = z.CalcSum();
	std::cout << res << std::endl;

	return 0;
}
