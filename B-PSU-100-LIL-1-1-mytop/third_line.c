/*
** EPITECH PROJECT, 2024
** main.c
** File description:
** main.c
*/

#include "include/my.h"

cpu_usage_t get_cpu_usage(void)
{
    FILE *fp;
    char buffer[1024];
    cpu_usage_t usage = {0};

    fp = fopen("/proc/stat", "r");
    fgets(buffer, sizeof(buffer), fp);
    fclose(fp);
    sscanf(buffer, "cpu %lld %lld %lld %lld %lld %lld %lld %lld",
        &usage.user, &usage.nice, &usage.sys, &usage.idle,
        &usage.iowait, &usage.irq, &usage.softirq, &usage.steal);
    return usage;
}

void calculate_cpu_usage_diff(cpu_usage_t *prev_usage,
    cpu_usage_t *current_usage, long long int *diffs,
    long long int *total_diff)
{
    *total_diff = 0;
    diffs[0] = current_usage->user - prev_usage->user;
    diffs[1] = current_usage->nice - prev_usage->nice;
    diffs[2] = current_usage->sys - prev_usage->sys;
    diffs[3] = current_usage->idle - prev_usage->idle;
    diffs[4] = current_usage->iowait - prev_usage->iowait;
    diffs[5] = current_usage->irq - prev_usage->irq;
    diffs[6] = current_usage->softirq - prev_usage->softirq;
    diffs[7] = current_usage->steal - prev_usage->steal;
    for (int i = 0; i < 8; i++) {
        *total_diff += diffs[i];
    }
}

void print_cpu_usage()
{
    static cpu_usage_t prev_usage;
    cpu_usage_t current_usage = get_cpu_usage();
    long long int diffs[8];
    long long int total_diff;
    float percentages[8];

    calculate_cpu_usage_diff(&prev_usage, &current_usage, diffs, &total_diff);
    for (int i = 0; i < 8; i++) {
        percentages[i] = ((float)diffs[i] / total_diff) * 100;
    }
    mvprintw(2, 0, "%%Cpu(s): ");
    print_bold_cpu(percentages[0], " us, ");
    print_bold_cpu(percentages[2], " sy, ");
    print_bold_cpu(percentages[1], " ni, ");
    print_bold_cpu(percentages[3], " id, ");
    print_bold_cpu(percentages[4], " wa, ");
    print_bold_cpu(percentages[5], " hi, ");
    print_bold_cpu(percentages[6], " si, ");
    print_bold_cpu(percentages[7], " st");
    prev_usage = current_usage;
}
