#include <stdio.h>
#include <time.h>
#include <stdlib.h>

#include "Date.h"
#include "Time.h"

int main()
{
    //According to the "Time.h" standards, the countdown of years starts from 1900
    //therefore, please try to enter all dates starting from 1900, except for those where you need to add or subtract the date
    int n;
    printf("input date from console: press 1\n from file: press 2\nif you take a different value, it will be from the console\n");
    scanf("%d", &n);
    int d, m, y, s, h;
    struct tm aTm;
    struct tm b;
    struct tm c;
    if(n==2)
    {
        Input_DateFromFile(&aTm);
        printf("entered day month year for example\n21 3 2020");
    }
    else if(n==1)
    {
        printf ("enter date 1 \nday: ");
        scanf("%d", &d);
        printf("month: ");
        scanf("%d", &m);
        printf("year: ");
        scanf("%d", &y);
        SetDate(d, m, y, &aTm);
    }
    printf("output from console: press 1\n from file: press 2\nif you take a different value, it will be from the console\n");
    scanf("%d", &n);

    if(n==2)
    {
        Output_DateToFile(&aTm);
    }
    else
    {
        OutDate(&aTm);
    }
      week_day(&aTm);
    printf("\nNext date:\n");
    NextDate(&aTm, &b);
    OutDate(&b);
    printf("\nPrevious date:\n");
    PreDate(&aTm,&b);
    OutDate(&b);
    printf("enter date 2\nday: ");
    scanf("%d", &d);
    printf("month: ");
    scanf("%d", &m);
    printf("year: ");
    scanf("%d", &y);
    SetDate(d, m, y, &b);
    if(date1IsBigThendate2(&aTm,&b))
    {
        printf("date 1 > date 2\n");
    }
    else if(date1Isdate2(&aTm, &b))
    {
        printf("date 1 == date 2\n");
    }
    else
    {
        printf("date 1 < date 2\n");
    }
    printf("Enter the number of days to add/subtract dates 1: ");
    scanf ("%d", &n);
    printf("subtract\n");
    subtract_days(&aTm, n);
    OutDate(&aTm);
    printf("add\n");
    add_days(&aTm, n+n);
    OutDate(&aTm);
    subtract_days(&aTm, n);
    printf("Enter the date that we will add subtract from date 1 (date 3)\nday: ");
    scanf("%d", &d);
    printf("month: ");
    scanf("%d", &m);
    printf("year: ");
    scanf("%d", &y);
    printf("date1+date3\n");
    add_date(&aTm, d, m, y, &c);
    OutDate(&c);
    printf("date1-date3\n");
    subtract_date(&aTm, d, m, y, &c);
    OutDate(&c);
    n=DaysBetween2(&aTm, &b);
    printf("The number of days between the dates1 and date2: %d\n", n);
    n=DaysBetween(&aTm);
    printf("The number of days between the dates1 and 0 year: %d\n", n);



    struct tm k;
    struct tm f;
    struct tm g;
    printf("input time from console: press 1\n from file: press 2\nif you take a different value, it will be from the console\n");
    scanf("%d", &n);

    if(n==2)
    {
        printf("entered days hours minutes seconds, for example\n110 23 59 59");
        SetTimeFromFile(&aTm);
    }
    else
    {
       printf("enter time1\nday: ");
       scanf("%d", &d);
       printf ("hour: ");
       scanf("%d", &h);
       printf("minute: ");
       scanf("%d", &m);
       printf("second: ");
       scanf("%d", &s);
       SetTime(&k, d, h, m, s);
    }
    printf("input from console: press 1\n from file: press 2\nif you take a different value, it will be from the console\n");
    scanf("%d", &n);

    if(n==2)
    {
        OutTimeToFile(&k);
    }
    else
    {
        OutTime(&k);
    }
    printf("Made time out of date1\n");
    FromDateToTime(&aTm, &f);
    OutTime(&f);
    printf("Enter the number of days to add/subtract time 1: ");
    scanf("%d", &n);
    printf("divade\n");
    divade(&k, n);
    OutTime(&k);
    printf("multipl\n");
    multipl(&k, n*n);
    OutTime(&k);
    divade(&k,n);
    printf ("enter time2\nday: ");
    scanf("%d", &d);
    printf ("hour: ");
    scanf("%d", &h);
    printf("minute: ");
    scanf("%d", &m);
    printf("second: ");
    scanf("%d", &s);
    SetTime(&f, d, h, m, s);
    printf("time1+time2\n");
    add_time(&k, &f, &g);
    OutTime(&g);
    OutTime(&g);
    printf("date1+time1\n");
    add_timedata(&k, &aTm, &g);
    OutTime(&g);
    getchar();
    return 0;

}
