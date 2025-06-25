/*
** EPITECH PROJECT, 2024
** main.c
** File description:
** main.c
*/

#include "include/my.h"

void set_priority(int priority, char *priority_str)
{
    if (priority <= -100) {
        snprintf(priority_str, 256, "rt");
    } else {
        snprintf(priority_str, 256, "%d", priority);
    }
}

void get_stat(int pid, processinfo_t *pinfo)
{
    FILE *file;
    char path[256];
    int priority;
    char temp_command[256];
    int uid;

    sprintf(path, "/proc/%d/stat", pid);
    file = fopen(path, "r");
    read_stat_file(file, pinfo, &priority);
    fclose(file);
    file = fopen(path, "r");
    read_command(file, temp_command);
    fclose(file);
    snprintf(pinfo->command, sizeof(pinfo->command), "%s", temp_command);
    set_priority(priority, pinfo->priority);
    sprintf(path, "/proc/%d/status", pid);
    file = fopen(path, "r");
    read_status_file(file, &uid);
    fclose(file);
    get_user_name(uid, pinfo->user, sizeof(pinfo->user));
}

void print_process_info(int row, processinfo_t *pinfo, long total_memory)
{
    double mem_percentage =
        (pinfo->rss * 4 * 1024) / (double)total_memory * 100;

    mvprintw(row, 0,
        "%7d %-8.8s %3s %3i %7.0f %6ld %6ld %c %5.1f %5.1f %.3d:%.2d.%.2d %s",
        pinfo->pid, pinfo->user, pinfo->priority, pinfo->nice,
        pinfo->vsize / 1024.0, pinfo->rss * 4,
        pinfo->shared * 4, pinfo->state,
        0.0, mem_percentage, 000, 00, 00, pinfo->command);
    refresh();
}

void print_processes()
{
    DIR *proc_dir = opendir("/proc");
    struct dirent *entry;
    int row = 7;
    int pid = 0;
    long total_memory = 1;
    processinfo_t pinfo;

    get_total_memory(&total_memory);
    entry = readdir(proc_dir);
    while (entry != NULL && row < LINES) {
        if (isdigit(entry->d_name[0])) {
            pid = atoi(entry->d_name);
            get_stat(pid, &pinfo);
            get_statm(pid, &pinfo);
            print_process_info(row++, &pinfo, total_memory);
        }
        entry = readdir(proc_dir);
    }
    closedir(proc_dir);
}
