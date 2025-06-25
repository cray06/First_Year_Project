/*
** EPITECH PROJECT, 2025
** int_to_str.c
** File description:
** int_to_str.c
*/

#include "../include/my.h"

void reverse_str(char *str, int length)
{
    char temp;

    for (int i = 0; i < length / 2; i++) {
        temp = str[i];
        str[i] = str[length - i - 1];
        str[length - i - 1] = temp;
    }
}

void handle_negative_and_convert(int n, char *str, int *i)
{
    int nbr = n;
    int is_negative = 0;

    if (n < 0) {
        is_negative = 1;
        nbr = -n;
    }
    while (nbr > 0) {
        str[(*i)] = nbr % 10 + '0';
        nbr /= 10;
        (*i)++;
    }
    if (is_negative) {
        str[*i] = '-';
        (*i)++;
    }
}

void int_to_str(int n, char *str)
{
    int i = 0;

    if (n == 0) {
        str[i] = '0';
        i++;
    } else {
        handle_negative_and_convert(n, str, &i);
    }
    str[i] = '\0';
    reverse_str(str, i);
}
