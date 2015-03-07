/*************************************************************************
	> File Name: char_pointc.cpp
	> Author: Arwen
	> Mail:745529725@qq.com 
	> Created Time: Sat 07 Mar 2015 08:27:14 PM CST
 ************************************************************************/

#include<iostream>
//using namespace std;
#include<cstring>
#include<string>
int main()
{
    const char *p = "i am super man !";
	const char *q = "i am good!";
	char ca[] = {'C','+'};

/*	int *psa = new int[10];//[10]();const must init ()
*	const std::string *pcs = new const std::string[10];//not need
*	delete [] psa;
*	delete [] pcs;
*/
//	char largestr[16];//careful  the size
//	strcpy(largestr, p);
	//std::cout << strlen(largestr) <<std::endl;
//	strcat(largestr, "sdfsd");
//	std::cout << strlen(largestr) <<std::endl;
//	strcat(largestr, q);
//	std::cout << strlen(largestr) <<std::endl;
//	int i = strcmp(p,p);
//	std::cout << largestr << std::endl;
//	std::cout << strlen(*p) << std::endl;//error *p
	while(*p)
	{
		std::cout << *p << std::endl;
		++p;
	}

	return 0;
}
