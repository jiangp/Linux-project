/*************************************************************************
	> File Name: virtual.cpp
	> Author: Arwen
	> Mail:745529725@qq.com 
	> Created Time: Thu 19 Mar 2015 04:22:45 PM CST
 ************************************************************************/

#include<iostream>
//using namespace std;
#include<string>
class Base
{
public:
	virtual
	void print()
	{
		std::cout << "base's virtual" <<std::endl;
	}
};

class child1 : public Base
{
public:
	void print()
	{
		std::cout << "chaild1's virtual " <<std::endl;
	}
};

class child2 : public Base
{
public:
	void print()
	{
		std::cout << " child2's virtual" <<std::endl;
	}
};
void display(Base *pb)
{
	pb->print();
}

int main()
{
	Base *pBase = NULL, obj_base;
	obj_base.print();

	pBase = &obj_base;
	pBase->print();
	std::cout <<std::endl;
	std::cout <<std::endl;
	std::cout <<std::endl;
	//child1
	child1 *pChild1 = NULL, obj_child1;
	obj_child1.print();
	pChild1 = &obj_child1;
	pChild1->print();
	std::cout <<std::endl;
	std::cout <<std::endl;
	std::cout <<std::endl;
	//child2
	child2 *pChild2 = NULL, obj_child2;
	obj_child2.print();
	pChild2 = &obj_child2;
	pChild2->print();

	 //test virtual
//	pBase = &obj_child1;
//	pBase->print();
	
	std::cout <<std::endl;
	std::cout <<std::endl;
	//display
	display(&obj_base);
	display(&obj_child1);
	display(&obj_child2);
	//
	std::cout <<std::endl;
	(*pBase).print();

	return 0;
}
