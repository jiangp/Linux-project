/*************************************************************************
	> File Name: smart_point.cpp
	> Author: Arwen
	> Mail:745529725@qq.com 
	> Created Time: Tue 17 Mar 2015 03:06:40 PM CST
 ************************************************************************/

#include<iostream>
//using namespace std::
class RAII
{
public:
	explicit RAII(T* p): m_p(p){}

	~RAII()
	{
		delete m_p;
	}
	void reset(T* p)
	{
		delete m_p;
		m_p = p;
	}
	T *get()const{
		return m_p;
	}
	T &operator*()const{
		return *m_p;
	}
	void swap(RAII & other){
		std::swap(m_p, other.m_p);
	}
private:
	RAII(const RAII& other);
	RAII &operator=(const RAII &other);
private:
	T* m_p;
};
