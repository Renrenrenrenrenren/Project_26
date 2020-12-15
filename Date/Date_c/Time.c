#include "Time.h"

void OutTimeToFile(struct tm* aTm)
{
    FILE *f;
    char output_file[BUFSIZ];
    printf("Enter output file's name:\n");
    scanf("%s", output_file); // prompt output file's name
    f= fopen(output_file, "w");
    fprintf(f, "%d.%02d.%02d.%02d \n", aTm->tm_yday, aTm->tm_hour, aTm->tm_min, aTm->tm_sec);
    fclose(f);
}
void OutTime(struct tm * a)
{
   printf("%d.%02d.%02d.%02d \n", a->tm_yday, a->tm_hour, a->tm_min, a->tm_sec);
}
void SetTimeFromFile (struct tm* aTm)
{
    FILE *f;
    char input_file[BUFSIZ];
    printf("Enter input file's name: ");
    scanf("%s", input_file); // prompt input file's name
    f= fopen(input_file, "r");
    int d, h, m, s;
    if (f==NULL)
    {
        printf("incorect input file name");
    }
    else
    {
        fscanf(f, "%d", &d);
        fscanf(f, "%d", &h);
        fscanf (f, "%d", &m);
        fscanf (f, "%d", &s);
    }
    fclose(f);
    SetTime(aTm, d, h, m, s);
}
void SetTime(struct tm* a, int day, int hour, int minute, int second) //sets a time value to a structure
{
    a->tm_yday=day;
    a->tm_hour=hour;
    a->tm_min=minute;
    a->tm_sec=second;
        if (hour >= 24 || hour < 0)
        //if the hours are more than 24 or less than zero
		{
		    printf ("Incorrect time value");
            exit(0);
		}
		if (minute >= 60 || minute < 0)
		//if minutes are more than 60 or less than zero
		{
		    printf ("Incorrect time value");
            exit(0);
		}
		if (second >= 60 || second < 0)
        //if seconds are more than 60 or less than zero
		{
		    printf ("ÂIncorrect time value");
			exit(0);
		}
		if (day < 0)
		//if days are less than zero
		{
		    printf ("Incorrect time value");
			exit(0);
		}
}
bool Time1IsBigThenTime2 (struct tm* a, struct tm* b)
// check if the time data in the structure a is greater than the time given in the structure b
//return 1 if it is, and 0 if if isn't
{
    if (a->tm_yday == b->tm_yday) //checking the day
		{
			if (a->tm_hour == b->tm_hour) //checking the hour
			{
				if (a->tm_min == b->tm_min) //checking the minute
				{
					return a->tm_sec > b->tm_sec; //checking the second
				}
				else return a->tm_min > b->tm_min;
			}
			else return a->tm_hour > b->tm_hour;
		}
		else return a->tm_yday > b->tm_yday;
}
bool Time1IsTime2 (struct tm* a, struct tm* b)
//Check if the date that given in structs aTm1 and aTm2 are the same
//return 1 if it is, and 0 if if isn't
{
    return (a->tm_yday==b->tm_yday&&a->tm_hour==b->tm_hour&&a->tm_min==b->tm_min&&a->tm_sec==b->tm_sec);
}
void add_time (struct tm* a, struct tm* b,struct tm* s)
//add time is given in structure a and b, the result is set in the structure s
{
        long int n = a->tm_sec + a->tm_min * 60 + a->tm_hour * 60 * 60 + a->tm_yday * 24 * 60 * 60 + b->tm_sec + b->tm_min * 60 + b->tm_hour * 60 * 60 + b->tm_yday * 24 * 60 * 60;
		//convert time is given in structures a and b into seconds and add them
		s->tm_sec = n % 60;
		n = (n - (n % 60)) / 60;
		s->tm_min = n % 60;
		n = (n - (n % 60)) / 60;
		s->tm_hour = n % 24;
		n = (n - (n % 24)) / 24;
		s->tm_yday = n;
}
void multipl(struct tm* a, int k) //multiply the time by number k
{
    long int n = a->tm_sec + a->tm_min * 60 + a->tm_hour * 60 * 60 + a->tm_yday * 24 * 60 * 60;
    //convert time is given in structures a into seconds
    n *= k;
    a->tm_sec = n % 60;
    n = (n - (n % 60)) / 60;
    a->tm_min = n % 60;
    n = (n - (n % 60)) / 60;
    a->tm_hour = n % 24;
    n = (n - (n % 24)) / 24;
    a->tm_yday = n;
}
void divade(struct tm* a, int k) //divide the time given in the structure by number k
{
    long int n = a->tm_sec + a->tm_min * 60 + a->tm_hour * 60 * 60 + a->tm_yday * 24 * 60 * 60;
    //convert time is given in structures into seconds
    n /= k;
    a->tm_sec = n % 60;
    n = (n - (n % 60)) / 60;
    a->tm_min = n % 60;
    n = (n - (n % 60)) / 60;
    a->tm_hour = n % 24;
    n = (n - (n % 24)) / 24;
    a->tm_yday = n;
}
void add_timedata(struct tm* time, struct tm* date,struct tm* s)
//add the date and time given in the appropriate structures, the result is set in the structure s
{
    s->tm_sec=time->tm_sec;
    s->tm_min=time->tm_min;
    s->tm_hour=time->tm_hour;
    s->tm_mday=date->tm_mday;
    s->tm_mon=date->tm_mon;
    s->tm_year=date->tm_year;
    //Set in the structure with the value of hours, seconds, minutes of a given time, and the value of the days, months, years given in date
    add_days(s, time->tm_yday);
}
int getDaysFromTime(struct tm* a)//returns the number of days from time
{
    return a->tm_yday;
}
void FromDateToTime (struct tm* date, struct tm* time) //reformatting from date to time,timethe result is set in the structure
{
    int n = DaysBetween(date);
    SetTime(time, n, 0, 0, 0);
}
