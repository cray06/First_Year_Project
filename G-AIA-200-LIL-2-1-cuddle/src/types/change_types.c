/*
** EPITECH PROJECT, 2025
** change_types
** File description:
** change_types
*/
#include "dataframe.h"

static void handle_column_type(dataframe_t *dataframe, int x, int y)
{
    for (int i = 0; i < 4; i++)
        if (dataframe->column_types[y] == types[i].type)
            types[i].f(dataframe, x, y);
}

void change_type(dataframe_t *dataframe)
{
    int y = 0;
    int x = 0;

    while (y < dataframe->nb_columns){
        handle_column_type(dataframe, x, y);
        x++;
        if (x >= dataframe->nb_rows){
            x = 0;
            y++;
        }
    }
}
