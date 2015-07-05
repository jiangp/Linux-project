#ifndef __FUNC__
#define __FUNC__
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
#endif

