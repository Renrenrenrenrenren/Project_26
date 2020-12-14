#ifndef DATE_H
#define DATE_H

#include <string>
#include<iostream>

using namespace std;
class Date
{
private:
    int day; int month; int year;
public:
    Date();//Constructor
    void SetDate(int valDay, int valMonth, int valYear); //setting the date value
    void NextDate(Date& nextday); //determining the next day's date value
    void PreDate(Date& yesterday); //determining the previous day's date value
    void operator =(const Date& date2); // Operator "=" reboot
    bool operator <=(const Date& date2);//Operator "<=" reboot
    bool operator >=(const Date& date2);//Operator ">=" reboot
    bool operator <(const Date& date2); //Operator "<" reboot
    bool operator >(const Date& date2); //Operator ">" reboot
    bool operator !=(const Date& date2); //Operator "!=" reboot
    bool operator ==(const Date& date2); //Operator "==" reboot
    Date add_days(int days); //adds "days" days to the date
    Date subtract_days(int days); //substracts "days" days from the date
    int DaysBetween(); //Determine the number of days between the date and the zero year
    int DaysBetween(const Date& date2); //determines the number of days between two dates
    Date operator + (const Date& date2); // Operator "+" reboot
    string WeekDay(); //determining the day of the week
    Date operator - (const Date& date2); // Operator "-" reboot
    string DateToStr(); //create a string for output
};



#endif // DATE_H
