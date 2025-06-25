/*
** EPITECH PROJECT, 2024
** my_strchr.c
** File description:
** my_strchr.c
*/

#include "include/my.h"

char *my_strchr(char *s, int c)
{
    while (*s != '\0') {
        if (*s == c)
            return s;
        s++;
    }
    return NULL;
}
