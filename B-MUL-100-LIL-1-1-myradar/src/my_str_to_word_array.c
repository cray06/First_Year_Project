/*
** EPITECH PROJECT, 2024
** my_str_to_word_array.c
** File description:
** my_str_to_word_array
*/

#include <stdlib.h>
#include <stddef.h>
#include <stdio.h>

static int alpha_char_check(char const *str, int i)
{
    char c = str[i];

    return (c >= '0' && c <= '9') ||
        (c >= 'A' && c <= 'Z') ||
        (c >= 'a' && c <= 'z');
}

void eat(char const *str, int i, int *in_word, int *count)
{
    if ((alpha_char_check(str, i)) != *in_word) {
        (*count)++;
        (*in_word) = 1;
    }
}

static int count_words(char const *str)
{
    int count = 0;
    int in_word = 0;

    for (int i = 0; str[i] != '\0'; i++) {
        if (alpha_char_check(str, i))
            eat(str, i, &in_word, &count);
        else
            in_word = 0;
    }
    return count;
}

static int count_letters(char const *str, int i)
{
    int count = 0;

    while (alpha_char_check(str, i)) {
        count++;
        i++;
    }
    return count;
}

static void stockage_p(char *str_storage, char const *str, int i)
{
    for (int j = 0; j < count_letters(str, i); j++) {
        str_storage[j] = str[j + i];
    }
    str_storage[count_letters(str, i)] = '\0';
}

static void strr(int *stock, int *i, char const *str)
{
    (*stock)++;
    if (*stock < count_words(str)) {
        *i = *i + count_letters(str, *i) + 1;
    } else {
        *i = *i + count_letters(str, *i);
    }
}

char **my_str_to_word_array(char const *str)
{
    int stock = 0;
    char *str_storage;
    char **tab = malloc(sizeof(char *) * (count_words(str) + 1));

    if (tab == NULL)
        return NULL;
    tab[count_words(str)] = NULL;
    for (int i = 0; str[i] != '\0';) {
        if (count_letters(str, i) == 0) {
            i++;
            continue;
        }
        str_storage = malloc(sizeof(char) * (count_letters(str, i) + 1));
        if (str_storage == NULL)
            return NULL;
        stockage_p(str_storage, str, i);
        tab[stock] = str_storage;
        strr(&stock, &i, str);
    }
    return tab;
}
