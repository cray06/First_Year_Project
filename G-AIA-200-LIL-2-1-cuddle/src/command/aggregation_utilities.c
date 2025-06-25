/*
** EPITECH PROJECT, 2025
** aggreg_utilities.c
** File description:
** aggreg_utilities.c
*/

#include "dataframe.h"

int len_values(void **values)
{
    int count = 0;

    while (*values){
        count++;
        values++;
    }
    return count;
}

void *copy_value(void *value, column_type_t type)
{
    if (type == INT)
        return copy_int_value(value);
    if (type == FLOAT)
        return copy_float_value(value);
    if (type == BOOL)
        return copy_bool_value(value);
    if (type == UINT)
        return copy_uint_value(value);
    return my_strdup((char *)value);
}
