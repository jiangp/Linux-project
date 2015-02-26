/*************************************************************************
  > File Name: print_month.c
  > Author: Comst
  > Mail:750145240@qq.com 
  > Created Time: Mon 26 Jan 2015 03:09:11 PM CST
 ************************************************************************/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define TITLE "| %d  SUN MON TUE WED THU FRI SAT \n"
#define REF_YEAR 1989
#define ISLEAPYEAR(year) (year % 400 == 0 || year % 4 == 0 && year % 100 != 0)
void print_month(int month, int year);
int dayofyear(int year, int month, int day) ;
int days_a_month(int mon,int year);
int diffdate(int year1,int month1, int day1, int year2, int month2, int day2);
int main(int argc, char* argv[])
{
	int mon ;
	int year ;
	while(scanf("%d%d", &mon, &year) == 2)
	{
		system("clear");
		print_month(mon, year);
	}
	return 0 ;
}
void print_month(int month, int year)
{
	printf( TITLE, month);
	int sum_days_a_month = days_a_month(month, year) ;
	int sum_days = diffdate(1989,1,1, year, month, 1);
	int week_bg = sum_days % 7 ;
	int space_cnt = 0 ; 
	int date = 1 ;

	//1
	printf("|    ");
	while(space_cnt < week_bg)
	{
		printf("    ");
		space_cnt ++ ;
	}
	while(week_bg <= 6)
	{
		printf("%3d ", date);
		date ++ ;
week_bg ++ ;
	}
	printf("\n");	
	//2
	printf("|    ");
	week_bg = 0 ;
	while(week_bg <= 6)
	{
		printf("%3d ", date);
		date ++ ;
		week_bg ++ ;
	}
	printf("\n");	
	//3
	printf("|    ");
	week_bg = 0 ;
	while(week_bg <= 6)
	{
		printf("%3d ", date);
		date ++ ;
		week_bg ++ ;
	}
	printf("\n");	
	//4
	printf("|    ");
	week_bg = 0 ;
	while(week_bg <= 6)
	{
		printf("%3d ", date);
		date ++ ;
		week_bg ++ ;
	}
	printf("\n");	
	//5
	printf("|    ");
	week_bg = 0 ;
	while(week_bg <= 6 && date <= sum_days_a_month)
	{
		printf("%3d ", date);
		date ++ ;
		week_bg ++ ;
	}
	printf("\n");
//6
	week_bg = 0 ;
	if(date <= sum_days_a_month)
	{
		printf("|    ");
		while(week_bg <= 6 && date <= sum_days_a_month)
		{
			printf("%3d ", date);
			date ++ ;
			week_bg ++ ;
		}
		printf("\n");

	}







}
int dayofyear(int year, int month, int day)
{
	int sum ;
	int index_month ;
	sum = 0 ;
	for(index_month = 1 ; index_month < month ; index_month ++)
	{
		switch(index_month)
		{
			case 1 : 
			case 3 : 
			case 5 : 
			case 7 : 
			case 8 : 
			case 10 : 
			case 12 : 
				sum += 31 ;
				break ;
			case 4 : 
			case 6 : 
			case 9 : 
			case 11 :
				sum += 30 ;
				break ;
			case 2 : 
				if(ISLEAPYEAR(year))
				{
					sum += 29 ;
				}else 
				{
					sum += 28 ;
				}
				break ;
		}

	}
	sum += day ;
	return sum ;
}
int diffdate(int year1,int month1, int day1, int year2, int month2, int day2)
{
	int index_year ;
	int sum  = 0; 
	for(index_year = year1; index_year < year2 ; index_year ++ )
	{
		if(ISLEAPYEAR(index_year))
		{
			sum += 366 ;
		}else 
		{
			sum += 365 ;
		}
	}
	sum = sum + dayofyear(year2,month2,day2) - dayofyear(year1,month1,day1);
	return sum ;
}
int days_a_month(int mon, int year)
{
	switch(mon)
	{
		case 1 : 
		case 3 : 
		case 5 : 
		case 7 : 
		case 8 : 
		case 10 : 
		case 12 : 
			return  31 ;
			break ;
		case 4 : 
		case 6 : 
		case 9 : 
		case 11 :
			return 30 ;
			break ;
		case 2 : 
			if(ISLEAPYEAR(year))
			{
				return  29 ;
			}else 
			{
				return 28 ;
			}
			break ;
	}

}

