/*
** EPITECH PROJECT, 2025
** free_csv
** File description:
** free_csv
*/
#include "dataframe.h"

void free_row(dataframe_t *dataframe, int row_index)
{
    for (int x = 0; x < dataframe->nb_columns; x++)
        free(dataframe->data[row_index][x]);
    free(dataframe->data[row_index]);
}

void df_free(dataframe_t *dataframe)
{
    if (dataframe->column_types != NULL)
        free(dataframe->column_types);
    if (dataframe->column_names != NULL);
        free_word_array(dataframe->column_names);
    for (int y = 0; y < dataframe->nb_rows; y++){
        free_row(dataframe, y);
    }
    if (dataframe->data != NULL)
        free(dataframe->data);
    free(dataframe);
}
