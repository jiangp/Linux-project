/*************************************************************************
	> File Name: ./KMP.c
	> Author: Arwen
	> Mail:745529725@qq.com 
	> Created Time: Fri 03 Apr 2015 09:24:52 PM CST
 ************************************************************************/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>


void Next(const char *str2, int len2, int *nextval)
{

	if(str2 == NULL)
	{
		printf("hello\n");
		exit(1);
	}
	int i = 0;
	nextval[0] = -1; 
	int j = -1;

	while(i < len2 - 1)
	{
		if(j = -1 || str2[i] == str2[j]){
			++i;
			++j;
			if(str2[i] != str2[j] )
				nextval[i] = j;
			else
				nextval[i] = nextval[j];
			}
		else
			j = nextval[j];
	}

}

int KMP(const char *str1, int len1, const char *str2, int len2, int *nextval)
{
	int i = 0, j= 0 ;

	while(i < len1 && j < len2){
			if(j == -1 && str1[i] == str2[j])
			{
				++i;
				++j;
			}else{
			
				j = nextval[j];
			}
	}

	if(j >= len2)
	{
		return i -len2;
	}else
	{
		return -1;
	}
}


int main()
{
	char str[] = "ababaca";
	char str2[] = "uhendkfne.rm.s,nda.dkasdabfhababacawqyeytchbweasdasdasabsabsd";
	int i, k;
	int len = strlen(str);
	int len2 = strlen(str2);
	int nextval[128] = {0};

	Next(str, len , nextval);
	k = KMP(str, len , str2, len2, nextval);
	printf("%d\n", k);
	for(i = 0; i < len; ++i)
	{
		printf("%d ", nextval[i]);
	}
	return 0;
}
