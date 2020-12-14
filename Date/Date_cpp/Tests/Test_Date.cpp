#include <string>
#include <fstream>
#include <iostream>
#include "Date.h"
using namespace std;

    void Date::OutDateToFile()
    {
        std::string Name = "DateOutToFIle.txt";
        ofstream fout;
        fout.open(Name);
        if (!fout.is_open())
        {
            std::cout << "ошибка открытия файла DateOutToFIle" << std::endl;
        }
        else
        {
            if (year == 0)
            {
                fout << "фактически в григорианском календаре 0-ого года нет, поєтому в этой программе 0-ой год = 1 год до н.э" << endl;
            }
            if (day < 10)
            {
                fout << "0" << day << ".";
            }
            if (day >= 10)
            {
                fout << day << ".";
            }
            if (month < 10)
            {
                fout << "0" << month << "." << year << " та " << day;
            }
            if (month >= 10)
            {
                fout << month << "." << year << " та " << day;
            }

            switch (month)
            {
            case 1:
                fout << " January " << year << endl;
                break;
            case 2:
                fout << " Fabruary " << year << endl;
                break;
            case 3:
                fout << " March " << year << endl;
                break;
            case 4:
                fout << " April " << year << endl;
                break;
            case 5:
                fout << " May " << year << endl;
                break;
            case 6:
                fout << " June " << year << endl;
                break;
            case 7:
                fout << " July " << year << endl;
                break;
            case 8:
                fout << " August " << year << endl;
                break;
            case 9:
                fout << " September " << year << endl;
                break;
            case 10:
                fout << " October " << year << endl;
                break;
            case 11:
                fout << " November " << year << endl;
                break;
            case 12:
                fout << " December " << year << endl;
                break;
            }
        }
        fout.close();
    }

    void Date::OutDate()             //вывод даты
    {
        if (year == 0)
        {
            cout << "фактически в григорианском календаре 0-ого года нет, поєтому в этой программе 0-ой год = 1 год до н.э" << endl;
        }
        if (day < 10)
        {
            cout << "0" << day << ".";
        }
        if (day >= 10)
        {
            cout << day << ".";
        }
        if (month < 10)
        {
            cout << "0" << month << "." << year << " та " << day;
        }
        if (month >= 10)
        {
            cout << month << "." << year << " та " << day;
        }

        switch (month)
        {
        case 1:
            cout << " January " << year << endl;
            break;
        case 2:
            cout << " Fabruary " << year << endl;
            break;
        case 3:
            cout << " March " << year << endl;
            break;
        case 4:
            cout << " April " << year << endl;
            break;
        case 5:
            cout << " May " << year << endl;
            break;
        case 6:
            cout << " June " << year << endl;
            break;
        case 7:
            cout << " July " << year << endl;
            break;
        case 8:
            cout << " August " << year << endl;
            break;
        case 9:
            cout << " September " << year << endl;
            break;
        case 10:
            cout << " October " << year << endl;
            break;
        case 11:
            cout << " November " << year << endl;
            break;
        case 12:
            cout << " December " << year << endl;
            break;
        }
    }



    void Date::SetDateFromTextFile()
    {
        std::string Name;
        cout<<"enter input file name";
        cin>>Name;
        ifstream fin;
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
            Date date;
            date.SetDate(d, m, y);
            day = d;
            month = m;
            year = y;
        }
        fin.close();
    }
