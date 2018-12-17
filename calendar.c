//
// Created by 1 on 14.12.2018.
//

#include "calendar.h"
#include <stdlib.h>
#include <stdio.h>
#include <time.h>

char* days_of_week[] = {"SU", "MO", "TU", "WE", "TH", "FR", "SA"};
int days_in_month[]={0,31,28,31,30,31,30,31,31,30,31,30,31};

char* numberToMonthName(int monthNumber) {
    switch (monthNumber) {
        case 1 :
            return "January";
        case 2 :
            return "February";
        case 3 :
            return "March";
        case 4 :
            return "April";
        case 5 :
            return "May";
        case 6 :
            return "June";
        case 7 :
            return "July";
        case 8 :
            return "August";
        case 9 :
            return "September";
        case 10 :
            return "October";
        case 11 :
            return "November";
        case 12 :
            return "December";
        default :
            return "Error: Wrong name";
    }
}

int getDayOfWeek(int day, int month, int year) {
    int a = (14 - month) / 12;
    int y = year - a;
    int m = month + 12 * a - 2;
    return (day + y + y / 4 - y / 100 + y / 400 + (31 * m) / 12) % 7;
}

int numberOfDaysInYear(int year_num) {
    if(year_num % 4 == 0)
        if(year_num % 100 == 0 && year_num % 400)
            return 365;
        else
            return 366;
    return 365;
}

void printCalendar(const struct tm* time) {
    printf("\t%s of %d\n", numberToMonthName(time->tm_mon + 1), time->tm_year + 1900);
    for (int i = 0; i != 7; ++i) {
        printf("%2s ", days_of_week[i]);
    }
    printf("\n");


    int first_day_of_week = getDayOfWeek(1, time->tm_mon + 1, time->tm_year + 1900);

    for (int day = 0; day != first_day_of_week; ++day)
    {
        printf("   ");
    }

    int day_shift = getDayShift(time->tm_year + 1900) + first_day_of_week;

    for (int day = 1; day <= days_in_month[time->tm_mon + 1]; ++day) {
        printf("%2d", day);

        if ((day + day_shift) % 7 > 0)
            printf(" ");
        else
            printf("\n");
    }

    printf("\n");
}

int getDayShift(int year) {
    if (numberOfDaysInYear(year) == 366)
        return 1;
    else
        return 0;
}