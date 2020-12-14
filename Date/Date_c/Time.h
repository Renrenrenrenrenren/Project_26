#ifndef TIME_H_INCLUDED
#define TIME_H_INCLUDED

#include "Date.h"

#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <stdbool.h>

void OutTimeToFile(struct tm* aTm);

void SetTimeFromFile (struct tm* aTm);

void OutTime(struct tm * a);

void SetTime(struct tm* a, int day, int hour, int minute, int second); //sets a time value to a structure

bool Time1IsBigThenTime2 (struct tm* a, struct tm* b);
// check if the time data in the structure a is greater than the time given in the structure b
//return 1 if it is, and 0 if if isn't

bool Time1IsTime2 (struct tm* a, struct tm* b);
//Check if the date that given in structs aTm1 and aTm2 are the same
//return 1 if it is, and 0 if if isn't

void add_time (struct tm* a, struct tm* b,struct tm* s);
//add time is given in structure a and b, the result is set in the structure s

void multipl(struct tm* a, int k);  //multiply the time given in the structure and the number k

void divade(struct tm* a, int k);  //divide the time given in the structure and the number k

void add_timedata(struct tm* time, struct tm* date,struct tm* s);
//add the date and time given in the appropriate structures, the result is set in the structure s

int getDaysFromTime(struct tm* a); //returns the number of days from time

void FromDateToTime (struct tm* date, struct tm* time);  //reformatting from date to time,timethe result is set in the structure



#endif // TIME_H_INCLUDED
