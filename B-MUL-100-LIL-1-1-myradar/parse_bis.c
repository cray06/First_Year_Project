/*
** EPITECH PROJECT, 2025
** parse_bis.c
** File description:
** parse_bis.c
*/

#include "include/my.h"

bool validate_plane_args(char **word_array)
{
    for (int i = 1; i <= 6; i++) {
        if (word_array[i] == NULL || my_is_all_digit(word_array[i]) == false)
            return false;
    }
    return true;
}
