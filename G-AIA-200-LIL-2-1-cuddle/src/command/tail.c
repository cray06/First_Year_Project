/*
** EPITECH PROJECT, 2025
** tail.c
** File description:
** tail.c
*/

#include "dataframe.h"

int setup_tail_dataframe(dataframe_t *dataframe, dataframe_t *tail)
{
    tail->column_names = copy_column_names(dataframe, tail->nb_columns);
    tail->column_types = copy_column_types(dataframe, tail->nb_columns);
    tail->data = allocate_data_rows(tail->nb_rows);
    tail->separator = dataframe->separator;
    if (tail->column_names == NULL
        || tail->column_types == NULL
        || tail->data == NULL)
        return 1;
    return 0;
}

void copy_tail_rows(dataframe_t *dataframe, dataframe_t *tail)
{
    int i = 0;
    int start_row;

    start_row = dataframe->nb_rows - tail->nb_rows;
    while (i < tail->nb_rows) {
        tail->data[i] =
            copy_row_data(dataframe, start_row + i, tail->nb_columns);
        i++;
    }
}

dataframe_t *df_tail(dataframe_t *dataframe, int nb_rows)
{
    dataframe_t *tail;

    if (dataframe == NULL || nb_rows <= 0)
        return NULL;
    if (nb_rows > dataframe->nb_rows)
        nb_rows = dataframe->nb_rows;
    tail = create_dataframe_structure(nb_rows, dataframe->nb_columns);
    if (tail == NULL)
        return NULL;
    if (setup_tail_dataframe(dataframe, tail))
        return NULL;
    copy_tail_rows(dataframe, tail);
    return tail;
}
