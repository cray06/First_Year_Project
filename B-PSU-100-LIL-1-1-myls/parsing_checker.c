/*
** EPITECH PROJECT, 2024
** parsing_checker.c
** File description:
** parsing_checker.c
*/

#include "include/my.h"

bool include_hidden(char *flags)
{
    return (my_strchr(flags, 'a')) ? true : false;
}

bool only_current(char *flags)
{
    return (my_strchr(flags, 'd')) ? true : false;
}

bool reverse_list(char *flags)
{
    return (my_strchr(flags, 'r')) ? true : false;
}

bool long_print(char *flags)
{
    return (my_strchr(flags, 'l')) ? true : false;
}

bool time_sorting(char *flags)
{
    return (my_strchr(flags, 't')) ? true : false;
}
