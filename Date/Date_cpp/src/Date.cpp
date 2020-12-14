#include "Date.h"

    void Date::SetDate(int valDay, int valMonth, int valYear) //setting the date value
    {
        bool x = false;
        if ((year % 4 == 0 && year % 100 != 0) || year % 400 == 0)//checking for leap year
        {
            x = true; //if year is leap
        }
        day = valDay;
        month = valMonth;
        year = valYear;
        while (day > 31 && (month == 1 || month == 3 || month == 5 || month == 7 || month == 8 || month == 10 || month == 12))
        //If the days in January, March, May, July, August, October, December are more than 31
        {
            cout << "Incorrect date value";
            exit(0);
        }
        while (day > 30 && (month == 4 || month == 6 || month == 9 || month == 11))
        //If there are more than 30 days in April, June, September, November
        {
            cout << "Incorrect date value";
            exit(0);
        }
        while (month == 2 && x == 1 && day > 29)
        //If the year is a leap year and the number of days in February is more than 29
        {
            cout << "Incorrect date value";
            exit(0);
        }
        while (month == 2 && x == 0 && day > 28)
        //If the year is not a leap year and the number of days in February is more than 28
        {
            cout << "Incorrect date value";
            exit(0);
        }
        while (month > 12 || month < 1 || day < 1)
        //If months are more than 12, or months are less than 1, or days are less than 1
        {
            cout << "Incorrect date value";
            exit(0);
        }
    }
    Date::Date()//Constructor
    {
        day = 1; month = 1; year = 0;
    }
    bool Date::operator == (const Date& date2) //Operator "==" reboot
    {
        return this->year == date2.year && this->month == date2.month && this->day == date2.day;
    }
    bool Date::operator !=(const Date& date2) //Operator "!=" reboot
    {
        return !(this->year == date2.year && this->month == date2.month && this->day == date2.day);
    }
    bool Date::operator >(const Date& date2) //Operator ">" reboot
    {
        return this->year > date2.year || (this->month > date2.month && this->year == date2.year) || (this->day > date2.day && this->month == date2.month && this->year == date2.year);
    }
    bool Date::operator <(const Date& date2) //Operator "<" reboot
    {
        return this->year < date2.year || (this->month < date2.month&& this->year == date2.year) || (this->day < date2.day&& this->month == date2.month && this->year == date2.year);
    }
    bool Date::operator >=(const Date& date2) //Operator ">=" reboot
    {
        return this->year >= date2.year || (this->month >= date2.month && this->year == date2.year) || (this->day >= date2.day && this->month == date2.month && this->year == date2.year);
    }
    bool Date::operator <=(const Date& date2) //Operator "<=" reboot
    {
        return this->year <= date2.year || (this->month <= date2.month && this->year == date2.year) || (this->day <= date2.day && this->month == date2.month && this->year == date2.year);
    }
    void Date::operator =(const Date& date2) // Operator "=" reboot
    {
        this->day = date2.day;
        this->month = date2.month;
        this->year = date2.year;
    }
    Date Date::operator + (const Date& date2) // Operator "+" reboot
    {
        Date h, date3 = date2;
        Date date1; date1.day = this->day; date1.month = this->month; date1.year = this->year;
        int n = date1.DaysBetween();
        h = date3.add_days(n);
        return h;
    }
    Date Date::operator - (const Date& date2) // Operator "-" reboot
    {
        Date h, date3 = date2;
        Date date1; date1.day = this->day; date1.month = this->month; date1.year = this->year;
        int n = date3.DaysBetween();
        h = date1.subtract_days(n);
        return h;
    }
    string Date::WeekDay() //determining the day of the week
    {
        string s;
        Date date1; date1.day = this->day; date1.month = this->month; date1.year = this->year;
        Date date2; date2.SetDate(7, 12, 2020); //Let the accounting be kept from December 7, 2020
        int n = date1.DaysBetween(date2);
        if (date1 > date2)
        {
            switch (n % 7)
            {
            case 0:
                s = "Monday";
                break;
            case 1:
                s = "Tuesday";
                break;
            case 2:
                s = "Wednesday";
                break;
            case 3:
                s = "Thursday";
                break;
            case 4:
                s = "Friday";
                break;
            case 5:
                s = "Saturday";
                break;
            case 6:
                s = "Sunday";
                break;
            }
        }
        else
        {
            switch (n % 7)
            {
            case 0:
                s = "Monday";
                break;
            case 6:
                s = "Tuesday";
                break;
            case 5:
                s = "Wednesday";
                break;
            case 4:
                s = "Thursday";
                break;
            case 3:
                s = "Friday";
                break;
            case 2:
                s = "Saturday";
                break;
            case 1:
                s = "Sunday";
                break;
            }
        }
        return s;
    }
    int Date::DaysBetween(const Date& date2) //determines the number of days between two dates
    {
        Date date1; date1.day = this->day; date1.month = this->month; date1.year = this->year;
        if (date1 < date2)
        {
            int i = 0;
            Date s;
            for (; date1 != date2; i++)
            {
                s = date1.add_days(1);
                date1 = s;
            }
            return i;
        }
        else if (date1 > date2)
        {
            int i = 0;
            Date s;
            for (; date1 != date2; i++)
            {
                s = date1.subtract_days(1);
                date1 = s;
            }
            return i;
        }
        else return 0;
    }
    int Date::DaysBetween() //Determine the number of days between the date and the zero year
    {
        Date date1; date1.day = this->day; date1.month = this->month; date1.year = this->year;
        Date date2;
        int i = date2.DaysBetween(date1);
        return i;
    }
    Date Date::subtract_days(int days) //substracts "days" days from the date
    {
        Date date1; date1.day = this->day; date1.month = this->month; date1.year = this->year;
        if (days == 0)
        {
            return date1;
        }
        else
        {
            Date sub;
            for (int i = 0; i < days; i++)
            {
                date1.PreDate(sub);
                date1 = sub;
            }
            return sub;
        }
    }
    Date Date::add_days(int days) //adds "days" days to the date
    {
        Date date1; date1.day = this->day; date1.month = this->month; date1.year = this->year;
        if (days == 0)
        {
            return date1;
        }
        else
        {
            Date sum;
            for (int i = 0; i < days; i++)
            {
                date1.NextDate(sum);
                date1 = sum;
            }
            return sum;
        }
    }
    void Date::PreDate(Date& yesterday)  //determining the previous day's date value
    {
        if (month == 1 && day == 1) //if the given date is January 1 some year
        {
            yesterday.SetDate(31, 12, year - 1);
        }
        else if ((month == 2 || month == 4 || month == 6 || month == 8 || month == 9 || month == 11) && day == 1)
        //if the given date is 1 day of February, or April, or July, or August, or September, or November some year
        {
            yesterday.SetDate(31, month - 1, year);
        }
        else if ((month == 5 || month == 7 || month == 10 || month == 12) && day == 1)
        //if the given date is 1 day of May, or June, or October, or December some year
        {
            yesterday.SetDate(30, month - 1, year);
        }
        else if (day == 1 && month == 3) //if the given date is March 1 some year
        {
            bool x = false;
            if ((year % 4 == 0 && year % 100 != 0) || year % 400 == 0) //checking a leap year
            {
                x = true; //if year is a leap
            }
            if (x)
            {
                yesterday.SetDate(29, month - 1, year);
            }
            else
            {
                yesterday.SetDate(28, month - 1, year);
            }
        }
        else //if the given date is not the start of the month
        {
            yesterday.SetDate(day - 1, month, year);
        }
    }
    void Date::NextDate(Date& nextday) //determining the next day's date value
    {
        if (month != 12 && day == 31) //if the given date is 31 day of some month (except December) some year
        {
            nextday.SetDate(1, month + 1, year);
        }
        else if (month == 12 && day == 31) // if the given date is December 31 some year
        {
            nextday.SetDate(1, 1, year + 1);
        }
        else if (day == 30 && (month == 4 || month == 6 || month == 9 || month == 11))
        //if the given date is 30 day of April, or June, or September or November some year
        {
            nextday.SetDate(1, month + 1, year);
        }
        else if (day == 29 && month == 2)  //if the given date is February 29 some year
        {
            nextday.SetDate(1, month + 1, year);
        }
        else if (day == 28 && month == 2) ////if the given date is February 28 some year
        {
            bool x = false;
            if ((year % 4 == 0 && year % 100 != 0) || year % 400 == 0) ////checking a leap year
            {
                x = true; //if year is a leap
            }
            if (x)
            {
                nextday.SetDate(29, month, year);
            }
            else
            {
                nextday.SetDate(1, month + 1, year);
            }
        }
        else //if the given date is not the end of the month
        {
            nextday.SetDate(day + 1, month, year);
        }
    }
    string Date::DateToStr() //create a string for output
    {
        string s="";
        if (year == 0)
        {
             s+="фактически в григорианском календаре 0-ого года нет, поєтому в этой программе 0-ой год = 1 год до н.э \n";
        }
        if (day < 10)
        {
            s+= '0' +to_string(day) + '.';
        }
        if (day >= 10)
        {
            s+= to_string(day)+'.';
        }
        if (month < 10)
        {
            s+= '0' + to_string(month) + '.' + to_string(year) + '\n' + to_string(day) + ' ';
        }
        if (month >= 10)
        {
            s+= to_string(month) + '.' + to_string(year) + '\n' + to_string(day) + ' ';}
            switch (month)
            {
        case 1:
            s+= "January ";
            s+= to_string(year);
            break;
        case 2:
            s+= "Fabruary ";
            s+= to_string(year);
            break;
        case 3:
            s+= "March ";
            s+=  to_string(year);
            break;
        case 4:
            s+= "April ";
            s+= to_string(year);
            break;
        case 5:
            s+= "May ";
            s+= to_string(year);
            break;
        case 6:
            s+= "June ";
            s+= to_string(year);
            break;
        case 7:
            s+= "July ";
            s+= to_string(year);
            break;
        case 8:
            s+= "August ";
            s+= to_string(year);
            break;
        case 9:
            s+= "September ";
            s+=  to_string(year);
            break;
        case 10:
            s+= "October ";
            s+= to_string(year);
            break;
        case 11:
            s+= "November ";
            s+= to_string(year);
            break;
        case 12:
            s+= "December ";
            s+= to_string(year);
            break;
        }
        s+="\n";
        return s;
    }
