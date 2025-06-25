/*
** EPITECH PROJECT, 2024
** main.c
** File description:
** main.c
*/

#include "include/my.h"

void print_first_line(void)
{
    print_current_time();
    print_uptime();
    user_number();
    load_avg();
}

void print_second_line(void)
{
    print_tasks_value();
}

void print_third_line(void)
{
    print_cpu_usage();
}

void print_fourth_line(void)
{
    mib_mem();
}

void print_fifth_line(void)
{
    swap_memory();
}
