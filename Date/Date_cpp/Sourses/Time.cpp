#include "Date.cpp"
#include <iostream>

class Time
{
private:
	int hour, minute, second;
	long int day;
public:
    Time()
    {
        hour = 0;
        minute = 0;
        second = 0;
        day = 0;
    }
    void SetTimeFromTextFile();
    void SetTime(long int valday, int valhour, int valminute, int valsecond)
	{
		day = valday; hour = valhour; minute = valminute; second = valsecond;
		if (hour >= 24 || hour < 0)
		{
			std::cout << "некорректно введены значения времени" << std::endl;
			exit(0);
		}
		if (minute >= 60 || minute < 0)
		{
			std::cout << "некорректно введены значения времени" << std::endl;
			exit(0);
		}
		if (second >= 60 || second < 0)
		{
			std::cout << "некорректно введены значения времени" << std::endl;
			exit(0);
		}
		if (day < 0)
		{
			std::cout << "некорректно введены значения времени" << std::endl;
			exit(0);
		}
	}
	bool operator > (const Time& time2)
	{
		if (this->day == time2.day)
		{
			if (this->hour == time2.hour)
			{
				if (this->minute == time2.minute)
				{
					return this->second > time2.second;
				}
				else return this->minute > time2.minute;
			}
			else return this->hour > time2.hour;
		}
		else return this->day > time2.day;
	}
	bool operator < (const Time& time2)
	{
		if (this->day == time2.day)
		{
			if (this->hour == time2.hour)
			{
				if (this->minute == time2.minute)
				{
					return this->second < time2.second;
				}
				else return this->minute < time2.minute;
			}
			else return this->hour < time2.hour;
		}
		else return this->day < time2.day;
	}
	bool operator ==(const Time &time2)
	{
		return this->day == time2.day && this->hour == time2.hour && this->minute == time2.minute && this->second == time2.second;
	}
	bool operator !=(const Time &time2)
	{
		return !(this->day == time2.day && this->hour == time2.hour && this->minute == time2.minute && this->second == time2.second);
	}
	Time add_time(const Time& time2)
	{
		long int n = this->second + this->minute * 60 + this->hour * 60 * 60 + this->day * 24 * 60 * 60 + time2.second + time2.minute * 60 + time2.hour * 60 * 60 + time2.day * 24 * 60 * 60;
		Time s;
		s.second = n % 60;
		n = (n - (n % 60)) / 60;
		s.minute = n % 60;
		n = (n - (n % 60)) / 60;
		s.hour = n % 24;
		n = (n - (n % 24)) / 24;
		s.day = n;
		return s;
	}
	Time subtract_time(const Time& time2)
	{
		long int n = this->second + this->minute * 60 + this->hour * 60 * 60 + this->day * 24 * 60 * 60 - time2.second - time2.minute * 60 - time2.hour * 60 * 60 - time2.day * 24 * 60 * 60;
		Time s;
		s.second = n % 60;
		n = (n - (n % 60)) / 60;
		s.minute = n % 60;
		n = (n - (n % 60)) / 60;
		s.hour = n % 24;
		n = (n - (n % 24)) / 24;
		s.day = n;
		return s;
	}
	Time mulyipl(const int k)
	{
		long int n = this->second + this->minute * 60 + this->hour * 60 * 60 + this->day * 24 * 60 * 60;
		n *= k;
		Time s;
		s.second = n % 60;
		n = (n - (n % 60)) / 60;
		s.minute = n % 60;
		n = (n - (n % 60)) / 60;
		s.hour = n % 24;
		n = (n - (n % 24)) / 24;
		s.day = n;
		return s;
	}
	Time div(const int k)
	{
		long int n = this->second + this->minute * 60 + this->hour * 60 * 60 + this->day * 24 * 60 * 60;
		n /= k;
		Time s;
		s.second = n % 60;
		n = (n - (n % 60)) / 60;
		s.minute = n % 60;
		n = (n - (n % 60)) / 60;
		s.hour = n % 24;
		n = (n - (n % 24)) / 24;
		s.day = n;
		return s;
	}
    Time FromDateToTime(Date& date)
    {
        Time s;
        s.day = (long int) date.DaysBetween();
        return s;
    }
    Time add_timedate(Date& date, Time& time)
    {
        Time s;
        s = s.FromDateToTime(date);
        return time.add_time(s);
    }
    Time subtract_timedate(Date& date, Time& time)
    {
        Time s;
        s = s.FromDateToTime(date);
        return s.subtract_time(time);
    }
};
