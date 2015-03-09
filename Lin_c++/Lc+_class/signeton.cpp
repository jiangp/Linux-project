/*************************************************************************
	> File Name: signeton.cpp
	> Author: Arwen
	> Mail:745529725@qq.com 
	> Created Time: Mon 09 Mar 2015 10:28:33 PM CST
 ************************************************************************/

#include<iostream>
//using namespace std;
class Singleton 
{
public:
	static Singleton* createinstance()
	{
		if(NULL == pInstance)
		{
			pInstance = new Singleton ;
		}
		return pInstance;
	}
private:
	Singleton()
	{
		std::cout << "gouzhaohanshu bei zhixing " << std::endl;
	}
	static Singleton *pInstance;
};
Singleton* Singleton::pInstance = NULL;
int main()
{
	Singleton *pInstance = Singleton::createinstance();
	Singleton *pInstance2 = Singleton::createinstance();
	std::cout << "pinstance = " << pInstance << std::endl;
	std::cout << "pinstance2 = " << pInstance2 << std::endl;

	return 0;
}
