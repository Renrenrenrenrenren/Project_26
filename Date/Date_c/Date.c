#include "Date.h"

void  Output_DateToFile(struct tm* aTm) //outputting the date value to a file
{
    FILE *f;
    char output_file[BUFSIZ];
    printf("Enter output file's name:\n");
    scanf("%s", output_file); // prompt output file's name
    f= fopen(output_file, "w");
    fprintf(f,"%04d.%02d.%02d \n",aTm->tm_year+1900, aTm->tm_mon+1, aTm->tm_mday);
    char s[40];
    strftime(s, 40, "%d %B %Y \n", aTm);
    fprintf (f,"%s", s);
    fclose(f);
}
void Input_DateFromFile(struct tm* aTm) //Input date value from a file
{
    FILE *f;
    char input_file[BUFSIZ];
    printf("Enter input file's name: ");
    scanf("%s", input_file); // prompt input file's name
    f= fopen(input_file, "r");
    int d, m, y;
    if (f==NULL)
    {
        printf("error input file open");
    }
    else
    {
        fscanf(f, "%d", &d);
        fscanf(f, "%d", &m);
        fscanf (f, "%d", &y);
    }
    fclose(f);
    SetDate( d, m, y, aTm);
}

void SetDate(int day, int month, int year, struct tm * aTm) //setting the value date in struct aTm
{
    aTm->tm_year=year-1900;
    aTm->tm_mon=month-1;
    aTm->tm_mday=day;
    int x = 0;
    if ((year % 4 == 0 && year % 100 != 0) || year % 400 == 0) //checking for leap year
    {
        x = 1; //if year is leap
    }
    while (day > 31 && (month == 1 || month == 3 || month == 5 || month == 7 || month == 8 || month == 10 || month == 12))
    //If the days in January, March, May, July, August, October, December are more than 31
    {
        printf("Incorrect date value");
        exit(0);
    }
    while (day > 30 && (month == 4 || month == 6 || month == 9 || month == 11))
    //If there are more than 30 days in April June September November
    {
        printf("Incorrect date value");
        exit(0);
    }
    while (month == 2 && x == 1 && day > 29)
    //If the year is a leap year and the number of days in February is more than 29
    {
        printf ("Incorrect date value");
        exit(0);
    }
    while (month == 2 && x == 0 && day > 28)
    //If the year is not a leap year and the number of days in February is more than 28
    {
        printf ("Incorrect date value");
        exit(0);
    }
    while (month > 12 || month < 1 || day < 1 ||year<0)
    //If months are more than 12, or months are less than 1, or days are less than 1
    {
        printf ("Incorrect date value");
        exit(0);
    }
}

void OutDate (struct tm* aTm)
{
   printf("%04d.%02d.%02d \n",aTm->tm_year+1900, aTm->tm_mon+1, aTm->tm_mday);
   char s[40];
   strftime(s, 40, "%d %B %Y \n", aTm);
   printf ("%s", s);
}
void NextDate(struct tm* th, struct tm* next) //determining the next day's date value
//in structure th the given date, in structure next set date value of the next day
{
    int m = th->tm_mon, d = th->tm_mday, y=th->tm_year;
    if ( d == 31 && m!=11) //if the given date is 31 day of some month (except December) some year
    {
        next->tm_mon = m+1; next->tm_mday = 1; next->tm_year = y;
    }
    else if (d == 30 && (m == 3 || m == 5 || m == 8 || m == 10))
    //if the given date is 30 day of April, or June, or September or November some year
    {
        next->tm_mon = m + 1; next->tm_mday = 1; next->tm_year = y;
    }
    else if (d == 29 && m == 1)
    //if the given date is February 29 some year
    {
        next->tm_mon = m + 1; next->tm_mday = 1; next->tm_year = y;
    }
    else if ((d == 28 && m == 1)) //if the given date is February 28 some year
    {
        bool x = 0;
        //checking a leap year
        if((y+1900)%4==0)
        {
            x = 1;
        }
        if ((y + 1900 )% 100 == 0)
        {
            x = 0;
        }
        if ((y + 1900 % 400) == 0)
        {
            x = 1;
        }
        if (x==1)//if year is leap
        {
            next->tm_mon = m; next->tm_mday = 29; next->tm_year = y;
        }
        else //if year is not leap
        {
            next->tm_mon = m + 1; next->tm_mday = 1; next->tm_year = y;
        }
    }
    else if (m == 11 && d == 31) // if the given date is December 31 some year
    {
        next->tm_mon = 0; next->tm_mday = 1; next->tm_year = y + 1;
    }
    else //if the given date is not the end of the month
    {
        next->tm_mon = m; next->tm_mday = d + 1; next->tm_year = y;
    }
}
void PreDate(struct tm* aTm, struct tm* preaTm)     //determining the next day's date value
//in structure th the given date, in structure next set date value of the next day
{
    int m = aTm->tm_mon, y = aTm->tm_year, d = aTm->tm_mday;
    if (m == 0 && d == 1) //if the given date is January 1 some year
    {
        preaTm->tm_mday = 31; preaTm->tm_mon = 11; preaTm->tm_year = y - 1;
    }
    else if ((m == 1 || m == 3 || m == 5 || m == 7 || m == 8 || m == 10) && d == 1)
    //if the given date is 1 day of February, or April, or July, or August, or September, or November some year
    {
        preaTm->tm_mday = 31; preaTm->tm_mon = m-1; preaTm->tm_year = y;
    }
    else if ((m == 4 || m == 6 || m == 9 || m == 11) && d == 1)
    //if the given date is 1 day of May, or June, or October, or December some year
    {
        preaTm->tm_mday = 30; preaTm->tm_mon = m-1; preaTm->tm_year = y;
    }
    else if (d == 1 && m == 2) //if the given date is March 1 some year
    {
        bool x = 0;
        //checking a leap year
        if((y+1900)%4==0)
        {
            x = 1;
        }
        if ((y + 1900 )% 100 == 0)
        {
            x = 0;
        }
        if ((y + 1900 % 400) == 0)
        {
            x = 1;
        }
        if (x==1) //if year is leap
        {
            preaTm->tm_mday = 29; preaTm->tm_mon = m - 1; preaTm->tm_year = y;
        }
        else //if year is not leap
        {
            preaTm->tm_mday = 28; preaTm->tm_mon = m - 1; preaTm->tm_year = y;
        }
    }
    else  //if the given date is not the start of the month
    {
        preaTm->tm_mday = d-1 ; preaTm->tm_mon = m; preaTm->tm_year = y;
    }
}
bool date1IsBigThendate2(struct tm* aTm1, struct tm* aTm2)
//checks if the date given in structure aTm1 is greater than the date given in struct
//return 1 if it is, and 0 if if isn't
{
    return (aTm1->tm_year==aTm2->tm_year&&aTm1->tm_mon==aTm2->tm_mon&&aTm1->tm_mday>aTm2->tm_mday)||(aTm1->tm_year==aTm2->tm_year&&aTm1->tm_mon>aTm2->tm_mon)||(aTm1->tm_year>aTm2->tm_year);
}
void add_days (struct tm* aTm, int n)//adds n days to the date, given in the struct aTm
{
    for(int i=0; i<n; i++)
    {
        NextDate(aTm, aTm); //resetting the date, given in the structure aTm to next date n times
    }
}
void subtract_days (struct tm* aTm, int n) //subtracts n days from the date, given in the struct aTm
{
    for( int i=0; i<n-1; i++)
        {
         PreDate(aTm, aTm); //resetting the date, given in the structure aTm to previous date n times
        }
}
bool date1Isdate2(struct tm* aTm1, struct tm* aTm2)
//Check if the date that given in structs aTm1 and aTm2 are the same
//return 1 if it is, and 0 if if isn't
{
    return (aTm1->tm_year==aTm2->tm_year&&aTm1->tm_mon==aTm2->tm_mon&&aTm1->tm_mday==aTm2->tm_mday);
}
void week_day (struct tm * aTm)
{
   struct tm *a = (struct tm*) calloc(1, sizeof(struct tm));
   SetDate(1,1, 1900, a);
    int n=2;
    while (!date1Isdate2(aTm, a))
    {
        NextDate (a,a);
        n++;
    }
   char s[20];
   aTm->tm_wday=n%7;
   for (int i = 0; i<20; i++) s[i] = 0;
   strftime(s, 20, "%A \n", aTm);
   printf ("%s", s);
   free(a);
}
int DaysBetween(struct tm * aTm) //Determine the number of days between the date of the given struct aTm and the zero year
{
    struct tm *a = (struct tm*) calloc(1, sizeof(struct tm)); //Declaring and allocating memory for the auxiliary structure
    SetDate(1,1, 1900, a); //We set the minimum date value allowed by the "time.h"
    int n=693961; //Since in the time.h" the countdown has been carried out since 1900, the initial number of days is the number of days between 1900 and zero year
    while (!date1Isdate2(aTm, a))
    {
        NextDate (a,a); //add one day to the auxiliary date, until it equals the given date
        n++;
    }
    free (a); //Freeing memory allocated for auxiliary and structure
    return n;
}
int DaysBetween2(struct tm * a, struct tm * b) //determines the number of days between two dates
{
     int n1 = DaysBetween(a);// Determine the number of days between Year and date a
     int n2 = DaysBetween(b); // Determine the number of days between New Year and date b
     if (n1-n2>0) return n1-n2;
     else return n2-n1;
     //return the difference of days that is greater than zero
}
void subtract_date(struct tm* a, int d, int m, int y, struct tm* c)
//subtract from the date given in the struct a the date given by prime numbers. Result setting structure c
{
   SetDate(d, m, y+1900, c); //Set the date given by prime numbers to the structure c, increase the value of the year by 1900
   int n=DaysBetween(c)-693960; //the number of days between a date specified by prime numbers and a zero year
   SetDate(a->tm_mday, a->tm_mon+1, a->tm_year+1900, c); //set in the structure c the value of the date given in the structure a
   subtract_days (c,n);//structure c set the date given in struct a subtract date value given by prime numbers
}
void add_date(struct tm* a, int day2, int month2, int year2, struct tm* c)
//add to the date given in the struct a the date given by prime numbers. Result setting structure c
{
   SetDate(day2, month2, year2+1900, c);//Set the date given by prime numbers to the structure c, increase the value of the year by 1900
   int n=DaysBetween(c)-693960; //the number of days between a date specified by prime numbers and a zero year
   SetDate(a->tm_mday, a->tm_mon+1, a->tm_year+1900, c); //set in the structure c the value of the date given in the structure a
   add_days (c,n);////structure c set the date given in struct a add date value given by prime numbers
}
