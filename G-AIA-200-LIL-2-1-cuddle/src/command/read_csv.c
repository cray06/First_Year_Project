/*
** EPITECH PROJECT, 2025
** read_csv
** File description:
** read_csv
*/
#include "dataframe.h"

static void get_nb_row(dataframe_t *dataframe, const char *filename)
{
    FILE *file = fopen(filename, "r");
    char *line = NULL;

    dataframe->nb_rows = 0;
    while (file != NULL && getline(&line, &(size_t){1}, file) != -1){
        dataframe->nb_rows++;
    }
    if (file != NULL){
        dataframe->nb_rows--;
        fclose(file);
    }
    free(line);
}

void determine_types(dataframe_t *dataframe, int index)
{
    column_type_t type = UNDEFINED;

    for (int i = 0; i < dataframe->nb_rows; i++){
        type = is_int(dataframe->data[i][index]) &&
        (type == INT || type == UNDEFINED) ? INT : type;
        type = is_float(dataframe->data[i][index]) &&
        (type == FLOAT || type == UNDEFINED) ? FLOAT : type;
        type = is_bool(dataframe->data[i][index]) &&
        (type == BOOL || type == UNDEFINED) ? BOOL : type;
        type = is_uint(dataframe->data[i][index]) &&
        (type == UINT || type == UNDEFINED) ? UINT : type;
        type = is_string(dataframe->data[i][index]) &&
        (type == STRING || type == UNDEFINED) ? STRING : type;
    }
    if (type == UNDEFINED)
        type = STRING;
    dataframe->column_types[index] = type;
}

int set_types(dataframe_t *dataframe, FILE *file)
{
    dataframe->column_types = malloc(sizeof(column_type_t) *
        dataframe->nb_columns);
    if (dataframe->column_types == NULL){
        fclose(file);
        free(dataframe->data);
        return 1;
    } else {
        for (int i = 0; i < dataframe->nb_columns; i++)
            determine_types(dataframe, i);
        change_type(dataframe);
        return 0;
    }
}

int get_info_columns(dataframe_t *dataframe, FILE *file, const char *separator)
{
    char **word_array;
    char *line = NULL;

    if (getline(&line, &(size_t){1}, file) == -1){
        fclose(file);
        return 1;
    }
    if (line[strlen(line) - 1] == '\n')
        line[strlen(line) - 1] = '\0';
    word_array = my_str_to_word_array(line, separator);
    dataframe->column_names = word_array;
    dataframe->nb_columns = len_word_array(word_array);
    free(line);
    return 0;
}

int get_data(dataframe_t *dataframe, const char *separator, FILE *file)
{
    char *line = NULL;
    char **word_array;

    dataframe->data = malloc(sizeof(void **) * dataframe->nb_rows);
    if (dataframe->data == NULL){
        fclose(file);
        free_word_array(dataframe->column_names);
        return 1;
    }
    for (int row = 0; getline(&line, &(size_t){1}, file) != -1 &&
        row < dataframe->nb_rows; row++){
        if (line[strlen(line) - 1] == '\n')
            line[strlen(line) - 1] = '\0';
        word_array = my_str_to_word_array(line, separator);
        dataframe->data[row] = (void **)word_array;
    }
    free(line);
    return 0;
}

static void set_separator(dataframe_t *dataframe, const char *separator)
{
    dataframe->separator = separator;
    if (dataframe->separator == NULL)
        dataframe->separator = ",";
}

dataframe_t *df_read_csv(const char *filename, const char *separator)
{
    FILE *file = fopen(filename, "r");
    dataframe_t dataframe;
    dataframe_t *new_dataframe;

    if (file == NULL)
        return NULL;
    new_dataframe = malloc(sizeof(*new_dataframe));
    if (new_dataframe == NULL){
        fclose(file);
        return NULL;
    }
    set_separator(&dataframe, separator);
    get_nb_row(&dataframe, filename);
    if (get_info_columns(&dataframe, file, dataframe.separator) ||
        get_data(&dataframe, dataframe.separator, file) ||
        set_types(&dataframe, file))
        return NULL;
    fclose(file);
    *new_dataframe = dataframe;
    return new_dataframe;
}
