/*
** EPITECH PROJECT, 2024
** my_strdup.c
** File description:
** Function that allocates memory and
** copies the string given
** as argument in it
*/

#include "../include/my.h"

char *my_strdup(char const *src)
{
    int len_str = my_strlen(src);
    int i = 0;
    char *str = malloc(len_str + 1);

    if (str == NULL)
        return NULL;
    while (i < len_str) {
        str[i] = src[i];
        i++;
    }
    str[i] = '\0';
    return str;
}
