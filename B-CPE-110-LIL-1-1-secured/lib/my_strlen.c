/*
** EPITECH PROJECT, 2024
** strlen
** File description:
**  length of a string
*/

#include "../include/my.h"

int my_strlen(char const *str)
{
    int i = 0;

    if (str == NULL)
        return 0;
    for (; str[i]; i++);
    return i;
}
