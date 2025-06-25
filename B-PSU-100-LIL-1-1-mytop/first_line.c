/*
** EPITECH PROJECT, 2024
** main.c
** File description:
** main.c
*/

#include "include/my.h"

void print_current_time(void)
{
    FILE *file;
    char buffer[256];
    int hours;
    int minutes;
    int seconds;
    char *time_str = NULL;

    file = fopen("/proc/driver/rtc", "r");
    if (fgets(buffer, sizeof(buffer), file) != NULL)
        time_str = buffer + 11;
    fclose(file);
    if (time_str != NULL) {
        hours = (time_str[0] - '0') * 10 + (time_str[1] - '0');
        minutes = (time_str[3] - '0') * 10 + (time_str[4] - '0');
        seconds = (time_str[6] - '0') * 10 + (time_str[7] - '0');
        hours = (hours + 1) % 24;
        mvprintw(0, 0, "top - %.2d:%.2d:%.2d ", hours, minutes, seconds);
    }
}

void get_uptime(double *uptime)
{
    int fd = 0;
    char buffer[128];
    ssize_t bytes_reads;

    fd = open("/proc/uptime", O_RDONLY);
    if (fd == -1) {
        *uptime = -1;
        return;
    }
    bytes_reads = read(fd, buffer, sizeof(buffer) - 1);
    if (bytes_reads == -1) {
        *uptime = -1;
        close(fd);
        return;
    }
    buffer[bytes_reads] = '\0';
    *uptime = atof(buffer);
    close(fd);
}

void print_uptime(void)
{
    double uptime = 0;
    int days = 0;
    int hours = 0;
    int minutes = 0;

    get_uptime(&uptime);
    if (uptime < 0)
        return;
    days = (int)uptime / (3600 * 24);
    hours = ((int)uptime % (3600 * 24)) / 3600;
    minutes = ((int)uptime % 3600) / 60;
    print_uptime_message(days, hours, minutes);
    refresh();
}

void user_number(void)
{
    int fd;
    struct utmp ut;
    int user_count = 0;

    fd = open("/var/run/utmp", O_RDONLY);
    if (fd == -1) {
        user_count = 0;
        printw("%3d user,", user_count);
        return;
    }
    while (read(fd, &ut, sizeof(ut))) {
        if (ut.ut_type == USER_PROCESS) {
            user_count++;
        }
    }
    close(fd);
    if (user_count <= 1)
        printw("%3d user,", user_count);
    else
        printw("%3d users,", user_count);
}

void load_avg(void)
{
    int fd;
    char buffer[256];
    char *loadavg;

    fd = open("/proc/loadavg", O_RDONLY);
    if (fd == -1)
        return;
    if (read(fd, buffer, 14) > 0) {
        buffer[14] = '\0';
        loadavg = buffer;
    }
    close(fd);
    printw("  load average: %.4s,%.5s,%.5s",
        loadavg, loadavg + 4, loadavg + 9);
}
