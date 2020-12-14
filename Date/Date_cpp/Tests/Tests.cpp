#include <iostream>
#include "Date.h"
#include "Time.h"

using namespace std;
int main()
{
   system("chcp 1251");
	system("cls");
    Date date, date1, s;
    //date.SetDate(1, 1, 1900);
    //int k = date.DaysBetween();
    //cout << k << endl;
    date.SetDate(1, 7, 2000 );
    date1.SetDate(21, 1, 50);
    date.OutDate();
    date1.OutDate();
    s = date + date1;
    //date=date.substract_days(date1.DaysBetween());
    s.OutDate();
	/*cout << "Доба: ";
	int hour, minute, second, hour2, minute2, second2;
	long int day, day2;
	cin >> day;
	cout << "година: ";
	cin >> hour;
	cout << "хвилина: ";
	cin >> minute;
	cout << "секунда: ";
	cin >> second;
	Time t, t2, s;
	t.SetTime(day, hour, minute, second);
	t.OutTime();
	cout << "Доба2: ";
	cin >> day2;
	cout << "година2: ";
	cin >> hour2;
	cout << "хвилина2: ";
	cin >> minute2;
	cout << "секунда2: ";
	cin >> second2;
	t2.SetTime(day2, hour2, minute2, second2);
	t2.OutTime();
	s = t.substract_time(t2);
	s.OutTime();*/
}
