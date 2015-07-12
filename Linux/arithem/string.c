/*************************************************************************
  > File Name: string.c
  > Author: Arwen
  > Mail:745529725@qq.com 
  > Created Time: Sat 07 Mar 2015 09:38:26 AM CST
 ************************************************************************/

#include<stdio.h>
#include<string.h>
int  search(char *name ,char *same) ;
int stringval(char *str);
int main()
{
	int nul;
//	char name[] ="ddggdasdmdanfkala,msldmfmasldmfnasnasdnkfbka,sndna,sdsdfnasdfa";
//	char same[] ="nasd";
	char name[] ={'7','6','1','2','2','\0'};
	//    int num = sizeof(same);
	int num = strlen(name);
	printf("%d\n",num);
//	search(name,same);
    nul = stringval(name);
	printf("%d\n",nul);
}
//查找字符串  朴素算法 o(m-n)m
int  search(char *name ,char *same) 
{
	int i,j,k =0;
	for(i = 0; i < strlen(name); i++)
	{
		k=0;
		for(j = 0; j < strlen(same); j++)
		{
			if(name[i+k] != same[j])
			{
				break;
			}
			else{
				k++;
			}
		}		
		if(k == strlen(same))
		{
			printf("%d :%s\n",i,same);
		}
	}
	return 0;
}

//KMP 
int KMP(char *name, char *same)
{
	if(name ==NULL || same ==NULL)
	{
		return ERROR;
	}
	int i;
	int j;
	int nlen = strlen(name);
	int slen = strlen(same);
	int next[slen];

	Long(name, next);

	while(i < nlen && j < slen)
	{
		if(j == -1 || name[i] == same[j])
		{
			i++;
			j++;
		}else
		{
			i = next[j];
		}
	}
	if(j == slen)
	{
		return i-j;

	}else
	{
		return ERROR;
	}
	
}
//KMP same Assignment
int Long(char *same , int next[])
{
	if(name == NULL || next == NULL)
	{
		rerurn ERROR;
	}
	int slen = strlen(same);
	next(0) = -1;
	int k = -1;
	int j = 0;
	while(i < slen - 1)
	{
		if(k == -1 || same[j] == same[k])
		{
			++j;
			++k;
			if(same[j] != same[k])
			{
				next[j] = k;
			}else
			{
				next[j] = next[k];
			}
		}else
		{
			k = next[k];
		}
	}	                                             
   return OK;
}

//string  return val
int stringval(char *str)
{
	if(str == NULL)
	{
		return -1 ;
	}
	int len = strlen(str);
	int sum = 0;
	int base = 10;
	int i;
	for(i = 0; i < len; ++i)
	{
		if(str[i] == '-')
		{
			continue ;
		}
		if(str[i]>='0'&&str[i]<='9')
		{
			sum = sum*base +(str[i]-'0');
			if(sum > 0x7ffffffff)
			{
				return -1;
			}

		}else
		{
			return -1;
		}
	}
	if(str[0] =='-')
    	sum = -sum;
	return sum;
}
//val return  string
int valstring(unsigned long val, char* str)
{

	return 0;

}
//出现最多字符串查找
int searchstring(char *str,char *s)
{
	int i k,max = 0;
	int len = strlen(str);
	for(i = 1; i <= len ; i++)
	{
		for(n = 1; n < len; n++)
		{
		for(j = n;j < len; j++)
		{
			if(str[j+i] == NULL)
			{
				max > k ? max : k;
			}
			if(str[j] == str[j+i])
			{
				k++;
			}else
			{
				if(max >k)
				max>k ? max : k ;

			}
		}
		}
		
	}
}
//LCS
int search_scl(char *src ,char *str)
{


}

//move Arithem
bool ismove(char *src, char *des)
{
	if(src == NULL || des == NULl)
	{
		return false;
	}
	int i ;
	int slen = strlen(src);
	int newsrclen = 2*len;
	char newsrc[newsrclen];
	for(i = 0; i < slen; i++)
	{
		newsrc[i] = src[i];
		newsrc[i + slen] = src[i];
		
	}
	int index = KMP(newsrc, des);
	if(index != ERROR)
		return true;
	return false;
}
//统计字符串中字符出现的次数
char timechar(char *str,char *c)
{
	if(str == NULL)
	  return 0;
	int Map[26] ={0};
	int i,max = 0 ;
	for(i=0; i<= strlen(str); i++)
	{
		Map[str[i]-'a']++;
	}
	for(i=0;i<26;i++)
	{
		max>Map[i]?max:Map[i];
	}
	return ('a'+i);
	
}
