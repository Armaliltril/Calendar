#include <stdio.h>
#include <signal.h>
#include <stdlib.h>
#include <time.h>
#include "handlers.h"
#include "calendar.h"

int main(int argc, char* argv[]) {
    const time_t timer = time(NULL);
    const struct tm* current_time = localtime(&timer);

    signal(SIGINT, intHandler);
    signal(SIGBREAK, breakHandler);

    printf("Hello\n");
    printCalendar(current_time);

    printf("Also we can show week number of input day.\n");
    printf("Try it: ");
    int day_num;
    scanf("%d", &day_num);

    printf("Week number: %d\n", getDayOfWeek(day_num, current_time->tm_mon + 1, current_time->tm_year + 1900));

    while (1){}
}



