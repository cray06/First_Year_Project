/*
** EPITECH PROJECT, 2024
** my.h
** File description:
** my.h
*/

#ifndef MY_H
    #define MY_H

    #include <stdbool.h>
    #include <stdlib.h>
    #include <stddef.h>
    #include <stdio.h>
    #include <stdarg.h>
    #include <dirent.h>
    #include <string.h>
    #include <errno.h>
    #include <sys/stat.h>
    #include <pwd.h>
    #include <grp.h>
    #include <time.h>
    #include <sys/types.h>
    #include <unistd.h>

struct FileInfo {
    char *name;
    char permissions[11];
    int links;
    char *owner;
    char *group;
    int size;
    char *mod_time;
    time_t mod_time_comp;
};

struct DirectoryContent {
    struct FileInfo *files;
    int count;
};

struct TimeSortingParams {
    struct DirectoryContent *content;
    char *flags;
    char *argv;
    int argc;
    int count;
};

void file_information(DIR *dir, struct DirectoryContent *content, char *flags,
    int *count);
void create_array(struct DirectoryContent *content, int count);
void print_file_names(struct DirectoryContent *content, int count);
void free_memory(struct DirectoryContent *content);
void print_files_in_directory(DIR *dir, char *flags, int argc, char *argv);
void sort_files(struct DirectoryContent *content, int count, char *flags);
void my_swap_files(struct FileInfo *a, struct FileInfo *b);
int my_strcasecmp(const char *s1, const char *s2);
DIR* open_directory(const char *path);
void display_directory_contents(int argc, char *argv[], char *flags);
void display_multiple_directories(int argc, char *argv[], char *flags);
char *get_flag(int *argc, char *argv[]);
bool include_hidden(char *flags);
bool only_current(char *flags);
bool reverse_list(char *flags);
void my_putchar(char c);
int my_putstr(char const *str);
char *my_strchr(char *s, int c);
char *my_strdup(char const *src);
int my_strlen(char const *str);
void get_file_info(const char *filename, struct FileInfo *file_info);
void get_permissions(mode_t mode, char *permissions);
bool long_print(char *flags);
char *my_strcpy(char *dest, char const *src);
char *my_strcat(char *dest, char const *src);
int my_put_nbr(int nb);
char *my_strncpy(char *dest, char const *src, int n);
char *my_strcat(char *dest, char const *src);
bool time_sorting(char *flags);
void sort_file_time(struct DirectoryContent *content, int count, char *flags);

#endif
