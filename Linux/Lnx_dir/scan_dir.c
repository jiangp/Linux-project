/*************************************************************************
	> File Name: scan_dir.c
	> Author: Arwen
	> Mail:745529725@qq.com 
	> Created Time: Thu 26 Feb 2015 02:29:43 PM CST
 ************************************************************************/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<sys/types.h>
#include<dirent.h>
#include<sys/stat.h>
#include<unistd.h>
void scan_dir(char* dir, int num);
int main(int argc, char* argv[])
{
	scan_dir(argv[1], 1);
	return 0;
}
void scan_dir(char* dir, int num)
{
	DIR *pdir = opendir(dir);
	char name[128] = "0";
	if(pdir == NULL)
	{
		perror("opendir\n");
		exit(1);
	}
	struct dirent* pent;
	struct stat mystat;
	while((pent = readdir(pdir)) != NULL)
	{
		if(strcmp(".",pent->d_name) == 0||strcmp("..",pent->d_name) == 0)
		{
			continue;
		}

		memset(name, 0, 128);
		sprintf(name, "%s/%s", dir, pent->d_name);
        memset(&mystat, 0, sizeof(mystat));

		if(lstat(name, &mystat) == -1)
		{
			perror("error");
			exit(1);
		} 

		if(S_ISDIR(mystat.st_mode))
		{
			scan_dir(name, num + 5 );
		}else
		{
			printf("%*s%s\n", num, " ", pent->d_name);
		}
	}
	closedir(pdir);
	
}
