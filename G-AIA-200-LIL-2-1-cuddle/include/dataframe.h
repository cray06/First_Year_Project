/*
** EPITECH PROJECT, 2025
** dataframe.h
** File description:
** dataframe.h
*/

#ifndef DATAFRAME_H
    #define DATAFRAME_H

    #include <stdio.h>
    #include <unistd.h>
    #include <stdlib.h>
    #include <string.h>
    #include <stdbool.h>
    #include <math.h>

typedef enum {
    BOOL,
    INT,
    FLOAT,
    STRING,
    UINT,
    UNDEFINED
} column_type_t;

typedef struct dataframe {
    int nb_rows;
    int nb_columns;
    char **column_names;
    column_type_t *column_types;
    void ***data;
    const char *separator;
} dataframe_t;

typedef struct linked_list {
    void *data;
    struct linked_list *next;
} linked_list_t;

typedef struct dataframe_shape_s {
    int nb_rows;
    int nb_columns;
} dataframe_shape_t;

typedef struct {
    column_type_t type;
    char *type_str;
    void (*f)(dataframe_t *, int, int);
} types_t;

extern types_t const types[];

char **my_str_to_word_array(char const *str, const char *delim);
void free_word_array(char **word_array);
int len_word_array(char **word_array);
int const_len_word_array(const char **word_array);
char *my_strdup(char const *src);
char *my_strlowcase(char *str);
int is_int(char *data);
int is_float(char *data);
int is_bool(char *data);
int is_uint(char *data);
int is_string(char *data);
void change_type(dataframe_t *dataframe);
void change_int_type(dataframe_t *dataframe, int row, int column);
void change_float_type(dataframe_t *dataframe, int row, int column);
void change_bool_type(dataframe_t *dataframe, int row, int column);
void change_uint_type(dataframe_t *dataframe, int row, int column);
void change_string_type(dataframe_t *dataframe, int row, int column,
    column_type_t current_type);
int get_column_index(dataframe_t *dataframe, const char *column);
void *copy_int_value(void *src);
void *copy_uint_value(void *src);
void *copy_float_value(void *src);
void *copy_bool_value(void *src);
void *copy_data_from_df(dataframe_t *dataframe, int row, int col);
void **copy_row_data(dataframe_t *src, int row, int nb_cols);
void ***allocate_data_rows(int nb_rows);
char **copy_column_names(dataframe_t *src, int nb_cols);
column_type_t *copy_column_types(dataframe_t *src, int nb_cols);
dataframe_t *create_dataframe_structure(int nb_rows, int nb_cols);
void *copy_value(void *value, column_type_t type);
int compare_values(void *val1, void *val2, column_type_t type);
int len_values(void **values);
void free_row(dataframe_t *dataframe, int row_index);
void df_info(dataframe_t *dataframe);
int check_row(dataframe_t *new_dataframe, int index);
int compare_value(void *value1, void *value2, column_type_t type);

dataframe_t *df_read_csv(const char *filename, const char *separator);
dataframe_shape_t df_shape(dataframe_t *dataframe);
void df_describe(dataframe_t *dataframe);
void df_free(dataframe_t *dataframe);
void **df_get_unique_values(dataframe_t *dataframe, const char *column);
void *df_get_value(dataframe_t *dataframe, int row, const char *column);
void **df_get_values(dataframe_t *dataframe, const char *column);
int df_write_csv(dataframe_t *dataframe, const char *filename);
dataframe_t *df_groupby(dataframe_t *dataframe, const char *aggregate_by,
    const char **to_aggregate, void *(*agg_func)(void **, int));
dataframe_t *df_head(dataframe_t *dataframe, int nb_rows);
dataframe_t *df_tail(dataframe_t *dataframe, int nb_rows);
dataframe_t *df_filter(dataframe_t *dataframe, const char *column,
    bool (*filter_func)(void *value));
dataframe_t *df_sort(dataframe_t *dataframe, const char *column,
    bool (*cmp)(void *, void *));
dataframe_t *df_apply(dataframe_t *dataframe, const char *column,
    void *(apply_func)(void *value));
dataframe_t *df_to_type(dataframe_t *dataframe, const char *column,
    column_type_t downcast);

#endif /* DATAFRAME_H */
