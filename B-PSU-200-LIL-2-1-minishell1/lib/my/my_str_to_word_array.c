/*
** EPITECH PROJECT, 2025
** my_str_to_word_array.c
** File description:
** my_str_to_word_array.c
*/

#include "lib.h"

int search_char(char const c, char const *separator)
{
    for (int i = 0; separator[i] != '\0'; i++) {
        if (separator[i] == c)
            return true;
    }
    return false;
}

char *get_next_word(char const *str, int *i, char const *separator)
{
    int x = 0;
    char *word = malloc(sizeof(char) * my_strlen(str) + 1);

    if (word == NULL)
        return NULL;
    while (search_char(str[*i], separator))
        (*i)++;
    while (str[*i] != '\0' && !search_char(str[*i], separator)) {
        word[x] = str[*i];
        (*i)++;
        x++;
    }
    word[x] = '\0';
    return word;
}

char **my_str_to_word_array(char const *str, char const *separator)
{
    int i = 0;
    int j = 0;
    char **words = malloc(sizeof(char *) * (my_strlen(str) + 1));

    if (words == NULL || str == NULL || separator == NULL)
        return NULL;
    while (str[i] != '\0') {
        words[j] = get_next_word(str, &i, separator);
        if (words[j] == NULL)
            return NULL;
        j++;
    }
    words[j] = NULL;
    return words;
}
