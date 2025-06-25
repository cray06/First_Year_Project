/*
** EPITECH PROJECT, 2024
** my_strstr.c
** File description:
** Reproducing the function strstr
*/

#include <stddef.h>

char *my_strstr(char *str, const char *to_find)
{
    char *s1 = str;
    const char *s2 = to_find;

    if (*to_find == '\0') {
        return str;
    }
    while (*str != '\0') {
        while (*s1 == *s2) {
            s1++;
            s2++;
        }
        if (*s2 == '\0') {
            return str;
            s2--;
        }
        s1++;
        str++;
    }
    return NULL;
}
