/*
** EPITECH PROJECT, 2025
** shape.c
** File description:
** shape.c
*/

#include "dataframe.h"

dataframe_shape_t df_shape(dataframe_t *dataframe)
{
    dataframe_shape_t shape = {0, 0};

    if (dataframe == NULL)
        return shape;
    shape.nb_rows = dataframe->nb_rows;
    shape.nb_columns = dataframe->nb_columns;
    return shape;
}
