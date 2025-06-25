/*
** EPITECH PROJECT, 2024
** main.c
** File description:
** main.c
*/

#include "include/my.h"

void print_bold_int(const int integer)
{
    attron(A_BOLD);
    printw("%3d", integer);
    attroff(A_BOLD);
}

void print_bold_cpu(const float nbr, char *str)
{
    attron(A_BOLD);
    printw("%4.1f", nbr);
    attroff(A_BOLD);
    printw("%s", str);
}

void print_bold_float(const float nbr, char *str)
{
    attron(A_BOLD);
    printw("%6.1f", nbr);
    attroff(A_BOLD);
    printw("%s", str);
}

void print_bold_float_ava(const float nbr, char *str)
{
    attron(A_BOLD);
    mvprintw(4, 56, "%6.1f", nbr);
    attroff(A_BOLD);
    printw("%s", str);
}
