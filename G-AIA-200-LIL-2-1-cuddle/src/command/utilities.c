/*
** EPITECH PROJECT, 2025
** utilities
** File description:
** utilities
*/
#include "dataframe.h"

int get_column_index(dataframe_t *dataframe, const char *column)
{
    int column_index = -1;

    for (int i = 0; dataframe->column_names[i] != NULL; i++){
        if (!strcmp(column, dataframe->column_names[i]))
            column_index = i;
    }
    return column_index;
}

void *df_get_value(dataframe_t *dataframe, int row, const char *column)
{
    int column_index = get_column_index(dataframe, column);

    if (column_index < 0)
        return NULL;
    return dataframe->data[row][column_index];
}

void **df_get_values(dataframe_t *dataframe, const char *column)
{
    int i = 0;
    void **values;
    int column_index = get_column_index(dataframe, column);

    if (column_index < 0)
        return NULL;
    values = malloc(sizeof(void *) * (dataframe->nb_rows + 1));
    for (; i < dataframe->nb_rows; i++){
        values[i] = df_get_value(dataframe, i, column);
    }
    values[i] = NULL;
    return values;
}

int is_in_values(void **values, void *value, column_type_t type)
{
    for (int i = 0; values[i] != NULL; i++){
        if (type == STRING && !strcmp(value, values[i]))
            return 1;
        if (type == INT && (*(int *){value} - *(int *){values[i]}) == 0)
            return 1;
        if (type == UINT &&
            (*(unsigned int *){value} - *(unsigned int *){values[i]}) == 0)
            return 1;
        if (type == FLOAT && (*(float *){value} - *(float *){values[i]}) == 0)
            return 1;
        if (type == BOOL && (*(bool *){value} == *(bool *){values[i]}))
            return 1;
    }
    return 0;
}

static void **fill_values(dataframe_t *dataframe, int index,
    const char *column)
{
    int len = 1;
    void **values = malloc(sizeof(void *) * len);

    if (values == NULL)
        return NULL;
    for (int i = len - 1; i < dataframe->nb_rows; i++){
        values[len - 1] = NULL;
        if (!is_in_values(values, df_get_value(dataframe, i, column),
            dataframe->column_types[index])){
            values[len - 1] = df_get_value(dataframe, i, column);
            len++;
            values = realloc(values, sizeof(void *) * len);
        }
        if (values == NULL)
            break;
    }
    values[len - 1] = NULL;
    return values;
}

void **df_get_unique_values(dataframe_t *dataframe, const char *column)
{
    int index = get_column_index(dataframe, column);
    void **values;

    if (index < 0)
        return NULL;
    values = fill_values(dataframe, index, column);
    return values;
}
