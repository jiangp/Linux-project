/*************************************************************************
	> File Name: Derivedclass.cpp
	> Author: Arwen
	> Mail:745529725@qq.com 
	> Created Time: Wed 18 Mar 2015 09:51:54 PM CST
 ************************************************************************/

#include<iostream>
//using namespace std;
class Baseclass
{
private:
	int a;
public:
	Baseclass(int i){
		std::cout << "Base class " << std::endl;
	}
	//Baseclass(const int a)//1.3
//	{
//		std::cout << " Base value" << std::endl;
//	}
};
#if 0
// 1.
class Derivedclass: public Baseclass
{
public:
	Derivedclass()
	{
		std::cout << "Deried class " << std::endl;
	}
	Derivedclass(const int i)
	{
		std::cout << "constructing" <<std::endl;
	}
};

#endif
// 2.
class Derclass : public Baseclass
{};
#if 0
//3.
class Dclass :public Baseclass
{
public:
	Dclass(int a)
	{
		std::cout << " Declass default" << std::endl;
	}
	Dclass(int x, int y):Baseclass()
	{
		std::cout << "constructing derived " << std::endl;
	}
};
#endif
//4.
class Declass : public Baseclass
{
public:

	Declass(int a) :Baseclass (a)
	{
		std::cout << "from one value" << std::endl;
	}
	Declass(int a, int b) :Baseclass(a)
	{
		std::cout << "from two value " << std::endl;
	}

};
int main()
{
	//1
//  Derivedclass s(5);
//	Derivedclass s2;
	//2
//	Derclass s(2);
//	Derclass s2;
	
	//3
//	Dclass s1(5,6);
//	Dclass s2(7);
	//4
	Declass s(2,3);
	Declass s2(1);
	return 0;
}


