/*
** EPITECH PROJECT, 2024
** main.c
** File description:
** main.c
*/

#include "include/my.h"

float get_cached(float *cached)
{
    FILE *file;
    char buffer[256];

    file = fopen("/proc/meminfo", "r");
    for (int i = 0; i <= 4; i++)
        fgets(buffer, sizeof(buffer), file);
    sscanf(buffer, "%*s %f", cached);
    fclose(file);
    return *cached;
}

float get_slab(float *slab)
{
    FILE *file;
    char buffer[256];

    file = fopen("/proc/meminfo", "r");
    for (int i = 0; i <= 19; i++)
        fgets(buffer, sizeof(buffer), file);
    sscanf(buffer, "%*s %f", slab);
    fclose(file);
    return *slab;
}
