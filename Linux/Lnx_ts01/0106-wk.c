#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int ye(int year1,int year2)
{
	int i,sum2=0;
	for(i=year1;i<year2;i++)
	{
		if((i%4==0)&&(i%100!=0)||(i%400==0))
		{
			sum2=sum2+366;
		}
		else
		{
			sum2=sum2+365;
		}
	}
	return sum2;
}



int day(int year,int mount,int day)
{
	int date[]={31,28,31,30,31,30,31,31,30,31,30,31};
	int i,sum1=0;
	if((year%4==0)&&(year%100!=0)||(year%400==0))
		date[1]=29;
	for(i=0;i<mount-1;i++)
	{
		sum1+=date[i];	     
	}
	sum1=sum1+day;
	return sum1;
}


void main()
{
	int sum2=0;
	int year1=2010,year2;
	int mount1=1,mount2;
	int day1=3,day2;
	int i,w,sum=0;
	char* wen[]={"wenk","mind","tusd","wond","turd","fird","satd"};
	int date[]={31,28,31,30,31,30,31,31,30,31,30,31};
	printf("输入日期");
	scanf("%d%d%d",&year2,&mount2,&day2);
	sum2=ye(year1,year2);
	if(sum2==0)
		sum2=-ye(year2,year1);

	sum=sum2+(day(year2,mount2,day2)-(day(year1,mount1,day1)));
	if(sum>0)
	{
		w=sum%7;
	}
	else{
		sum2=-sum2;
		sum=sum2-(day(year2,mount2,day2))+(day(year1,mount1,day1));
		w=7-(sum%7);

	}
	printf("当天是星期%s:",wen[w]);
	//for(i=0;i<5;i++)		
	  // printf("%s",wen[w]);
	system("pause");
	
}