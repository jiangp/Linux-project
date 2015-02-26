/*************************************************************************
	> File Name: print.c
	> Author: Arwen
	> Mail:745529725@qq.com 
	> Created Time: Mon 26 Jan 2015 08:20:14 PM CST
 ************************************************************************/

#include"c.h"
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


