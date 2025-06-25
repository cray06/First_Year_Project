/*
** EPITECH PROJECT, 2024
** my_strlen.c
** File description:
** Function that counts and returns
** the number of characters found
** in the string passed as parameter
*/

#include "include/shell.h"

int my_strlen(char const *str)
{
    int count = 0;

    while (str[count] != '\0') {
        count++;
    }
    return count;
}
