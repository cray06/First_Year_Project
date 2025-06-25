/*
** EPITECH PROJECT, 2024
** my_putstr.c
** File description:
** my_putstr.c
*/

#include "lib.h"

int my_putstr(char const *str)
{
    if (str == NULL)
        return 84;
    write(1, str, my_strlen(str));
    return 0;
}
