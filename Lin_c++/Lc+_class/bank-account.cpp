/*************************************************************************
	> File Name: book-account.cpp
	> Author: Arwen
	> Mail:745529725@qq.com 
	> Created Time: Sun 12 Jul 2015 05:22:15 PM CST
 ************************************************************************/

#include<iostream>
//using namespace std;
#include<string>
#define RATE 0.01

class BookAccount
{
	public:
		BookAccount():m_balance(10), m_year(1){}
		BookAccount(double balance, int year):m_balance(balance), m_year(year)
		{}
		void save(double balance)
		{
			m_balance += balance;
		}
		void fetch(double balance)
		{
			m_balance -= balance;
		}
		void caleTotal()
		{
			m_balance = m_balance * (1 + m_rate);
		}
		void print()
		{
			std::cout << "The totle balance is: " << m_balance << std::endl;
		}
	private:
		std::string m_name[128];
		double m_balance;
		int m_year;
		double m_rate = 0.01;
};


int main(int argc, char **argv)
{
	BookAccount tom(1000, 3);
	tom.save(2000);
	tom.caleTotal();
	tom.print();
	return 0;
}
