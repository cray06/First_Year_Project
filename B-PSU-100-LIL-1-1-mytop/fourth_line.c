/*
** EPITECH PROJECT, 2024
** main.c
** File description:
** main.c
*/

#include "include/my.h"

float get_total(float *total)
{
    FILE *file;
    char buffer[256];

    file = fopen("/proc/meminfo", "r");
    if (file == NULL)
        return 0;
    if (fgets(buffer, sizeof(buffer), file) != NULL) {
        sscanf(buffer, "MemTotal: %f kB", total);
    }
    fclose(file);
    return *total;
}

float get_free(float *free)
{
    FILE *file;
    char buffer[256];

    file = fopen("/proc/meminfo", "r");
    if (file == NULL)
        return 0;
    for (int i = 0; i <= 1; i++) {
        fgets(buffer, sizeof(buffer), file);
    }
    sscanf(buffer, "MemFree: %f kB", free);
    fclose(file);
    return *free;
}

float get_available(float *available)
{
    FILE *file;
    char buffer[256];

    file = fopen("/proc/meminfo", "r");
    if (file == NULL)
        return 0;
    for (int i = 0; i <= 2; i++) {
        fgets(buffer, sizeof(buffer), file);
    }
    sscanf(buffer, "MemAvailable: %f kB", available);
    fclose(file);
    return *available;
}

float get_buffers(float *buffers)
{
    FILE *file;
    char buffer[256];

    file = fopen("/proc/meminfo", "r");
    if (file == NULL)
        return 0;
    for (int i = 0; i <= 3; i++) {
        fgets(buffer, sizeof(buffer), file);
    }
    sscanf(buffer, "Buffers: %f kB", buffers);
    fclose(file);
    return *buffers;
}

void mib_mem(void)
{
    float total = get_total(&total);
    float free = get_free(&free);
    float available = get_available(&available);
    float buffers = get_buffers(&buffers);
    float cached = get_cached(&cached);
    float used = 0;
    float slab = get_slab(&slab);

    used = total - available;
    mvprintw(3, 0, "MiB Mem : ");
    print_bold_float(total / 1024.0, " total,   ");
    print_bold_float(free / 1024.0, " free,   ");
    print_bold_float(used / 1024.0, " used,   ");
    print_bold_float((buffers + cached + slab) / 1024.0, " buff/cache");
    print_bold_float_ava(available / 1024.0, " avail Mem");
    refresh();
}
