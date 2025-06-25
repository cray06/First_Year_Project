/*
** EPITECH PROJECT, 2025
** copy
** File description:
** copy
*/
#include "dataframe.h"

void *copy_float_value(void *src)
{
    float *value;

    value = malloc(sizeof(float));
    if (value != NULL)
        *value = *(float *)src;
    return value;
}

void *copy_bool_value(void *src)
{
    bool *value;

    value = malloc(sizeof(bool));
    if (value != NULL)
        *value = *(bool *)src;
    return value;
}

void *copy_int_value(void *src)
{
    int *value;

    value = malloc(sizeof(int));
    if (value != NULL)
        *value = *(int *)src;
    return value;
}

void *copy_uint_value(void *src)
{
    unsigned int *value;

    value = malloc(sizeof(unsigned int));
    if (value != NULL)
        *value = *(unsigned int *)src;
    return value;
}

void *copy_data_from_df(dataframe_t *dataframe, int row, int col)
{
    column_type_t type;

    type = dataframe->column_types[col];
    return copy_value(dataframe->data[row][col], type);
}
