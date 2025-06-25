/*
** EPITECH PROJECT, 2024
** main.c
** File description:
** main.c
*/

#include "include/my.h"

void read_stat_file(FILE *file, processinfo_t *pinfo, int *priority)
{
    fscanf(file, "%d %*s %c %*d %*d %*d %*d %*d %*u %*u %*u %*u %*u %*u"
    "%*u %*d %*d %d %d %*d %*d %*u %llu",
    &pinfo->pid, &pinfo->state, priority, &pinfo->nice, &pinfo->vsize);
}

void read_command(FILE *file, char *temp_command)
{
    char *end;

    fscanf(file, "%*d (");
    fgets(temp_command, 256, file);
    end = strchr(temp_command, ')');
    if (end != NULL) {
        *end = '\0';
    }
}

void read_status_file(FILE *file, int *uid)
{
    char line[256];

    while (fgets(line, sizeof(line), file) && strncmp(line, "Uid:", 4) != 0);
    if (strncmp(line, "Uid:", 4) == 0) {
        sscanf(line + 4, "%d", uid);
    }
}

void get_statm(int pid, processinfo_t *pinfo)
{
    FILE *filem;
    char pathm[256];

    sprintf(pathm, "/proc/%d/statm", pid);
    filem = fopen(pathm, "r");
    if (filem == NULL)
        return;
    fscanf(filem, "%*d %ld %ld", &pinfo->rss, &pinfo->shared);
    fclose(filem);
}

void get_total_memory(long *total_memory)
{
    FILE *file = fopen("/proc/meminfo", "r");
    char line[256];

    if (file == NULL) {
        *total_memory = 1;
        return;
    }
    while (fgets(line, sizeof(line), file)) {
        if (strncmp(line, "MemTotal:", 9) == 0) {
            sscanf(line + 9, "%ld", total_memory);
            *total_memory *= 1024;
            break;
        }
    }
    fclose(file);
}
