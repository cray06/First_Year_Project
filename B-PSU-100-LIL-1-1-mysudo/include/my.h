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
    #include <unistd.h>
    #include <crypt.h>
    #include <termios.h>
    #include <string.h>
    #include <sys/types.h>

typedef struct {
    char *user;
    char *u_user;
    char **groups;
    char **sudo_ers;
    int group_id;
    int user_id;
} user_t;

int my_strncmp(const char *s1, const char *s2, int n);
char **my_str_to_word_array(char const *str);
int my_strlen(char const *str);
int my_strcmp(const char *s1, const char *s2);
char *my_strdup(char const *src);
char *my_strstr(char *str, const char *to_find);
char **get_group(user_t *user_info);
char **get_sudoers(user_t *user_info);
char *parse_env(char **env);
int request_passwd(char *passwd, user_t *user_info);
void free_word_array(char **array);
int check_passwd(char *passwd, user_t *user_info);
char *get_id(user_t *user_info);
int check_in_sudoers(user_t *user_info);
char *my_strncpy(char *dest, char const *src, int n);
int get_gid(user_t *user_info);
int get_uid(user_t *user_info);
char **command(char **av);
int g_flag(char **av);
int u_flag(char **av);
void process_flags(char *argv[], user_t *user_info);

#endif
