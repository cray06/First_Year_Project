/*
** EPITECH PROJECT, 2024
** parsing.c
** File description:
** parsing.c
*/

#include "include/my.h"

static int is_flag_argument(char *arg)
{
    return arg[0] == '-';
}

static int is_valid_flag(char c)
{
    return my_strchr("alRdrt", c) != NULL;
}

static void process_flag_argument(char *arg, char *flags, int *index)
{
    for (int j = 1; arg[j] != '\0'; j++) {
        if (is_valid_flag(arg[j])) {
            flags[*index] = arg[j];
            (*index)++;
        }
    }
}

char *get_flag(int *argc, char *argv[])
{
    char *flags = malloc(8);
    int index = 0;

    for (int i = 1; i < *argc; i++) {
        if (is_flag_argument(argv[i])) {
            process_flag_argument(argv[i], flags, &index);
        }
    }
    flags[index] = '\0';
    return flags;
}
