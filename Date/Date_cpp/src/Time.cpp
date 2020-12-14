#include "Time.h"

    Time::Time() //Constructor
    {
        hour = 0;
        minute = 0;
        second = 0;
        day = 0;
    }
    void Time::FromDateToTime(Date date) //converts a date to time
    {
        this->second=0;
        this->minute=0;
        this->hour=0;
        this->day= date.DaysBetween();
    }
    string Time::TimeToStr()
    {
        string s = "";
        s+= to_string(day)+ ".";
		if (hour < 10)
		{
			s+= "0" + to_string(hour) + ".";
		}
		else
		{
			s+= to_string(hour) + ".";
		}

		if (minute < 10)
		{
			s+= "0" + to_string(minute) + ".";
		}
		else
		{
			s+= to_string(minute) + ".";
		}
		if (second < 10)
		{
            s+= "0" + to_string(second) + "\n";
		}
		else
		{
			s+= to_string(second) + "\n";
		}

        return s;
    }
    bool Time::operator ==(const Time &time2)  //Operator "==" reboot
	{
		return this->day == time2.day && this->hour == time2.hour && this->minute == time2.minute && this->second == time2.second;
	}
    Time Time::add_timedate(Date& date) //add the date and time
    {
        Time st, s;
        s.second=this->second; s.minute-this->minute; s.hour=this->hour; s.second=this->second;
        st.FromDateToTime(date);
        return st.add_time(s);
    }
    Time Time::subtract_timedate(Date& date) //subtracts the time from the date
    {
        Time s, st;
        s.second=this->second; s.minute-this->minute; s.hour=this->hour; s.second=this->second;
        st.FromDateToTime(date);
        return st.subtract_time(s);
    }
    Time Time::add_time(const Time& time2)
    //add time to time2
	{
		long int n = this->second + this->minute * 60 + this->hour * 60 * 60 + this->day * 24 * 60 * 60 + time2.second + time2.minute * 60 + time2.hour * 60 * 60 + time2.day * 24 * 60 * 60;
		//convert time and time2 into seconds and add them
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
	Time Time:: subtract_time(const Time& time2)
	//Subtract from the time the time2
	{
		long int n = this->second + this->minute * 60 + this->hour * 60 * 60 + this->day * 24 * 60 * 60 - time2.second - time2.minute * 60 - time2.hour * 60 * 60 - time2.day * 24 * 60 * 60;
		//convert time and time2 into seconds and subtract them
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
	Time Time::mulyipl(const int k) //multiply the time given in the structure by number k
	{
		long int n = this->second + this->minute * 60 + this->hour * 60 * 60 + this->day * 24 * 60 * 60;
		//convert time into seconds
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
	Time Time:: div(const int k) //divide the time by number k
	{
		long int n = this->second + this->minute * 60 + this->hour * 60 * 60 + this->day * 24 * 60 * 60;
		//convert time into seconds
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
	bool Time::operator !=(const Time &time2)  //Operator "!=" reboot
	{
		return !(this->day == time2.day && this->hour == time2.hour && this->minute == time2.minute && this->second == time2.second);
	}
    bool Time::operator < (const Time& time2)  //Operator "<" reboot
	{
		if (this->day == time2.day) //checking the day
		{
			if (this->hour == time2.hour) //checking the hour
			{
				if (this->minute == time2.minute) //checking the minute
				{
					return this->second < time2.second; //checking the second
				}
				else return this->minute < time2.minute;
			}
			else return this->hour < time2.hour;
		}
		else return this->day < time2.day;
	}
    bool Time::operator > (const Time& time2)  //Operator ">" reboot
	{
		if (this->day == time2.day) //checking the day
		{
			if (this->hour == time2.hour) //checking the hour
			{
				if (this->minute == time2.minute) //checking the minute
				{
					return this->second > time2.second; //checking the second
				}
				else return this->minute > time2.minute;
			}
			else return this->hour > time2.hour;
		}
		else return this->day > time2.day;
	}
    void Time::SetTime(int valday, int valhour, int valminute, int valsecond) //sets a time value
	{
		day = valday; hour = valhour; minute = valminute; second = valsecond;
		if (hour >= 24 || hour < 0)
        //if the hours are more than 24 or less than zero
		{
			cout << "Incorrect time value" << endl;
			exit(0);
		}
		if (minute >= 60 || minute < 0)
        //if minutes are more than 60 or less than zero
		{
			cout << "Incorrect time value" << endl;
			exit(0);
		}
		if (second >= 60 || second < 0)
		//if seconds are more than 60 or less than zero
		{
			cout << "Incorrect time value" << endl;
			exit(0);
		}
		if (day < 0)
		{
			cout << "Incorrect time value" << endl;
			exit(0);
		}
	}
