/*
** EPITECH PROJECT, 2024
** my_putstr.c
** File description:
** my_putstr.c
*/

#include "../include/my.h"

int my_putstr(char const *str)
{
    if (str == NULL)
        return 84;
    for (int i = 0; str[i]; i++)
        my_putchar(str[i]);
    return 0;
}
