/*
** EPITECH PROJECT, 2024
** my_strcmp.c
** File description:
** Same function as C lib
*/

#include "include/shell.h"

int my_strcmp(const char *s1, const char *s2)
{
    while (*s1 && *s2) {
        if (*s1 != *s2) {
            return (*s1 - *s2);
        }
        s1++;
        s2++;
    }
    return *s1 - *s2;
}
