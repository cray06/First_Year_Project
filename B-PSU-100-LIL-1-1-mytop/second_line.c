/*
** EPITECH PROJECT, 2024
** main.c
** File description:
** main.c
*/

#include "include/my.h"

int is_process_dir(const struct dirent *entry)
{
    return isdigit(entry->d_name[0]);
}

char get_process_state(const char *pid)
{
    char path[256];
    int fd = 0;
    char buffer[1024];
    int bytes_read = 0;
    char *state_ptr;

    strcpy(path, "/proc/");
    strcat(path, pid);
    strcat(path, "/stat");
    fd = open(path, O_RDONLY);
    bytes_read = read(fd, buffer, sizeof(buffer) - 1);
    close(fd);
    buffer[bytes_read] = '\0';
    state_ptr = strchr(buffer, ')');
    return *(state_ptr + 2);
}

void count_process(int *running, int *stopped, int *zombie)
{
    DIR *proc_dir = opendir("/proc");
    struct dirent *entry;
    char state;

    entry = readdir(proc_dir);
    while (entry != NULL) {
        if (!is_process_dir(entry)) {
            entry = readdir(proc_dir);
            continue;
        }
        state = get_process_state(entry->d_name);
        if (state == 'R')
            (*running)++;
        if (state == 'T')
            (*stopped)++;
        if (state == 'Z')
            (*zombie)++;
        entry = readdir(proc_dir);
    }
    closedir(proc_dir);
}

void total_process(int *total)
{
    DIR *proc_dir;
    struct dirent *entry;

    proc_dir = opendir("/proc");
    entry = readdir(proc_dir);
    while (entry != NULL) {
        if (isdigit(entry->d_name[0]))
            (*total)++;
        entry = readdir(proc_dir);
    }
    closedir(proc_dir);
}

void print_tasks_value()
{
    int running = 0;
    int sleeping = 0;
    int stopped = 0;
    int zombie = 0;
    int total = 0;

    count_process(&running, &stopped, &zombie);
    total_process(&total);
    sleeping = total - stopped - zombie - running;
    mvprintw(1, 0, "Tasks: ");
    print_bold_int(total);
    printw(" total, ");
    print_bold_int(running);
    printw(" running, ");
    print_bold_int(sleeping);
    printw(" sleeping, ");
    print_bold_int(stopped);
    printw(" stopped, ");
    print_bold_int(zombie);
    printw(" zombie");
}
