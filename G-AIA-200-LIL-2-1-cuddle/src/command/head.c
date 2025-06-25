/*
** EPITECH PROJECT, 2025
** head.c
** File description:
** head.c
*/

#include "dataframe.h"

void **copy_row_data(dataframe_t *src, int row, int nb_cols)
{
    void **new_row;
    int j = 0;

    new_row = malloc(sizeof(void *) * (nb_cols + 1));
    if (new_row == NULL)
        return NULL;
    while (j < nb_cols) {
        new_row[j] = copy_data_from_df(src, row, j);
        j++;
    }
    new_row[j] = NULL;
    return new_row;
}

void ***allocate_data_rows(int nb_rows)
{
    void ***data;

    data = malloc(sizeof(void **) * nb_rows);
    return data;
}

dataframe_t *create_dataframe_structure(int nb_rows, int nb_cols)
{
    dataframe_t *df;

    df = malloc(sizeof(dataframe_t));
    if (df == NULL)
        return NULL;
    df->nb_rows = nb_rows;
    df->nb_columns = nb_cols;
    return df;
}

static dataframe_t *init_head_df(dataframe_t *df, int nb_rows)
{
    dataframe_t *head = create_dataframe_structure(nb_rows, df->nb_columns);

    if (head == NULL)
        return NULL;
    head->column_names = copy_column_names(df, head->nb_columns);
    head->column_types = copy_column_types(df, head->nb_columns);
    head->data = allocate_data_rows(nb_rows);
    head->separator = df->separator;
    if (!head->column_names || !head->column_types || !head->data) {
        return NULL;
    }
    return head;
}

dataframe_t *df_head(dataframe_t *dataframe, int nb_rows)
{
    dataframe_t *head;
    int i = 0;

    if (dataframe == NULL || nb_rows <= 0)
        return NULL;
    if (nb_rows > dataframe->nb_rows)
        nb_rows = dataframe->nb_rows;
    head = init_head_df(dataframe, nb_rows);
    if (head == NULL)
        return NULL;
    while (i < nb_rows) {
        head->data[i] = copy_row_data(dataframe, i, head->nb_columns);
        i++;
    }
    return head;
}
