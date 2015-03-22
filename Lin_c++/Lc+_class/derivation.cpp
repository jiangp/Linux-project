/*************************************************************************
	> File Name: derivation.cpp
	> Author: Arwen
	> Mail:745529725@qq.com 
	> Created Time: Wed 18 Mar 2015 03:27:02 PM CST
 ************************************************************************/

#include<iostream>
//using namespace std;
class Line;

class Point 
{
private:
	int m_x;
	int m_y;
protected:
	int m_mi;
public:
	friend Line;
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
	void print()//chen yuan hanshu fu gai
	{
		std::cout << "(" << getx() << gety() << m_zi << ")" << std::endl;
	}
	int CalcSum()
	{
		return getx() + gety() + m_zi;
	}
public:
	int m_zi;
};
class Line 
{
public:
	Line(int x1 = 0, int y1 = 0, int z1 = 0, int x2 = 0, int y2 = 0, int z2 = 0) 
		: m_pt3(x1, y1),
		  m_pt3d1(x1, y1, z1),
		  m_pt3d2(x2, y2, z2)
	{}
	void setPoint(int x, int y)
	{
		m_pt3.m_x = x;
		m_pt3.m_y = y;
	}

	void setPoint3D(int x, int y, int z)
	{
		m_pt3d1.m_x = x;
		m_pt3d1.m_y = y;
		m_pt3d1.m_zi = z;
	}

	void print() 
	{
		m_pt3d1.print();
		m_pt3d2.print();
		m_pt3.print();
	}
private:
	Point3D m_pt3d1;
	Point3D m_pt3d2;
	Point m_pt3;

};
int main()
{
	std::cout << "Point's size : " << sizeof(Point) << std::endl;
	std::cout << "Point3D's size : " << sizeof(Point) << std::endl;
	Point x = (7,9);
	x.print();

	Point3D z(3,4,5);
	z.print();

//	z.m_mi = 30;

	int res = z.CalcSum();
	std::cout << res << std::endl;

	Line line(1,2,3,4,5,6);
	line.print();
	line.setPoint(10,11);
	line.print();
	line.setPoint3D(15,16,17);
//	line.print();

	return 0;
}
