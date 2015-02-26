/*************************************************************************
	> File Name: 012603.c
	> Author: Arwen
	> Mail:745529725@qq.com 
	> Created Time: Mon 26 Jan 2015 10:24:01 AM CST
 ************************************************************************/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int main()
{
	int i,j=0,n=0,emp=0;
	int k,bg,end;
	char arr[80];
	printf("is a tepyset proplem !\n");
	printf("piease input chars :\n");
	gets(arr);
	for(i=0;i<strlen(arr);i++)
	{
		if(arr[i ]==' ')
		{
			j++;
		}
		if(arr[ i]=='\t')
		{
			j=j+8;
		}
		if(arr[i]!=' '&&arr[i+1]==' '||arr[i]!=' '&&arr[i+1]=='\0')
		{
              n++; 
		}
	}
	emp=j/(n-1);
	for(i=0;i<strlen(arr);)
	{
		while(arr[i ]==' '||arr[ i]=='\t')
		{i++;}
		if(arr[ i]=='\0')
		{break;}
		bg=i;
		while(!(((arr[ i+1]==' '||arr[ i+1]=='\t')&&(arr[ i]!=' '||arr[ i]!='\t'))||(arr[ i+1]=='\0'&&(arr[ i]!=' '||arr[ i]!='\t'))))
		{
			  i++;
	    }
		end=i;
		i++;
		while(arr[i ]==' '||arr[i ]=='\t')
		{i++;}
		
	   for(k=bg;k<=end;k++)
	   {
		   printf("%c",arr[ k]);
	   }
	   if(arr[i ]!='\0')
	   {
          for(k=0;k<emp;k++)
	      {
		      printf(" ");
	      }
	   }
	}
	printf("\n");
    system("pause");
	return 0;
}
