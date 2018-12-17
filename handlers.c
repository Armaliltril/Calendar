//
// Created by 1 on 14.12.2018.
//

#include "handlers.h"
#include "calendar.h"
#include <signal.h>
#include <stdio.h>
#include <stdlib.h>

void intHandler(int sig) {
    static int num_pressed = 0;
    num_pressed += 1;

    signal(SIGINT, intHandler);

    printf("Oh, you pressed Ctrl+C. ");
    printf("%d time!\n", num_pressed);

    if (num_pressed == 3) {
        printf("Fine!.. It's enough\n");
        printf("Type year number: ");
        int year_num;
        scanf("%d", &year_num);
        printf("Number of days in this year: %d", numberOfDaysInYear(year_num));
        exit(0);
    }
}

void breakHandler(int sig) {
    exit(0);
}