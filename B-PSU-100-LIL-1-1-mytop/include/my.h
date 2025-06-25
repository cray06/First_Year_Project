/*
** EPITECH PROJECT, 2024
** my.h
** File description:
** my.h
*/

#ifndef MY_H
    #define MY_H

    #include <stdio.h>
    #include <stdlib.h>
    #include <ncurses.h>
    #include <dirent.h>
    #include <ctype.h>
    #include <unistd.h>
    #include <time.h>
    #include <fcntl.h>
    #include <string.h>
    #include <utmp.h>
    #include <pwd.h>

typedef struct cpu_usage {
    unsigned long long int user;
    unsigned long long int nice;
    unsigned long long int sys;
    unsigned long long int idle;
    unsigned long long int iowait;
    unsigned long long int irq;
    unsigned long long int softirq;
    unsigned long long int steal;
} cpu_usage_t;

typedef struct {
    int pid;
    char user[32];
    char priority[4];
    int nice;
    long long int vsize;
    long rss;
    long shared;
    char state;
    char command[256];
    double total_time;
} processinfo_t;

void print_first_line(void);
void print_second_line(void);
void print_third_line(void);
void print_fourth_line(void);
void print_fifth_line(void);
void print_top(void);
void print_white_line(void);
void print_current_time(void);
void print_uptime(void);
void user_number(void);
void load_avg(void);
void print_tasks_value(void);
void print_cpu_usage(void);
void mib_mem(void);
void swap_memory(void);
void print_processes(void);
void get_user_name(int uid, char *user_name, size_t size);
void set_priority(int priority, char *priority_str);
void get_stat(int pid, processinfo_t *pinfo);
void get_statm(int pid, processinfo_t *pinfo);
void get_total_memory(long *total_memory);
void read_stat_file(FILE *file, processinfo_t *pinfo, int *priority);
void read_command(FILE *file, char *temp_command);
void read_status_file(FILE *file, int *uid);
void print_process_info(int row, processinfo_t *pinfo, long total_memory);
void count_process(int *running, int *stopped, int *zombie);
void total_process(int *total);
int is_process_dir(const struct dirent *entry);
char get_process_state(const char *pid);
cpu_usage_t get_cpu_usage(void);
void calculate_cpu_usage_diff(cpu_usage_t *prev_usage,
    cpu_usage_t *current_usage, long long int *diffs,
    long long int *total_diff);
float get_total(float *total);
float get_free(float *free);
float get_available(float *available);
float get_buffers(float *buffers);
float get_cached(float *cached);
float get_slab(float *slab);
void print_bold_int(const int integer);
void print_bold_cpu(const float nbr, char *str);
void print_bold_float(const float nbr, char *str);
void print_bold_float_ava(const float nbr, char *str);
void print_uptime_message(int days, int hours, int minutes);
char **my_str_to_word_array(char const *str);

#endif
