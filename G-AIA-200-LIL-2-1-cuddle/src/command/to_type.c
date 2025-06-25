/*
** EPITECH PROJECT, 2025
** to_type
** File description:
** to_type
*/
#include "dataframe.h"

dataframe_t *init_typed(dataframe_t *dataframe)
{
    dataframe_t *typed = malloc(sizeof(*typed));

    if (typed == NULL)
        return NULL;
    typed->nb_columns = dataframe->nb_columns;
    typed->nb_rows = dataframe->nb_rows;
    typed->column_names = copy_column_names(dataframe, typed->nb_columns);
    typed->column_types = copy_column_types(dataframe, typed->nb_columns);
    typed->separator = dataframe->separator;
    typed->data = malloc(sizeof(void **) * typed->nb_rows);
    for (int i = 0; typed->data != NULL && i < typed->nb_rows; i++){
        typed->data[i] = copy_row_data(dataframe, i, typed->nb_columns);
    }
    if (typed->column_names == NULL || typed->column_types == NULL ||
        typed->data == NULL){
        df_free(typed);
        return NULL;
    }
    return typed;
}

dataframe_t *df_to_type(dataframe_t *dataframe, const char *column,
    column_type_t downcast)
{
    dataframe_t *typed;
    int index = get_column_index(dataframe, column);

    if (index < 0)
        return NULL;
    typed = init_typed(dataframe);
    if (typed == NULL)
        return NULL;
    for (int i = 0; i < typed->nb_rows; i++){
        change_string_type(typed, i, index, typed->column_types[index]);
    }
    typed->column_types[index] = downcast;
    if (downcast != STRING)
        change_type(typed);
    return typed;
}
