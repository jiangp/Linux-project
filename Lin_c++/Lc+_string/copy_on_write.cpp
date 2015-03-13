/*************************************************************************
	> File Name: copy_on_write.cpp
	> Author: Arwen
	> Mail:745529725@qq.com 
	> Created Time: Thu 12 Mar 2015 02:44:23 PM CST
 ************************************************************************/

#include<iostream>
//using namespace std;
#include<string.h>
class String
{
public:
	String(const char *str);
	String(const String &rhs);
	String &operator=(const String &s);
	~String();
private:
	char *m_str;
};
String::String(const char *str)
{
	if(str == NULL)
	{
		m_str = new char[2];
		m_str[0] = '\0';
		m_str[1] = 1;
	}else
	{
		int len = strlen(str);
		m_str = new char[strlen(str)+2];
		strncpy(m_str, str,len);
		m_str[len + 1] = 1;


	}
}
String::String(const String &rhs)
{
	if(this != &rhs)
	{
		m_str = rhs.m_str;
		int len = strlen(m_str);
		++m_str[len+1];
	}
}
String::&operator=(const String &s)
{
	if(this != &s)
	{
		int len = strlen(m_str);
		--m_str[len + 1];

		m_str = s.m_str;
		len = strlen(m_str);
		++m_str;
	}
	return (*this);
}
String::~String()
{
	int len = strlen(m_str);
	--m_str[len +1];
	if(0 == m_str[len+1])
	{
		delete [] m_str;
	}
}
char &operator[](int idx)
{
	static char ss = '\0';
	int len = strlen[m_str];
	m_str = new char[strlen(m_strlen) + 1];
	if(idx >len || len == 0)
	{
		return ss;
	}
	return m_str[index];

}
int main()
{
	String

	return 0;
}




