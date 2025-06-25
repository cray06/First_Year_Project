/*
** EPITECH PROJECT, 2024
** my_strstr.c
** File description:
** Reproducing the function strstr
*/

#include <lib.h>

char *my_strstr(char *str, const char *to_find)
{
    for (int i = 0; str[i] != '\0'; i++) {
        if (my_strncmp(str + i, to_find, my_strlen(to_find) - 1))
            return str + i;
    }
    return NULL;
}
