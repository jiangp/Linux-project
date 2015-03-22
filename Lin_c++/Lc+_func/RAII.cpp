/*************************************************************************
	> File Name: RAII.cpp
	> Author: Arwen
	> Mail:745529725@qq.com 
	> Created Time: Tue 17 Mar 2015 10:14:18 AM CST
 ************************************************************************/

#include<iostream>
//using namespace std;
#include<string>
#include<stdexcept>
#include<stdio.h>
class SafeFile
{
public:
	SafeFile(const char *filename)
		:fileHandler(fopen(filename, "w+"))
	{
		if(NULL == fileHandler)
		{
			std::cout << "file open fail" << std::endl;
		}
	}
	~SafeFile() {fclose(fileHandler);}

	void write(const char *str)
	{
		if(fputs(str, fileHandler) == EOF)
		{
			throw std::runtime_error("Write Error");
		}
	}
	void write(const char *str , size_t num)
	{
		if(num !=0 && fwrite(str, num, 1, fileHandler) == 0)
		{
			throw std::runtime_error("Write Error!");
		}
	}
private:
	SafeFile(const SafeFile &);
	SafeFile &operator=(const SafeFile &);
private:
	FILE *fileHandler;
};

int main()
{
	SafeFile testVar("1.txt");
	testVar.write("Hello RAII");
	return 0;
}
