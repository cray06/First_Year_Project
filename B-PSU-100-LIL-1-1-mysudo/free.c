/*
** EPITECH PROJECT, 2025
** free.c
** File description:
** free.c
*/

#include "include/my.h"

void free_word_array(char **array)
{
    if (array == NULL)
        return;
    for (int i = 0; array[i] != NULL; i++)
        free(array[i]);
    free(array);
}
