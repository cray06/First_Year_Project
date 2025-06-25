/*
** EPITECH PROJECT, 2025
** write_csv.c
** File description:
** write_csv.c
*/

#include "dataframe.h"

void write_value_by_type(FILE *file, void *data, column_type_t type)
{
    if (data == NULL)
        return;
    switch (type) {
        case INT:
            fprintf(file, "%d", *((int *)data));
            return;
        case UINT:
            fprintf(file, "%u", *((unsigned int *)data));
            return;
        case FLOAT:
            fprintf(file, "%f", *((float *)data));
            return;
        case BOOL:
            fprintf(file, "%s", *((bool *)data) ? "true" : "false");
            return;
        default:
            fprintf(file, "%s", (char *)data);
    }
}

int write_separator(FILE *file, int j, int nb_columns, const char *separator)
{
    if (j < nb_columns - 1)
        return fprintf(file, "%s", separator);
    return fprintf(file, "\n");
}

int write_column_headers(FILE *file, dataframe_t *dataframe)
{
    for (int i = 0; i < dataframe->nb_columns; i++) {
        fprintf(file, "%s", dataframe->column_names[i]);
        write_separator(file, i, dataframe->nb_columns, dataframe->separator);
    }
    return 0;
}

int write_data_rows(FILE *file, dataframe_t *dataframe)
{
    for (int i = 0; i < dataframe->nb_rows; i++) {
        for (int j = 0; j < dataframe->nb_columns; j++) {
            write_value_by_type(file, dataframe->data[i][j],
                dataframe->column_types[j]);
            write_separator(file, j, dataframe->nb_columns,
                dataframe->separator);
        }
    }
    return 0;
}

int df_write_csv(dataframe_t *dataframe, const char *filename)
{
    FILE *file;

    if (dataframe == NULL || filename == NULL)
        return 1;
    file = fopen(filename, "w");
    if (file == NULL)
        return 1;
    write_column_headers(file, dataframe);
    write_data_rows(file, dataframe);
    fclose(file);
    return 0;
}
