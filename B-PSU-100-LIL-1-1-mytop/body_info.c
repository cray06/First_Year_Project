/*
** EPITECH PROJECT, 2024
** main.c
** File description:
** main.c
*/

#include "include/my.h"

void print_white_line(void)
{
    int col = 78;

    attron(A_STANDOUT);
    mvprintw(6, 0, "    PID USER");
    printw("      PR  NI");
    printw("    VIRT    RES");
    printw("    SHR S  %%CPU  %%MEM");
    printw("     TIME+ COMMAND");
    while (col < COLS - 1) {
        printw(" ");
        col++;
    }
    attroff(A_STANDOUT);
}

void print_top(void)
{
    print_first_line();
    print_second_line();
    print_third_line();
    print_fourth_line();
    print_fifth_line();
    print_white_line();
}
