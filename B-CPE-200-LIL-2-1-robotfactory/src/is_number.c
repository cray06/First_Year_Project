/*
** EPITECH PROJECT, 2025
** is_number.c
** File description:
** is_number.c
*/

#include "asm.h"

bool my_isdigit(char nbr)
{
    if (nbr >= '0' && nbr <= '9')
        return true;
    return false;
}

bool my_isnumber(const char *str)
{
    for (int i = 0; str[i] != '\0'; i++) {
        if (!my_isdigit(str[i]))
            return false;
    }
    return true;
}
