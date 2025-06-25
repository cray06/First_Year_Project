/*
** EPITECH PROJECT, 2024
** my_str_to_word_array.c
** File description:
** my_str_to_word_array
*/

#include "../include/my.h"

static void fill_word(char const *str, char **word_array, int *i, int j)
{
    int x = 0;

    while (str[*i] == ' ' || str[*i] == '\0'
        || str[*i] == ':' || str[*i] == '\t')
        (*i)++;
    while (str[*i] != ' ' && str[*i] != '\0'
        && str[*i] != ':' && str[*i] != '\t') {
        word_array[j][x] = str[*i];
        (*i)++;
        x++;
    }
    word_array[j][x] = '\0';
}

char **my_str_to_word_array(char const *str)
{
    int i = 0;
    int j = 0;
    char **word_array = malloc(sizeof(char *) * (my_strlen(str) + 1));

    if (word_array == NULL)
        return NULL;
    while (str[i] != '\0') {
        word_array[j] = malloc(sizeof(char) * my_strlen(str) + 1);
        if (word_array[j] == NULL)
            return NULL;
        fill_word(str, word_array, &i, j);
        j++;
        word_array[j] = NULL;
    }
    return word_array;
}
