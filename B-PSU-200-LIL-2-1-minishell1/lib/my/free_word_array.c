/*
** EPITECH PROJECT, 2025
** free_word_array.c
** File description:
** free_word_array.c
*/

#include "lib.h"

void free_word_array(char **words)
{
    if (words == NULL)
        return;
    for (int i = 0; words[i] != NULL; i++) {
        free(words[i]);
    }
    free(words);
}
