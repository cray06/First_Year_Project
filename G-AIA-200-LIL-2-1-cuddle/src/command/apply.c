/*
** EPITECH PROJECT, 2025
** apply
** File description:
** apply
*/
#include "dataframe.h"

int check_row(dataframe_t *new_dataframe, int index)
{
    if (new_dataframe->data[index] != NULL)
        return 0;
    for (int i = 0; i < index; i++){
        free_row(new_dataframe, i);
    }
    new_dataframe->data = NULL;
    df_free(new_dataframe);
    return 1;
}

void init_df_apply(dataframe_t *src, dataframe_t *new_dataframe)
{
    new_dataframe->separator = src->separator;
    new_dataframe->nb_columns = src->nb_columns;
    new_dataframe->nb_rows = src->nb_rows;
    new_dataframe->column_names = NULL;
    new_dataframe->column_types = NULL;
    new_dataframe->data = NULL;
}

dataframe_t *create_df_apply(dataframe_t *src)
{
    dataframe_t *df_apply = malloc(sizeof(*df_apply));

    if (df_apply == NULL)
        return NULL;
    init_df_apply(src, df_apply);
    df_apply->column_types = copy_column_types(src, src->nb_columns);
    df_apply->data = malloc(sizeof(void **) * df_apply->nb_rows);
    for (int i = 0; df_apply->data != NULL && i < df_apply->nb_rows; i++){
        df_apply->data[i] = copy_row_data(src, i,
            df_apply->nb_columns);
        if (check_row(df_apply, i))
            return NULL;
    }
    df_apply->column_names = copy_column_names(src, df_apply->nb_columns);
    if (df_apply->column_types == NULL ||
        df_apply->column_names == NULL || df_apply->data == NULL){
        df_free(df_apply);
        return NULL;
    }
    return df_apply;
}

dataframe_t *df_apply(dataframe_t *dataframe, const char *column,
    void *(apply_func)(void *value))
{
    int column_index = get_column_index(dataframe, column);
    dataframe_t *new_dataframe;
    void *value;

    if (column_index < 0)
        return NULL;
    new_dataframe = create_df_apply(dataframe);
    if (new_dataframe == NULL)
        return NULL;
    for (int i = 0; i < new_dataframe->nb_rows; i++){
        new_dataframe->data[i][column_index] =
            apply_func(new_dataframe->data[i][column_index]);
    }
    return new_dataframe;
}
