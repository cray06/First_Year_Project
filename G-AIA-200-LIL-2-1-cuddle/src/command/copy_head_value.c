/*
** EPITECH PROJECT, 2025
** copy_head_value.c
** File description:
** copy_head_value.c
*/

#include "dataframe.h"

char **copy_column_names(dataframe_t *src, int nb_cols)
{
    char **names;
    int i = 0;

    names = malloc(sizeof(char *) * (nb_cols + 1));
    if (names == NULL)
        return NULL;
    while (i < nb_cols) {
        names[i] = my_strdup(src->column_names[i]);
        i++;
    }
    names[i] = NULL;
    return names;
}

column_type_t *copy_column_types(dataframe_t *src, int nb_cols)
{
    column_type_t *types;
    int i = 0;

    types = malloc(sizeof(column_type_t) * nb_cols);
    if (types == NULL)
        return NULL;
    while (i < nb_cols) {
        types[i] = src->column_types[i];
        i++;
    }
    return types;
}
