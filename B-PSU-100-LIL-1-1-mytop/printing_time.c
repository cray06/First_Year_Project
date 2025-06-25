/*
** EPITECH PROJECT, 2024
** main.c
** File description:
** main.c
*/

#include "include/my.h"

void print_uptime_message(int days, int hours, int minutes)
{
    if (days > 0) {
        if (days == 1)
            printw("up %d day, %d:%02d,", days, hours, minutes);
        else
            printw("up %d days, %d:%02d,", days, hours, minutes);
    } else if (hours > 0)
        printw("up %d:%02d,", hours, minutes);
    else
        printw("up %d min,", minutes);
}
