/*************************************************************************
	> File Name: Algorithm.cpp
	> Author: Arwen
	> Mail:745529725@qq.com 
	> Created Time: Tue 17 Mar 2015 04:16:51 PM CST
 ************************************************************************/

#include<iostream>
//using namespace std;
#include<algorithm>
#include<string>
#include<vector>
std::string make_plural(size_t ctr, const std::string &word, const std::string &ending)
{
	return (ctr == 1) ? word :word + ending;
}


	bool isShorter(const std::string &s1, const std::string &s2)
	{
		return (s1.size() <s2.size());
	}
	bool GT6(const std::string &s)
	{
		return s.size() >= 6;
	}
int main()
{
	 std::vector<std::string> word_space;
	 std::string word;
	 while(std::cin >> word){
		 word_space.push_back(word);
	 }

	 sort(word_space.begin(), word_space.end());

	 std::vector<std::string>::iterator end_unique = unique(word_space.begin(), word_space.end());
	 word_space.erase(end_unique, word_space.end());
	 stable_sort(word_space.begin(), word_space.end(), isShorter);
	 std::vector<std::string>::size_type wc = count_if(word_space.begin(),word_space.end(), GT6);
	 std::cout << " " <<make_plural(wc, "word", "s") << " 6 char or longer" <<std::endl;
	return 0;
}
