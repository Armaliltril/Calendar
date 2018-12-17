//
// Created by 1 on 14.12.2018.
//

#ifndef TIMETABLE_OS_CALENDAR_H
#define TIMETABLE_OS_CALENDAR_H

#include <time.h>

char* numberToMonthName(int);

int getDayOfWeek(int day, int month, int year);

int numberOfDaysInYear(int);

int getDayShift(int);

void printCalendar(const struct tm*);

#endif //TIMETABLE_OS_CALENDAR_H
