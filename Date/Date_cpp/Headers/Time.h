#ifndef TIME_H_INCLUDED
#define TIME_H_INCLUDED
#include <fstream>



class Time
{
public:
    void OutTime();
    void SetTimeFromTextFile();
    void OutDateToFile();
    void SetTime(long int valday, int valhour, int valminute, int valsecond);
    bool operator > (const Time& time2);
    bool operator < (const Time& time2);
    bool operator ==(const Time &time2);
    bool operator !=(const Time &time2);
    Time add_time(const Time& time2);
    Time subtract_time(const Time& time2);
    Time mulyipl(const int k);
    Time div(const int k);
    Time FromDateToTime(Date& date);
    Time add_timedate(Date& date, Time& time);
    Time subtract_timedate(Date& date, Time& time);
    void SetTimeFromTextFile();
};
#endif // TIME_H_INCLUDED
