#ifndef DATE_H_INCLUDED
#define DATE_H_INCLUDED

#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <stdbool.h>

void  Output_DateToFile(struct tm* aTm);

void week_day (struct tm * aTm);

void  Input_DateFromFile(struct tm* aTm);

void OutDate (struct tm* aTm);

void SetDate(int day, int month, int year, struct tm * aTm); //setting the date value in struct aTm

void NextDate(struct tm* th, struct tm* next);//determining the next day's date value
//in structure th the given date, in structure next set date value of the next day

void PreDate(struct tm* aTm, struct tm* preaTm);//determining the next day's date value
//in structure th the given date, in structure next set date value of the next day

bool date1IsBigThendate2(struct tm* aTm1, struct tm* aTm2);
//checks if the date given in structure aTm1 is greater than the date given in struct
//return 1 if it is, and 0 if if isn't

void add_days (struct tm* aTm, int n); //adds n days to the date, given in the struct aTm

void subtract_days (struct tm* aTm, int n); //substracts n days from the date, given in the struct aTm

bool date1Isdate2(struct tm* aTm1, struct tm* aTm2);
//Check if the date that given in structs aTm1 and aTm2 are the same
//return 1 if it is, and 0 if if isn't

int DaysBetween(struct tm * aTm);//Determine the number of days between the date of the given struct aTm and the zero year

int DaysBetween2(struct tm * a, struct tm * b);  //determines the number of days between two dates

void subtract_date(struct tm* a, int d, int m, int y, struct tm* c);
//subtract from the date given in the struct a the date given by prime numbers. Result setting structure c

void add_date(struct tm* a, int d, int m, int y, struct tm* c); //a+b=c b day =d, m=month y=year
//add to the date given in the struct a the date given by prime numbers. Result setting structure c


#endif // DATE_H_INCLUDED
