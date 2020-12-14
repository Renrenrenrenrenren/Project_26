#ifndef DATE_H_INCLUDED
#endif // DATE
#define DATE_H_INCLUDED
#include <string>
#include <iostream>


class Date
{
private:
    int day; int month; int year;
public:
    Date()
    {
        day = 1; month = 1; year = 0;
    }
    void OutDateToFile();
    void OutDate();
    void SetDateFromTextFile();
     void SetDate(int valDay, int valMonth, int valYear) //setting the date value in struct aTm
    {
        bool x = false; //checking for leap year
        if ((year % 4 == 0 && year % 100 != 0) || year % 400 == 0)
        {
            x = true; //if year is leap
        }
        day = valDay;
        month = valMonth;
        year = valYear;
        while (day > 31 && (month == 1 || month == 3 || month == 5 || month == 7 || month == 8 || month == 10 || month == 12))
        {
            printf ("¬ы ввели некорректное значение даты");
            exit(0);
        }
        while (day > 30 && (month == 4 || month == 6 || month == 9 || month == 11))
        {
            std::cout << "¬ы ввели некорректное значение даты";
            exit(0);
        }
        while (month == 2 && x == 1 && day > 29)
        {
            std::cout << "¬ы ввели некорректное значение даты";
            exit(0);
        }
        while (month == 2 && x == 0 && day > 28)
        {
            std::cout << "¬ы ввели некорректное значение даты";
            exit(0);
        }
        while (month > 12 || month < 1 || day < 1)
        {
            std::cout << "¬ы ввели некорректное значение даты";
            exit(0);
        }
    }
    void NextDate(Date& nextday) //determining the next day's date value
    //in structure th the given date, in structure next set date value of the next day
    {
        if ((month == 1 || month == 3 || month == 5 || month == 7 || month == 8 || month == 10) && day == 31)
        {
            nextday.SetDate(1, month + 1, year);
        }
        else if (month == 12 && day == 31)
        {
            nextday.SetDate(1, 1, year + 1);
        }
        else if (day == 30 && (month == 4 || month == 6 || month == 9 || month == 11))
        {
            nextday.SetDate(1, month + 1, year);
        }
        else if (day == 29 && month == 2)
        {
            nextday.SetDate(1, month + 1, year);
        }
        else if (day == 28 && month == 2)
        {
            bool x = false;
            if ((year % 4 == 0 && year % 100 != 0) || year % 400 == 0)
            {
                x = true;
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
        else
        {
            nextday.SetDate(day + 1, month, year);
        }
    }
    void PreDate(Date& yesterday)      // предведущий день
    {
        if (month == 1 && day == 1)
        {
            yesterday.SetDate(31, 12, year - 1);
        }
        else if ((month == 2 || month == 4 || month == 6 || month == 8 || month == 9 || month == 11) && day == 1)
        {
            yesterday.SetDate(31, month - 1, year);
        }
        else if ((month == 5 || month == 7 || month == 10 || month == 12) && day == 1)
        {
            yesterday.SetDate(30, month - 1, year);
        }
        else if (day == 1 && month == 3)
        {
            bool x = false;
            if ((year % 4 == 0 && year % 100 != 0) || year % 400 == 0)
            {
                x = true;
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
        else
        {
            yesterday.SetDate(day - 1, month, year);
        }
    }
    // перезагрузка всех операторов не была нужна, но пусть будет на вс€кий пожарный
    bool operator ==(const Date& date2) //перезагрузка оператора "=="
    {
        return this->year == date2.year && this->month == date2.month && this->day == date2.day;
    }
    bool operator !=(const Date& date2) //перезагрузка оператора "!="
    {
        return !(this->year == date2.year && this->month == date2.month && this->day == date2.day);
    }
    bool operator >(const Date& date2) //перезагрузка оператора ">"
    {
        return this->year > date2.year || (this->month > date2.month && this->year == date2.year) || (this->day > date2.day && this->month == date2.month && this->year == date2.year);
    }
    bool operator <(const Date& date2) //перезагрузка оператора "<"
    {
        return this->year < date2.year || (this->month < date2.month&& this->year == date2.year) || (this->day < date2.day&& this->month == date2.month && this->year == date2.year);
    }
    bool operator >=(const Date& date2) //перезагрузка оператора ">="
    {
        return this->year >= date2.year || (this->month >= date2.month && this->year == date2.year) || (this->day >= date2.day && this->month == date2.month && this->year == date2.year);
    }
    bool operator <=(const Date& date2) //перезагрузка оператора ">="
    {
        return this->year <= date2.year || (this->month <= date2.month && this->year == date2.year) || (this->day <= date2.day && this->month == date2.month && this->year == date2.year);
    }
    void operator =(const Date& date2) // перезагрузка оператора "="
    {
        this->day = date2.day;
        this->month = date2.month;
        this->year = date2.year;
    }
    Date add_days(int days) //прибавление дней
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
    Date substract_days(int days) // вычитане дней
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
    int DaysBetween(const Date& date2) //дней между 2-м€ датами
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
                s = date1.substract_days(1);
                date1 = s;
            }
            return i;
        }
        else return 0;
    }
    int DaysBetween() //дней между 01.01.0 и даной датой
    {
        Date date1; date1.day = this->day; date1.month = this->month; date1.year = this->year;
        Date date2;
        int i = date2.DaysBetween(date1);
        return i;
    }
    Date operator + (const Date& date2) // перезагрузка оператора "+"
    {
        Date h, date3 = date2;
        Date date1; date1.day = this->day; date1.month = this->month; date1.year = this->year;
        int n = date1.DaysBetween();
        h = date3.add_days(n);
        return h;
    }
    Date operator - (const Date& date2) // перезагрузка оператора "-"
    {
        Date h, date3 = date2;
        Date date1; date1.day = this->day; date1.month = this->month; date1.year = this->year;
        int n = date3.DaysBetween();
        h = date1.substract_days(n);
        return h;
    }
    std::string WeekDay()
    {
        std::string s;
        Date date1; date1.day = this->day; date1.month = this->month; date1.year = this->year;
        Date date2; date2.SetDate(7, 12, 2020);
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

};

