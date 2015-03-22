/*************************************************************************
	> File Name: class_wd_search.cpp
	> Author: Arwen
	> Mail:745529725@qq.com 
	> Created Time: Mon 16 Mar 2015 11:10:36 AM CST
 ************************************************************************/

#include<iostream>
//using namespace std;
#include<string>
#include<fstream>
#include<sstream>
#include<vector>
#include<stdexcept>
#include<stdlib.h>
#include<stdio.h>
#include<map>
#include<set>


class TextQuery
{
public:
	typedef std::vector<std::string>::size_type line_no;
	void read_file(std::ifstream &is)
		{store_file(is); build_map();}
	std::set<line_no> run_query(const std::string&) const;//
	std::string text_line(line_no) const;//
private:
	void store_file(std::ifstream&);
	void build_map();
	std::vector<std::string>line_of_text;
	std::map<std::string, std::set<line_no> > word_map;
};





void TextQuery::store_file(std::ifstream &is)
{
	std::string textline;
	while(getline(is, textline))//line store
		line_of_text.push_back(textline);
}




void TextQuery::build_map()
{
	for(line_no line_num = 0; line_num != line_of_text.size(); ++line_num)
	{
		std::stringstream line(line_of_text[line_num]);
		std::string word;
		while(line >> word)
		{
			word_map[word].insert(line_num);//word store
		}
	}
}




std::set<TextQuery::line_no> TextQuery::run_query(const std::string &query_word) const
{
	std::map<std::string, std::set<TextQuery::line_no> >::const_iterator loc = word_map.find(query_word);
	if(loc == word_map.end())
		return std::set<TextQuery::line_no>();
	else
		return loc->second;
}




std::string make_plural(size_t ctr, const std::string &word, const std::string &ending)
{
	return (ctr == 1) ? word : word + ending;
}




std::string TextQuery::text_line(line_no line) const
{
	if(line < line_of_text.size())
		return line_of_text[line];
	throw std::out_of_range("line number out of range");
}



void print_result(const std::set<TextQuery::line_no> &locs, const std::string &sought, const TextQuery &file)
{
	typedef std::set<TextQuery::line_no> line_nums;
	line_nums::size_type size = locs.size();
	std::cout << "\n" << sought <<" occurs " 
		      << size << " "
			  << make_plural(size, "time" , "s") << std::endl;
	line_nums::const_iterator it = locs.begin();
	for(; it != locs.end(); ++it)
	{
		std::cout << "\t (line" 
			      << (*it) + 1 << ") "
				  <<file.text_line(*it) << std::endl;
	}
}






std::ifstream& open_file(std::ifstream &in , const std::string &file)
{
	in.close();
	in.clear();
	in.open(file.c_str());
	return in;
}







int main(int argc, char **argv)
{
	std::ifstream infile;
	if(argc < 2 || !open_file(infile,argv[1]))
	{ 
		std::cerr << "No input file !" << std::endl;
		return EXIT_FAILURE;
	}
	TextQuery tq;
	tq.read_file(infile);
	while(true)
	{
		std::cout << "Enter word to look for, or enter q to erxt: " << std::endl;
		std::string s;
		std::cin >> s;
		if(!std::cin || s == "q")
			break;
		std::set<TextQuery::line_no> locs = tq.run_query(s);
		print_result(locs, s , tq);
	}
	return 0;
}

