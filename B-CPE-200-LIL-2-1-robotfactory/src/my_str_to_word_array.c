/*
** EPITECH PROJECT, 2024
** my_str_to_word_array.c
** File description:
** my_str_to_word_array
*/
#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>

static int isnt_delimiter(char c, char *delimiters)
{
    for (int i = 0; delimiters[i] != '\0'; i++){
        if (c == delimiters[i])
            return 0;
    }
    return 1;
}

static int get_nb_word(char const *str, char *delimiters)
{
    int nb = 0;
    int quote = 0;
    int can = 1;

    if (str == NULL)
        return 0;
    for (int i = 0; str[i] != '\0'; i++){
        if ((isnt_delimiter(str[i], delimiters) || quote) && can){
            nb++;
            can = 0;
        }
        if (str[i] == '"')
            quote = !quote;
        if (!isnt_delimiter(str[i], delimiters) && !quote)
            can = 1;
    }
    return nb;
}

static int get_number_char(char const *str, char *delimiters, int i)
{
    int nb = 0;
    int quote = 0;
    int word_end = 0;

    for (int x = i; str[x] != '\0' && !word_end; x++){
        if (!isnt_delimiter(str[x], delimiters) && !quote)
            word_end = 1;
        if ((isnt_delimiter(str[x], delimiters) || quote) && str[x] != '"'){
            nb++;
            word_end = 0;
        }
        if (str[x] == '"')
            quote = !quote;
    }
    return nb;
}

static char *put_str_temp(char const *str, char *delimiters, int i)
{
    char *str_temp;
    int nb = get_number_char(str, delimiters, i);

    str_temp = malloc(sizeof(char) * (nb + 1));
    if (str_temp == NULL)
        return NULL;
    if (str[i] == '"')
        i++;
    for (int y = 0; y < nb; y++)
        str_temp[y] = str[y + i];
    str_temp[nb] = '\0';
    return str_temp;
}

char **my_str_to_word_array(char const *str, char *delim)
{
    char **word_array = malloc(sizeof(char *) * (get_nb_word(str, delim) + 1));
    int x = 0;
    int quote = 0;
    int can = 1;

    if (word_array == NULL)
        return NULL;
    for (int i = 0; str[i] != '\0'; i++){
        if ((isnt_delimiter(str[i], delim) || quote) && can){
            word_array[x] = put_str_temp(str, delim, i);
            x++;
            can = 0;
        }
        if (str[i] == '"')
            quote = !quote;
        if (!isnt_delimiter(str[i], delim) && !quote)
            can = 1;
    }
    word_array[x] = NULL;
    return word_array;
}

void free_word_array(char **word_array)
{
    for (int i = 0; word_array[i] != NULL; i++){
        free(word_array[i]);
    }
    free(word_array);
}

int len_word_array(char **word_array)
{
    int len = 0;

    for (int i = 0; word_array[i] != NULL; i++)
        len++;
    return len;
}
