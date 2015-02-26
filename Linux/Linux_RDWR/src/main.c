/*************************************************************************
	> File Name: ./src/main.c
	> Author: Arwen
	> Mail:745529725@qq.com 
	> Created Time: Mon 26 Jan 2015 08:49:45 PM CST
 ************************************************************************/

#include<chang.h>
int main(int argc,char *argv [] )
{
	char s[80];
	char s1[80];
	char s2[80];
	int i,n=0;
	printf("please input s :\n");
	gets(s);
	printf("please input s1 :\n");
	gets(s1);
	printf("please input s2 :\n");
	gets(s2);
	for(i=0;i<strlen(s);i++)
	{
		for(n=0;n<strlen(s1);n++)
		{
		     if(s[i]==s1[n])
			 {
				 s[i]=s2[n];
			 }
		}
	}
	puts(s);
	system("pause");
	return 0;
}

