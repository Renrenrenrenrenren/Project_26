#include <string>
#ifndef TIME_H_INCLUDED
#endif // DATE
#define TIME_H_INCLUDED
#include <fstream>

    void Time:: SetTimeFromTextFile()
    {
        ifstream fin;
        string Name;
        cout<<"ëntrer fil name enter date: ";
        cin>>Name
        fin.open(Name);
        if (!fin.is_open())
        {
            cout << "ошибка открытия файла для ввода даты";
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
            /*day = d;
            minute = m;
            hour = h;
            second = s;*/
        }
        fin.close();
    }
	void Time::OutTime()
	{
		cout << day << ".";
		if (hour < 10)
		{
			cout << "0" << hour << ".";
		}
		else
		{
			cout << hour << ".";
		}
		if (minute < 10)
		{
			cout << "0" << minute << ".";
		}
		else
		{
			cout << minute << ".";
		}
		if (second < 10)
		{
			cout << "0" << second << endl;
		}
		else
		{
			cout << second << endl;
		}
	}
    void Time::OutDateToFile()
    {
        string Name = "TimeOutToFIle.txt";
        ofstream fout;
        fout.open(Name);
        if (!fout.is_open())
        {
            cout << "ошибка открытия файла TimeOutToFIle" << endl;
        }
        else
        {
            fout << day << ".";
            if (hour < 10)
            {
                fout << "0" << hour << ".";
            }
            else
            {
                fout << hour << ".";
            }
            if (minute < 10)
            {
                fout << "0" << minute << ".";
            }
            else
            {
                fout << minute << ".";
            }
            if (second < 10)
            {
                fout << "0" << second << endl;
            }
            else
            {
                fout << second << endl;
            }
        }
        fout.close();
    }
