/*************************************************************************
	> File Name: line.cpp
	> Author: Arwen
	> Mail:745529725@qq.com 
	> Created Time: Mon 09 Mar 2015 11:01:21 PM CST
 ************************************************************************/

#include<iostream>
//using namespace std;
class Point
{
public:
	Point(int ix ,int iy)
	{
		std::cout << "point use " << std::endl;
		m_ix = ix ;
		m_iy = iy ;
	}
	Point(const Point &rhs)
	{
		std::cout << "point copy use " << std::endl;
		m_ix = rhs.m_ix;
		m_iy = rhs.m_iy;
	}
	void print()
	{
		std::cout << "(" << m_ix << "," << m_iy << ")" <<std::endl;
	}
private:
	int m_ix;
	int m_iy;

};

class Line
{
public:
	Line(int x1 ,int y1, int x2, int y2) : m_pt1(x1,x2),m_pt2(y1,y2)
	{
		std::cout << "line use" << std::endl;
	}
	Line(const Line &rhs) : m_pt1(rhs.m_pt1) , m_pt2(rhs.m_pt2)
	{
		std::cout << "line copy used " << std::endl;
	}
	void draw()
	{
		m_pt1.print();
		std::cout << " to ";
		m_pt2.print();
		std::cout << std::endl;
	}
	Point getPoint1()
	{
		return m_pt1;
	}
private:
	Point m_pt1;
	Point m_pt2;
};
int main()
{
	Line line1(1,2,3,4);
	line1.draw();
	std::cout << std::endl;
	 
	Line line2(line1);
	line2.draw();
	std::cout << "dianuong get Point1() " <<std::endl;
	line2.getPoint1();
	return 0;
}
