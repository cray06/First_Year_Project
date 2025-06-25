/*
** EPITECH PROJECT, 2023
** B-CPE-110 : Setting Up Shell
** File description:
** shell.h
*/

#ifndef SHELL_H
    #define SHELL_H

    #include <stdbool.h>
    #include <stdlib.h>
    #include <stddef.h>
    #include <stdio.h>
    #include <stdarg.h>
    #include <string.h>
    #include <unistd.h>
    #include <stdbool.h>

typedef struct linked_s {
    int id;
    char *name;
    char *type;
    struct linked_s *next;
} linked_t;

typedef struct {
    int (*compare)(linked_t *a, linked_t *b);
} compare_func_t;

typedef struct {
    compare_func_t *cmps;
    int cmp_count;
    int reverse;
} sort_params_t;

void my_putchar(char c);
int my_putstr(char const *str);
int my_strcmp(const char *s1, const char *s2);
char *my_strdup(char const *src);
int my_strlen(char const *str);
int my_put_nbr(int nb);
int my_getnbr(char const *str);
int compare_by_id(linked_t *a, linked_t *b);
int compare_by_name(linked_t *a, linked_t *b);
int compare_by_type(linked_t *a, linked_t *b);

// To be implemented
int add(void *data, char **args);
int del(void *data, char **args);
int sort(void *data, char **args);
int disp(void *data, char **args);

// Already implemented
int workshop_shell(void *data);

#endif /* SHELL_H */
