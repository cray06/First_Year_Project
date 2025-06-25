/*
** EPITECH PROJECT, 2024
** my_strcat.c
** File description:
** Function that concatenates two strings.
*/

#include "include/my.h"

char *my_strcat(char *dest, char const *src)
{
    int len_dest = my_strlen(dest);
    int i = 0;

    for (i = 0; src[i] != '\0'; i++) {
        dest[len_dest + i] = src[i];
    }
    dest[len_dest + i] = '\0';
    return (dest);
}
