/*
** EPITECH PROJECT, 2025
** types
** File description:
** types
*/
#include "dataframe.h"

const types_t types[] = {
    {INT, "INT", &change_int_type},
    {FLOAT, "FLOAT", &change_float_type},
    {BOOL, "BOOL", &change_bool_type},
    {UINT, "UINT", &change_uint_type},
    {STRING, "STRING", NULL}
};
