/*
** EPITECH PROJECT, 2025
** describe.c
** File description:
** describe.c
*/

#include "dataframe.h"

static float set_variable(dataframe_t *dataframe, int index, int i)
{
    if (dataframe->column_types[index] == FLOAT)
        return *(float *)df_get_value(dataframe, i,
            dataframe->column_names[index]);
    if (dataframe->column_types[index] == INT)
        return *(int *)df_get_value(dataframe, i,
            dataframe->column_names[index]);
    if (dataframe->column_types[index] == UINT)
        return *(unsigned int *)df_get_value(dataframe, i,
            dataframe->column_names[index]);
}

static float calculate_mean(dataframe_t *dataframe, int index)
{
    float sum = 0;

    for (int i = 0; i < dataframe->nb_rows; i++){
        sum += set_variable(dataframe, index, i);
    }
    return sum / (float)dataframe->nb_rows;
}

static float calculate_std(dataframe_t *dataframe, int index, float mean)
{
    float sum_squared_diff = 0;
    float value = 0;

    for (int i = 0; i < dataframe->nb_rows; i++) {
        value = set_variable(dataframe, index, i);
        sum_squared_diff += (value - mean) * (value - mean);
    }
    return sqrt(sum_squared_diff / dataframe->nb_rows);
}

static float find_min(dataframe_t *dataframe, int index)
{
    float min_value = set_variable(dataframe, index, 0);
    float current;

    for (int i = 1; i < dataframe->nb_rows; i++) {
        current = set_variable(dataframe, index, i);
        if (current < min_value)
            min_value = current;
    }
    return min_value;
}

static float find_max(dataframe_t *dataframe, int index)
{
    float max_value = *(float *)df_get_value(dataframe, 0,
        dataframe->column_names[index]);
    float current;

    for (int i = 1; i < dataframe->nb_rows; i++) {
        current = set_variable(dataframe, index, i);
        if (current > max_value)
            max_value = current;
    }
    return max_value;
}

void print_column_stats(dataframe_t *dataframe, int index)
{
    float mean = calculate_mean(dataframe, index);
    float std = calculate_std(dataframe, index, mean);
    float min = find_min(dataframe, index);
    float max = find_max(dataframe, index);

    printf("Column: %s\n", dataframe->column_names[index]);
    printf("Count: %d\n", dataframe->nb_rows);
    printf("Mean: %.2f\n", mean);
    printf("Std: %.2f\n", std);
    printf("Min: %.2f\n", min);
    printf("Max: %.2f\n", max);
}

int is_numerical_column(column_type_t type)
{
    return (type == INT || type == FLOAT || type == UINT);
}

void process_column(dataframe_t *dataframe, int index, int *first_printed)
{
    int should_print = is_numerical_column(dataframe->column_types[index]);

    if (*first_printed == 0 && should_print)
        printf("\n");
    if (should_print)
        print_column_stats(dataframe, index);
    if (should_print)
        *first_printed = 0;
}

void df_describe(dataframe_t *dataframe)
{
    int first_printed = 1;

    if (dataframe == NULL)
        return;
    for (int i = 0; i < dataframe->nb_columns; i++)
        process_column(dataframe, i, &first_printed);
}
