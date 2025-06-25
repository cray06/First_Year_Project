/*
** EPITECH PROJECT, 2025
** info.c
** File description:
** info.c
*/

#include "dataframe.h"

char *get_type_name(column_type_t type)
{
    if (type == INT)
        return "int";
    if (type == FLOAT)
        return "float";
    if (type == BOOL)
        return "bool";
    if (type == UINT)
        return "unsigned int";
    return "string";
}

void print_column_info(dataframe_t *dataframe)
{
    int i = 0;
    char *type_name;

    while (i < dataframe->nb_columns) {
        type_name = get_type_name(dataframe->column_types[i]);
        printf("- %s: %s\n", dataframe->column_names[i], type_name);
        i++;
    }
}

void df_info(dataframe_t *dataframe)
{
    if (dataframe == NULL)
        return;
    printf("%d columns:\n", dataframe->nb_columns);
    print_column_info(dataframe);
}
