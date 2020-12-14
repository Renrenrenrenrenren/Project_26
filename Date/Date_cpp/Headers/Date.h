#ifndef DATE_H_INCLUDED
#define DATE_H_INCLUDED
//#include "Sourses\Date.cpp"
#include <string>

class Date
{
public:
    void OutDateToFile();
    void OutDate();
    void SetDateFromTextFile()
    void NextDate(Date& nextday);
    void PreDate(Date& yesterday);
    bool operator ==(const Date& date2);
    bool operator !=(const Date& date2);
    bool operator >(const Date& date2);
    bool operator <(const Date& date2);
    bool operator >=(const Date& date2);
    bool operator <=(const Date& date2);
    void operator =(const Date& date2);
    Date add_days(int days);
    Date substract_days(int days);
    int DaysBetween(const Date& date2);
    int DaysBetween();
    Date operator + (const Date& date2);
    Date operator - (const Date& date2);
    string WeekDay();
};
void SetDateFromTextFile(string Name);
    void OutDateToFile();
    void OutDate();
    void SetDate(int valDay, int valMonth, int valYear)

#endif // DATE_H_INCLUDED
