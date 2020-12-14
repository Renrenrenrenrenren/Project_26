#include <iostream>
#include <string>
#include <fstream>
#include <locale.h>

#include "Date.h"
#include "Time.h"

using namespace std;

void Output_Date(Date &date) //output date in console
    {
        string s = date.DateToStr();
        cout<<s<<endl;
    }
void Input_Date(Date &date) //input date from console
    {
        cout<<"доба: ";
        int d, m, y;
        cin>>d;
        cout<<"мiсяць: ";
        cin>>m;
        cout<<"рiк: ";
        cin>>y;
        date.SetDate(d,m,y);
    }
void Input_DateFromTextFile(Date &date) //input date from file
    {
        ifstream fin;
        string Name;
        cout<<"Введите имя файла для ввода даты: ";
        cin>>Name;
        fin.open(Name);
        if (!fin.is_open())
        {
            cout << "ошибка открытия файла для ввода даты";
            exit(0);
        }
        else
        {
            int sh = 0, d, m, y;
            cout << "В файле введено значение дня, месяца, года, каждое значение с новов стоки, в указаном порядке без перехода на новый рядок в конце" << endl;
            while (!fin.eof())
            {
                sh++;
                string str;
                str = "";
                getline(fin, str);
                if (sh == 1)
                {
                    d = stoi(str);
                }
                if (sh == 2)
                {
                    m = stoi(str);
                }
                if (sh == 3)
                {
                    y = stoi(str);
                }
            }
            date.SetDate(d, m, y);
        }
        fin.close();
    }
void Output_DateToFile( Date &date) //output date to file
    {
        string Name;
        cout<<"Введите имя файла для вывода даты: ";
        cin>>Name;
        ofstream fout;
        fout.open(Name);
        if (!fout.is_open())
        {
            cout << "ошибка открытия файла DateOutToFIle" << endl;
        }
        else
        {
            string s = date.DateToStr();
            fout<<s<<endl;
        }
        fout.close();
    }


void Input_TimeFromTextFile(Time &time) //input time from file
    {
        ifstream fin;
        string Name;
        cout<<"Введите имя файла для ввода времени: ";
        cin>>Name;
        fin.open(Name);
        if (!fin.is_open())
        {
            cout << "ошибка открытия файла для ввода времени";
            exit(0);
        }
        else
        {
            int sh = 0, d, h, m, s;
            cout << "В файле введено значение дня, часа, минуты, секунды, каждое значение с новов стоки, в указаном порядке без перехода на новый рядок в конце" << endl;
            while (!fin.eof())
            {
                sh++;
                string str;
                str = "";
                getline(fin, str);
                if (sh == 1)
                {
                    d = stoi(str);
                }
                if (sh == 2)
                {
                    h = stoi(str);
                }
                if (sh == 3)
                {
                    m = stoi(str);
                }
                if (sh == 4)
                {
                    s = stoi(str);
                }
            }
            time.SetTime(d, h, m, s);
        }
        fin.close();
    }
void Output_TimeToFile(Time &time) //output time to file
    {
        string Name;
        ofstream fout;
        fout.open(Name);
        if (!fout.is_open())
        {
            cout << "ошибка открытия файла для вывода времени" << endl;
        }
        else
        {
            string s = time.TimeToStr();
            cout<<s;
        }
        fout.close();
    }
void Input_Time(Time &time) //input time from console
{
    cout<<"доба: ";
    int d, h, m, s;
    cin>>d;
    cout<<"година: ";
    cin>>h;
    cout<<"хвилина: ";
    cin>>m;
    cout<<"секунда: ";
    cin>>s;
    time.SetTime(d, h, m, s);
}
void Output_Time(Time &time) //output time in console
{
    string s = time.TimeToStr();
    cout<<s;
}


int main()
{
    Date date, date2, s;
    int n;
    cout<<"input date from console: press 1\n from file: press 2\nif you take a different value, it will be from the console\n";
    cin>>n;
    if (n==2)
    {
        Input_DateFromTextFile(date);
        cout<<"netered day month year for example\n21 3 2020"<<endl;
    }
    else
    {
         cout<<"enter date 1"<<endl;
         Input_Date(date);
    }
    cout<<"output from console: press 1\n from file: press 2\nif you take a different value, it will be from the console\n";
    cin>>n;
    if(n==2)
    {
        Output_DateToFile(date);
    }
    else
    {
        Output_Date(date);
    }
    Output_Date(date);
    cout<<date.WeekDay()<<endl;
    cout<<"next date"<<endl;
    date.NextDate(s);
    Output_Date(s);
    cout<<"previous date"<<endl;
    date.PreDate(s);
    Output_Date(s);
    cout<<"enter date 2)"<<endl;
    Input_Date(date2);
    if(date2>date)
    {
        cout<<"date2>date1"<<endl;
    }
    else if (date2==date)
    {
        cout<<"date2==date1"<<endl;
    }
    else
    {
        cout<<"date2<date1"<<endl;
    }
    cout<<"Enter the number of days to add/subtract date 1: ";
    cin>>n;
    cout<<"subtract:"<<endl;
    s=date.subtract_days(n);
    Output_Date(s);
    cout<<"add:"<<endl;
    s=date.add_days(n);
    Output_Date(s);
    cout<<"date2+date1"<<endl;
    s=date2+date;
    Output_Date(s);
    cout<<"date2-date1"<<endl;
    s=date2-date;
    Output_Date(s);
    cout<<"The number of days between the dates1 and date2"<<endl;
    cout<<date.DaysBetween(date2)<<endl;
    cout<<"The number of days between the dates1 and 0 year"<<endl;
    cout<<date.DaysBetween()<<endl;


    Time a, b, c;
    cout<<"input time from console: press 1\n from file: press 2\nif you take a different value, it will be from the console\n";
    cin>>n;
    if(n==2)
    {
        cout<<"entered days hours minutes seconds, for example\n110 23 59 59"<<endl;
        Input_TimeFromTextFile(a);
    }
    else
    {
        cout<<"enter time1"<<endl;
        Input_Time(a);
    }
    cout<<"input from console: press 1\n from file: press 2\nif you take a different value, it will be from the console\n";
    cin>>n;
    if(n==2)
    {
       Output_TimeToFile(a);
    }
    else
    {
       Output_Time(a);
    }
    cout<<"Made time out of date1:"<<endl;
    b.FromDateToTime(date);
    Output_Time(b);
    cout<<"enter time2"<<endl;
    Input_Time(b);
    Output_Time(b);
    cout<<"time1+time2:"<<endl;
    c=b.add_time(a);
    Output_Time(c);
    cout<<"time2-time1:"<<endl;
    c=b.subtract_time(a);
    Output_Time(c);
    cout<<"Enter the number of days to add/subtract time1"<<endl;
    cin>>n;
    cout<<"multipl:"<<endl;
    c=a.mulyipl(n);
    Output_Time(c);
    cout<<"divade:"<<endl;
    c=a.div(n*n);
    Output_Time(c);
    cout<<"time1+date1"<<endl;
    c=a.add_timedate(date);
    Output_Time(c);
    cout<<"date1-time1"<<endl;
    c=a.subtract_timedate(date);
    Output_Time(c);
}
