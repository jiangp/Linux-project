/*************************************************************************
	> File Name: String.cpp
	> Author: Arwen
	> Mail:745529725@qq.com 
	> Created Time: Wed 11 Mar 2015 08:47:49 PM CST
 ************************************************************************/

#include<iostream>
#include<string.h>
#include<stdio.h>
//using namespace std;
class string
{
public:
	string(){
		m_str = new char[1];
		m_str[0] = '\0';
	}
	string(const char* vec_str)
	{
		m_str = new char[strlen(vec_str) + 1];
		strcpy(m_str, vec_str);
	}
	string(const string &cp)
	{
		m_str = new char[strlen(cp.m_str)+1];
		//m_str = cp.m_str;
		strcpy(m_str, cp.m_str);
	}
	~string(){
		std::cout << " qq " <<std::endl;
		delete [] m_str;
		m_str = NULL;
	}

	char *c_str()
	{
		return m_str;
	}

	//=
  string &operator=(const string &cp)
	{
		if(this == &cp)
			return (*this);
		delete [] m_str;
		m_str = new char[strlen(cp.m_str) + 1];
		if(m_str != NULL)
		{
			strcpy(m_str, cp.m_str);
		}
		return (*this);
	}
	string &operator=(const char *cp)
	{
		if(NULL == cp)
			return (*this);
		m_str = new char[strlen(cp) + 1];
		if(m_str != NULL)
		{
			strcpy(m_str,cp);
		}
		return (*this);
	}
	//+=
    string &operator+=(const string &add)
	{
		if(this == &add)
			return (*this);
		char *k = new char[strlen(m_str) + strlen(add.m_str) + 1];
		strcpy(k, m_str);
		strcat(k, add.m_str);
		delete [] m_str;
		m_str = k;
		k = NULL;		
		return (*this);
	}
	string &operator+=(const char *add)
	{
		char *k = new char[strlen(m_str) + strlen(add) + 1];
		strcpy(k, m_str);
		strcat(k,add);
		delete [] m_str;
		m_str = k;
		k = NULL;
		return (*this);
	}
//[]
	char &operator[](std::size_t index)
	{
		static char size ='\0';
		if(index <strlen(m_str) && index>=0)
		{
			return m_str[index];
		}else
		{
			std::cout << "error !" << std::endl;
			return size;
		}
	}
	const char &operator[](std::size_t index) const
	{
		static char size ='\0';
		if(index <strlen(m_str) && index>=0)
		{
			return m_str[index];
		}else
		{
			std::cout << "error !" << std::endl;
			return size;
		}
	}
	//()
	std::size_t size() const
	{
		return strlen(m_str);
	}
	const char* c_str() const
	{
		return m_str;
	}
	//+
	friend string operator+(const string &str1,const string &str2)
	{
		string res;
		res.m_str = new char[strlen(str1.m_str) + strlen(str2.m_str) + 1];
		strcpy(res.m_str,str1.m_str);
		strcat(res.m_str,str2.m_str);
		return res;
	}
	friend string operator+(const string &str1,const char *str2)
	{
		string res1;
		res1.m_str = new char[strlen(str1.m_str) + strlen(str2) + 1];
		strcpy(res1.m_str, str1.m_str);
		strcat(res1.m_str, str2);
		return res1;
	}
	friend string operator+(const char *str1, const string &str2)
	{
		string res2;
		res2.m_str = new char[strlen(str2.m_str) + strlen(str1) + 1];
		strcpy(res2.m_str, str1);
		strcat(res2.m_str, str2.m_str);
		return res2;
	}
	//==
	friend bool operator==(const string &s1,const string &s2)
	{
		if(strcmp(s1.m_str,s2.m_str) == 0)
		{
			return true;
		}else
		{
			return false;
		}
	}
	//!=
	friend bool operator!=(const string &s1, const string &s2)
	{
		if(strcmp(s1.m_str,s2.m_str) == 0)
		{
			return false;
		}else
		{
			return true;
		}

	}
	//<
	friend bool operator<(const string &s1, const string &s2)
	{
		if(strcmp(s1.m_str,s2.m_str) < 0)
		{
			return true;
		}else
		{
			return false;
		}
	}
	//>
	friend bool operator>(const string &s1,const string &s2)
	{
		if(strcmp(s1.m_str,s2.m_str) > 0)
		{
			return true;
		}else
		{
			return false;
		}
	}
	//<=
	friend bool operator<=(const string &s1,const string &s2)
	{
		if(strcmp(s1.m_str,s2.m_str) <= 0)
		{
			return true;
		}else
		{
			return false;
		}
	}
	//>=
	friend bool operator>=(const string &s1,const string &s2)
	{
		if(strcmp(s1.m_str,s2.m_str) >= 0)
		{
			return true;
		}else
		{
			return false;
		}
	}
	//>>
    friend std::istream &operator>>(std::istream &is, const string &s)
	{
		is >>s.m_str;
	}
	//<<
	friend std::ostream &operator<<(std::ostream &os, const string &s)
	{
		os << s.m_str;
	}
	
	void print()
	{
		std::cout << m_str << std::endl;
	}
private:
	char *m_str;	
};

int main()
{
    string str = "hello";
//	string str2 = "word";
//	string str3(str);
	string str2;
	str2 = str + "a";
	str2.print();
//    str3.print();
//	printf("str's address:%x\n", str.c_str());
//	printf("str3's address:%x\n", str3.c_str());

//	string str3;
//	std::cin >> str3;
//	std::cout << sizeof(str) << std::endl;
//	if(str >= str2)
//	{
//		std::cout << "true" << std::endl;
//	}else
//	{
//		std::cout << "flase" <<std::endl;
//	}
//	std::cout << str[1] <<std::endl;
//  str3 += "hello";
//	str3 = "hello";
//	str3 = str + str2;
//	str3 = "word" + str2;
//	str3 = str + "hello";
//	std::cout << str3.size() << std::endl;
	//std::cout << str3 <<std::endl;
	return 0;
}
