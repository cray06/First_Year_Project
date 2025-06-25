/*
** EPITECH PROJECT, 2024
** main.c
** File description:
** main.c
*/

#include "include/my.h"

void swap_memory(void)
{
    FILE *file;
    char buffer[256];
    float total = 0;
    float free = 0;
    float used = 0;

    file = fopen("/proc/swaps", "r");
    if (file == NULL)
        return;
    for (int i = 0; i < 2; i++)
        fgets(buffer, sizeof(buffer), file);
    fclose(file);
    sscanf(buffer, "%*s %*s %f %f", &total, &used);
    free = total - used;
    mvprintw(4, 0, "MiB Swap: ");
    print_bold_float(total / 1024, " total,   ");
    print_bold_float(free / 1024, " free,   ");
    print_bold_float(used / 1024, " used.");
    refresh();
}
