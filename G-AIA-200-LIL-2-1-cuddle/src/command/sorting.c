/*
** EPITECH PROJECT, 2025
** sorting.c
** File description:
** sorting.c
*/

#include "dataframe.h"

static void swap_rows(void ***data, int r1, int r2)
{
    void **temp = data[r1];

    data[r1] = data[r2];
    data[r2] = temp;
}

static dataframe_t *create_empty_sorted_df(dataframe_t *df)
{
    dataframe_t *sorted_df = malloc(sizeof(dataframe_t));

    if (sorted_df == NULL)
        return NULL;
    sorted_df->separator = df->separator;
    sorted_df->nb_rows = df->nb_rows;
    sorted_df->nb_columns = df->nb_columns;
    sorted_df->column_types = copy_column_types(df, df->nb_columns);
    sorted_df->column_names = copy_column_names(df, df->nb_columns);
    sorted_df->data = malloc(sizeof(void **) * df->nb_rows);
    if (sorted_df->column_types == NULL || sorted_df->column_names == NULL
        || sorted_df->data == NULL)
        return NULL;
    return sorted_df;
}

static int copy_name_col(dataframe_t *dest, dataframe_t *src)
{
    for (int i = 0; i < src->nb_columns; i++)
        dest->column_names[i] = strdup(src->column_names[i]);
    return 0;
}

int copy_data(dataframe_t *dest, dataframe_t *src)
{
    for (int i = 0; i < src->nb_rows; i++) {
        dest->data[i] = malloc(sizeof(void *) * src->nb_columns);
        if (dest->data[i] == NULL)
            return -1;
        for (int j = 0; j < src->nb_columns; j++)
            dest->data[i][j] = src->data[i][j];
    }
    return 0;
}

void perform_bubble_sort_swap(dataframe_t *df, int index,
    bool (*cmp)(void *, void *), int j)
{
    if (cmp(df->data[j][index], df->data[j + 1][index]))
        swap_rows((void ***)df->data, j, j + 1);
}

void bubble_sort(dataframe_t *df, int index, bool (*cmp)(void *, void *))
{
    for (int i = 0; i < df->nb_rows - 1; i++)
        for (int j = 0; j < df->nb_rows - i - 1; j++)
            perform_bubble_sort_swap(df, index, cmp, j);
}

dataframe_t *df_sort(dataframe_t *df, const char *col,
    bool (*cmp)(void *, void *))
{
    int index = get_column_index(df, col);
    dataframe_t *sorted_df;

    if (index == -1)
        return NULL;
    sorted_df = create_empty_sorted_df(df);
    if (sorted_df == NULL)
        return NULL;
    copy_name_col(sorted_df, df);
    sorted_df->column_types = copy_column_types(df, df->nb_columns);
    for (int i = 0; sorted_df->data != NULL && i < sorted_df->nb_rows; i++){
        sorted_df->data[i] = copy_row_data(df, i, sorted_df->nb_columns);
        if (check_row(sorted_df, i))
            return NULL;
    }
    bubble_sort(sorted_df, index, cmp);
    return sorted_df;
}
