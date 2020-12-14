#ifndef TIME_H
#define TIME_H

#include <string>
#include<iostream>

#include "Date.h"

class Time
{
private:
	int hour, minute, second;
	long int day;
public:
    Time(); //Constructor
	void SetTime(int valday, int valhour, int valminute, int valsecond); //sets a time value
    bool operator > (const Time& time2);  //Operator ">" reboot
	bool operator < (const Time& time2);  //Operator "<" reboot
	bool operator ==(const Time &time2);  //Operator "==" reboot
	bool operator !=(const Time &time2);  //Operator "!=" reboot
	Time div(const int k); //divide the time by number k
	Time mulyipl(const int k); //multiply the time given in the structure by number k
	Time add_time(const Time& time2); //add time to time2
	Time subtract_time(const Time& time2); //Subtract from the time the time2
    void FromDateToTime(Date date); //converts a date to time
    Time subtract_timedate(Date& date);  //subtracts the time from the date
    Time add_timedate(Date& date); //add the date and time
    string TimeToStr(); //create a string for output
};



#endif // TIME_H
