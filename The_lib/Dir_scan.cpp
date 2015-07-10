/*************************************************************************
	> File Name: Dir_scan.cpp
	> Author: Arwen
	> Mail:745529725@qq.com 
	> Created Time: Fri 10 Jul 2015 10:55:54 AM CST
 ************************************************************************/

#include<iostream>
#include<algorithm>
#include<dirent.h>
#include<fstream>
#include<functional>
#include<stdio.h>
#include<stdlib.h>
#include<set>
#include<stdexcept>
#include<sys/types.h>
#include<sys/stat.h>
#include<string.h>
#include<map>
#include<vector>
#include<unistd.h>
#include<utility>

//using namespace std;

//扫描目录类，该类扫描指定目录下的项并将属于普通文件的项的绝对路径保存下来。
class DirScan
{
	public:
		DirScan(std::vector<std::string>& vec):m_vec(vec) {}
		void operator()(const std::string &dir_name)
		{
			traverse(dir_name);
		}
		void traverse(const std::string& dir_name)
		{
			DIR* pdir =opendir(dir_name.c_str());
			chdir(dir_name.c_str());
			struct dirent* mydirent;
			struct stat mystat;
			while((mydirent = readdir(pdir)) != NULL){
				stat(mydirent->d_name, &mystat);
				if(S_ISDIR(mystat.st_mode)){
					if(strncmp(mydirent->d_name, ".", 1) == 0|\
							strncmp(mydirent->d_name, "..", 2) == 0){
						continue;
					}
					else{
						traverse(mydirent->d_name);
					}
				}
				else{
					std::string file_name = "";
					file_name = file_name + getcwd(NULL, 0) +\
								"/" + mydirent->d_name;
					m_vec.push_back(file_name);
				}
			}
			chdir("..");
			closedir(pdir);
		}
	private:
		std::vector<std::string>& m_vec;
};



//文件处理类，该类将多个文件已某种格式格式化文件并将各个文件统一保存到一个文件形成网页库文件。
//每个文件被处理成<doc><docid>id</docid><doctitle>title</doctitle><docurl>url</docurl><doccontent>content</doccontent></doc>
class FileProcess
{
	public:
		FileProcess(std::vector<std::string>& vec,\
				std::string & str): m_vec(vec)
		{
			m_title = str;
		}
		void operator()(const std::string& file_name, const std::string& offset_file)
		{
			do_some(file_name, offset_file);
		}
		void do_some(const std::string& file_name, const std::string& offset_file)
		{
			FILE* fp = fopen(file_name.c_str(), "w");
			FILE* fp_offset = fopen(offset_file.c_str(), "w");
			if(fp == NULL || fp_offset == NULL){
				std::cout << "file open" <<std::endl;
				exit(0);
			}
			int index;
			char* mytxt = new char[1024*1024]();
			int mydocid;
			char myurl[256] = "";
			char* myconnect = new char[1024 *1024]();
			char* mytitle = new char[1024]();
			
			for(index = 0; index != m_vec.size(); ++index){
				memset(mytxt, 0, 1024*1024);
				memset(myurl, 0, 256);
				memset(myconnect, 0, 1024*1024);
				memset(mytitle, 0, 1024);
				FILE* fp_file = fopen(m_vec[index].c_str(), "r");
				read_file(fp_file, myconnect, mytitle);
				fclose(fp_file);
				mydocid = index + 1;
				strncpy(myurl, m_vec[index].c_str(), m_vec[index].size());
				sprintf(mytxt,"<doc><docid>%d</docid><docurl>%s</docurl><doctitle>%s</doctitle><doccontent>%s</doccontent></doc>\n", mydocid, myurl, mytitle, myconnect);
				int myoffset = ftell(fp);
				int mysize = strlen(mytxt);
				char offset_buf[128] = "";
				fprintf(fp_offset, "%d\t%d\t%d\n", mydocid, myoffset, mysize);
				write_to_file(fp, mytxt);
			}
			fclose(fp);
		}


		void read_file(FILE* fp, char* myconnect, char* mytitle)
		{
			int iret;
			const int size = 1024 * 1024;
			char* line = new char[1024]();
			int pos = 0;
			while(1){
				int iret = fread(myconnect + pos, 1, size - pos, fp);
				if(iret == 0){
					break;
				}
				else{
					pos +=iret;
				}
			}
			rewind(fp);
			int count = 0, flag = 0;
			while(count <= 10 && fgets(line, 512, fp) != NULL){
				std::string str_line(line);

				if(str_line.find("标  题") != std::string::npos){
					strncpy(mytitle, str_line.c_str(), str_line.size());
					flag = 1;
					break;
				}
				++count;
			}
			if(count < 11 && flag == 0){
				rewind(fp);
				fgets(mytitle, 1024, fp);
			}
			else if(count == 11 && flag == 0){
				fgets(mytitle, 1024, fp);
			}
		}




		//将格式化后的文档写到网页库文件中
		void write_to_file(FILE* fp, char* mytxt)
		{
			int iret, pos = 0;
			int len = strlen(mytxt);
			while(1){
				iret = fwrite(mytxt + pos, 1, len - pos, fp);
				len = len - iret;
				if(len == 0){
					break;
				}
			}
		}

	private:
		std::vector<std::string>& m_vec;
		std::string m_title; 
		std::map<int, std::pair<int, int> > m_offset;
};



int main(int argc, char **argv)
{
	std::vector<std::string> str_vec;
	DirScan mydirscan(str_vec);
	mydirscan(argv[1]);
	
	std::cout << str_vec.size() << std::endl;
	std::string title;
	std::cin >> title;
	std::cout << title << std::endl;
	FileProcess myfileprocess(str_vec, title);
	myfileprocess(argv[2], argv[3]);
	std::cout << "over" << std::endl;
	return 0;
}
