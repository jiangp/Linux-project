/*************************************************************************
	> File Name: class_create.cpp
	> Author: Arwen
	> Mail:745529725@qq.com 
	> Created Time: Mon 09 Mar 2015 03:23:56 PM CST
 ************************************************************************/

#include<iostream>
#include<cstring>

//using namespace std;
/*
class Sales_item{
public:
	double avg_price() const;
	bool same_isbn(const Sale_item &rhs) const
	{
		return isbn == rhs.isbn;
	}
	Sales_item() : units_sold(0),revenue(0.0){}//constructor 构造函数
private:
	std::string isbn;
	unsigned units_sold;
	double revenue;
};
double Sales_item::avg_price() const
{
	if(units_sold)
		return revenue/units_sold ;
	else
		return 0;
}
*/

/*
class Screen {
public:
      typedef std::string::size_type index;
	  char get() const { return contents[cursor];}
	  inline char get(index ht, index wd) const;
	  index get_cursor() const ;
private:
	  std::

};
char Screen::get(index r, index c) const
{
	index row = r * width;
	return contents[row +c];
}
inline char Screen::index Screen::get_cursor() const
{
	return cursor
}

*/

class Student
{
public:
	char m_name[10];
	int m_id;
public:
	Student()
	{
		std::cout << "gouzhao hanshu " << std::endl;
	}
	~Student()
	{
		std::cout << "xigou hanshu " << std::endl;
	}
private:
	//static void* operator new (std::size_t nSize);
   // static void operator delete(void *pVoid);

	/*static void* operator new(std::size_t nSize)
	{
		std::cout << "new use size = " << nSize << std::endl;
	//	void *pRet = new char[nSize];
		void *pRet = malloc(nSize);
		return pRet;
	}
	static void operator delete(void *pVoid)
	{
		std::cout << "delete caozuofu ." << std::endl;
		free(pVoid) ;
	}*/

};
class Teacher
{

};

int main(void)
{
	Student *pstu = new Student;
	pstu->m_id = 101;
	strcpy(pstu->m_name,"tony");
	std::cout << std::endl;
	delete pstu;
//	pstu->destroy();
	return 0;
}
