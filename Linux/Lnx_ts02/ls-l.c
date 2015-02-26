/*************************************************************************
	> File Name: 1.c
	> Author: Arwen
	> Mail:745529725@qq.com 
	> Created Time: Tue 27 Jan 2015 11:15:58 AM CST
 ************************************************************************/
#include<stdio.h>
#include<stdlib.h>
#include<sys/stat.h>
#include<sys/types.h>
#include<fcntl.h>
#include<unistd.h>
#include<string.h>
#include<grp.h>
#include<pwd.h>
#include<time.h>
void mode_to_str(mode_t md,char* buf);
int main()
{
	struct stat my_stat;
	memset(&my_stat,0,sizeof(my_stat));
	char buf[11];
	if(-1==stat("./2.c",&my_stat))
	{
		printf("error !");
		exit (1);
	}
//	printf("mode:%04x link:%u uid:%u gid%u size:%u mtime:%u ",my_stat.st_mode,my_stat.st_nlink,my_stat.st_uid,my_stat.st_gid,my_stat.st_size,my_stat.st_mtime);
	mode_to_str(my_stat.st_mode,buf);
//  puts(buf);
     printf("%s  ",buf);
	printf("%s %s ",getpwuid(my_stat.st_uid) ->pw_name,getgrgid(my_stat.st_gid)->gr_name);
    printf("%s ",ctime(&my_stat.st_mtime));
	return 0;
}
void mode_to_str(mode_t md,char* buf)
{
	if(S_ISREG(md))
	{
		buf[0] ='-';
	}
	else if(S_ISDIR(md))
	{
		buf[0] ='d';
	}
	else if(S_ISCHR(md))
	{
		buf[ 0] ='c';
	}
	else if(S_ISBLK(md))
	{
		buf[0] ='b';
	}
	else if(S_ISFIFO(md))
	{
		buf[ 0]='p';
	}
	else if(S_ISLNK(md))
	{
		buf[ 0]= 'l';
	}
	else 
	{
        buf[0 ]='s';
	}
	if(md &S_IRUSR)
	{
		buf[1 ]='r';
	}else
	{
		buf[ 1]='-';
	}
	if(md &S_IWUSR)
	{
	    buf[ 2]='w';
	}else
	{
		buf[ 2]= '-';
	}

	if(md &S_IXUSR)
	{
		buf[ 3]= 'x';
	}
	else
	{
       buf [ 3]= '-';
	}

	if(md &S_IRGRP)
	{
		buf[4 ]='r';
	}else
	{
		buf[ 4]='-';
	}
	if(md &S_IWGRP)
	{
	    buf[ 5]='w';
	}else
	{
		buf[ 5]= '-';
	}

	if(md &S_IXGRP)
	{
		buf[ 6]= 'x';
	}
	else
	{
       buf [ 6]= '-';
	}

	if(md &S_IROTH)
	{
		buf[7]='r';
	}else
	{
		buf[ 7]='-';
	}
	if(md &S_IWOTH)
	{
	  buf[ 8]='w';
	}else
	{
		buf[ 8]= '-';
	}

	if(md &S_IXOTH)
	{
		buf[ 9]= 'x';
	}
	else
	{
       buf [ 9]= '-';
	}
	buf[ 10]=0;
}
