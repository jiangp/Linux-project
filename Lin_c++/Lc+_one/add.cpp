/*************************************************************************
	> File Name: add.cpp
	> Author: Arwen
	> Mail:745529725@qq.com 
	> Created Time: Thu 09 Jul 2015 03:28:16 PM CST
 ************************************************************************/

#include<iostream>
//using namespace std;
int add();
int addTheNumber();
int addNumber();
int main(int argc, char* argv[])
{
//	add();
//	addTheNumber();
	addNumber();
	return 0;
}
/*add two number receive the sum
 * */
int add()
{
	int val1, val2;
	std::cout << "Enter tow number: " << std::endl;
	std::cin >> val1 >> val2;
	std::cout << "The sum of " << val1 << " and " << val2 << 
		" is " << val1 + val2 << std::endl;
	return 0;
}

/*add The number os -100 to 100  receive the sum */
int addTheNumber()
{
	int sum = 0;
	for(int i = -100; i <= 100; ++i){
		sum += i;
	}
	std::cout << "The number of -100 to 100 sum is: " << 
		sum << std::endl;
	return 0;
}
/*write a while to cin number not know */
int addNumber()
{
	int val, sum = 0;
	while(std::cout << "input:" , std::cin >> val){
		sum += val;
	}
	std::cout << "The number of value is：" 
		<< sum <<std::endl;
	return 0;
}
