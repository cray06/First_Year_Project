/*
** EPITECH PROJECT, 2024
** is_digit.c
** File description:
** is_digit & is_all_digit.c
*/

#include "../include/my.h"

bool my_is_all_digit(char *str)
{
    int digit = 0;

    for (int i = 0; str[i] != '\0'; i++)
        if (str[i] >= '0' && str[i] <= '9')
            digit++;
    if (my_strlen(str) == digit) {
        return true;
    } else
        return false;
}
