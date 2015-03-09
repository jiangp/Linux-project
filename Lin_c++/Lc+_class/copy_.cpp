/*************************************************************************
	> File Name: copy_.cpp
	> Author: Arwen
	> Mail:745529725@qq.com 
	> Created Time: Mon 09 Mar 2015 10:06:42 AM CST
 ************************************************************************/

#include<iostream>
//using namespace std;
class C
{
public:
	computer(const)
	{

	}
	computer &operator= (const computer &rhs)
	{
		if(this == &rhs)
			return (*this);
		if(psBrand_){
			delete [] psBrand_;
			psBrand_ = NULL;
		}//防止内存泄露
		psBrand_ = new char[strlen(rhs.psBrand_)+1];
		if(NULL == psBrand_){
			std::cout << "memory allocated fail" <<std::endl;
			return NULL;
		}
		strcpy(psBrand_ , rhs.psBrand_);
		fPrice_ = rhs.fPrice_;
		std::cout << "diaoyong " << std::endl;
	}
	~computer()
	{
		delete[] psBrand_;
		psBrand_ = NULL;
		std::cout << "clear " <<std::endl;
	}
private:
	imt price_;
};
int main()
{
	computer pc3;
	pc3 = pc2;
	std::cout << "pc3: " << std::endl;
	pc3.print(pc3);
	return 0;
}
