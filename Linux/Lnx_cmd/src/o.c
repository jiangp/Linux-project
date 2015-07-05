/*************************************************************************
	> File Name: ./src/o.c
	> Author: Arwen
	> Mail:745529725@qq.com 
	> Created Time: Mon 26 Jan 2015 09:42:25 PM CST
 ************************************************************************/

#include"c.h"
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



