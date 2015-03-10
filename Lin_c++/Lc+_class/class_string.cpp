/*************************************************************************
	> File Name: class_string.cpp
	> Author: Arwen
	> Mail:745529725@qq.com 
	> Created Time: Tue 10 Mar 2015 10:46:12 AM CST
 ************************************************************************/

#include<iostream>
//using namespace std;
#include<cstring>
#include<string>

class String
{
public:
	String(const char *str = NULL)  
	{
		m_data = new char[strlen(str)+1];
		strcpy(m_data, str);
		std::cout << "def" <<std::endl;
	}
/*	String(const char *data): m_data(data)
	{
	   std::cout << "构造函数被调用 " << std::endl;
	}*/
	String(const String &rhs)
	{
		std::cout << "复制构造函数被调用" << std::endl;
		m_data = new char[strlen(rhs.m_data)+1];
		strcpy(m_data, rhs.m_data);
	}
	~String(){
		delete m_data;
		m_data = NULL;
	}

    String &operator=(const String &msg)
	{
		if(&msg == this)
		{
			return *this;
		}
		if(m_data)
		{
			delete m_data;
			m_data = NULL;
		}
		m_data = new char[strlen(msg.m_data)+1];
		strcpy(m_data, msg.m_data);  
		std::cout << "operator" << std::endl;
		return *this;
	}
	void print()
	{
		std::cout << "m_data = " << m_data <<std::endl;
	}
private:
	char *m_data;

};
int main()
{
	char name[] = "lilei";
	char name1[] = "li";
	String stu = name;
	String stu1 = stu;
	stu = name1;
	stu.print();
	stu1.print();

	std::cout << std::endl;

	return 0;

}
