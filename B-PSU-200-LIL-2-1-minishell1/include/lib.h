/*
** EPITECH PROJECT, 2024
** my.h
** File description:
** my.h
*/

#ifndef LIB_H
    #define LIB_H

    #include <stdbool.h>
    #include <stdlib.h>
    #include <stddef.h>
    #include <stdio.h>
    #include <stdarg.h>
    #include <unistd.h>
    #include <sys/types.h>
    #include <string.h>
    #include <sys/wait.h>
    #include <signal.h>
    #include <sys/stat.h>
    #include <unistd.h>
    #include <fcntl.h>
    #include <errno.h>

char **my_str_to_word_array(char const *str, char const *separator);
int my_putstr(char const *str);
void my_putchar(char c);
int my_strlen(char const *str);
int my_put_nbr(int nb);
int my_strncmp(const char *s1, const char *s2, int n);
int my_strcmp(const char *s1, const char *s2);
char *my_strcat(char *dest, char const *src);
char *my_strstr(char *str, const char *to_find);
char *my_strdup(char const *src);
void free_word_array(char **words);
char *my_strcpy(char *dest, char const *src);


#endif
