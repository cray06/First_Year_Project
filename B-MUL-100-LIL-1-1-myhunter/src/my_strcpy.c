/*
** EPITECH PROJECT, 2024
** my_strcpy.c
** File description:
** Function that copies a string into another
*/

#include "../include/my.h"

char *my_strcpy(char *dest, char const *src)
{
    char *content = dest;

    while (*src != '\0') {
        *dest = *src;
        src++;
        dest++;
    }
    *dest = '\0';
    return content;
}
