/*
** EPITECH PROJECT, 2025
** filter.c
** File description:
** filter.c
*/

#include "dataframe.h"

static int count_filtered_rows(dataframe_t *dataframe, int index,
    bool (*filter_func)(void *value))
{
    int filtered_rows = 0;

    for (int i = 0; i < dataframe->nb_rows; i++)
        if (filter_func(dataframe->data[i][index]))
            filtered_rows++;
    return filtered_rows;
}

dataframe_t *create_filtered_df(dataframe_t *dataframe, int filtered_rows)
{
    dataframe_t *filtered_df = malloc(sizeof(dataframe_t));

    if (filtered_df == NULL)
        return NULL;
    filtered_df->nb_columns = dataframe->nb_columns;
    filtered_df->nb_rows = filtered_rows;
    filtered_df->separator = dataframe->separator;
    filtered_df->column_names = copy_column_names(dataframe,
        dataframe->nb_columns);
    filtered_df->column_types = copy_column_types(dataframe,
        dataframe->nb_columns);
    filtered_df->data = malloc(sizeof(void *) * filtered_rows);
    if (filtered_df->data == NULL)
        return NULL;
    return filtered_df;
}

static void copy_data_of_row(dataframe_t *filtered_df, dataframe_t *src,
    int new_row, int src_row)
{
    for (int j = 0; j < src->nb_columns; j++)
        filtered_df->data[new_row][j] = copy_value(src->data[src_row][j],
            src->column_types[j]);
}

void copy_filtered_data(dataframe_t *filtered_df, dataframe_t *dataframe,
    int index, bool (*filter_func)(void *value))
{
    int new_row = 0;

    for (int i = 0; i < dataframe->nb_rows
        && new_row < filtered_df->nb_rows; i++) {
        if (!filter_func(dataframe->data[i][index]))
            continue;
        filtered_df->data[new_row] =
            malloc(sizeof(void *) * dataframe->nb_columns);
        if (filtered_df->data[new_row] == NULL)
            continue;
        copy_data_of_row(filtered_df, dataframe, new_row, i);
        new_row++;
    }
}

dataframe_t *df_filter(dataframe_t *dataframe, const char *column,
    bool (*filter_func)(void *value))
{
    int index = 0;
    int filtered_rows = 0;
    dataframe_t *filtered_df;

    if (dataframe == NULL || column == NULL || filter_func == NULL)
        return NULL;
    index = get_column_index(dataframe, column);
    if (index == -1)
        return NULL;
    filtered_rows = count_filtered_rows(dataframe, index, filter_func);
    if (filtered_rows == 0)
        return NULL;
    filtered_df = create_filtered_df(dataframe, filtered_rows);
    if (filtered_df == NULL)
        return NULL;
    copy_filtered_data(filtered_df, dataframe, index, filter_func);
    return filtered_df;
}
