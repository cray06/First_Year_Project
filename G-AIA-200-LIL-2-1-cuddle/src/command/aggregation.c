/*
** EPITECH PROJECT, 2025
** aggregation
** File description:
** aggregation
*/
#include "dataframe.h"

int compare_value(void *value1, void *value2, column_type_t type)
{
    if (type == STRING && !strcmp(value1, value2))
        return 0;
    if (type == INT && (*(int *){value1} - *(int *){value2}) == 0)
        return 0;
    if (type == UINT &&
        (*(unsigned int *){value1} - *(unsigned int *){value2}) == 0)
        return 0;
    if (type == FLOAT && (*(float *){value1} - *(float *){value2}) == 0)
        return 0;
    if (type == BOOL && (*(bool *){value1} == *(bool *){value2}))
        return 0;
    return 1;
}

void **get_values_with_same_agg_by(dataframe_t *df, const char *column_agg_by,
    const char *column_to_agg, void *value_agg_by)
{
    int len = 1;
    void **values = malloc(sizeof(void *) * len);
    void *value;

    if (values == NULL)
        return NULL;
    for (int i = 0; i < df->nb_rows; i++){
        value = df_get_value(df, i, column_agg_by);
        values[len - 1] = NULL;
        if (!compare_value(value, value_agg_by,
            df->column_types[get_column_index(df, column_agg_by)])){
            values[len - 1] = df_get_value(df, i, column_to_agg);
            len++;
            values = realloc(values, sizeof(void *) * len);
        }
        if (values == NULL)
            return NULL;
    }
    values[len - 1] = NULL;
    return values;
}

static dataframe_t *init_grouped_data(dataframe_t *grouped, void **values)
{
    grouped->data = malloc(sizeof(void **) * grouped->nb_rows);
    if (grouped->data == NULL){
        df_free(grouped);
        return NULL;
    }
    for (int i = 0; i < grouped->nb_rows; i++){
        grouped->data[i] = malloc(sizeof(void *) * (grouped->nb_columns + 1));
        if (grouped->data[i] == NULL){
            df_free(grouped);
            return NULL;
        }
    }
    for (int i = 0; i < grouped->nb_rows; i++)
        grouped->data[i][0] = copy_value(values[i], grouped->column_types[0]);
    return grouped;
}

static dataframe_t *init_grouped_column_names(dataframe_t *grouped,
    const char *agg_by, const char **to_agg)
{
    grouped->column_names = malloc(sizeof(char *) *(grouped->nb_columns + 1));
    if (grouped->column_names == NULL){
        free(grouped);
        return NULL;
    }
    grouped->column_names[0] = my_strdup(agg_by);
    for (int i = 1; i < grouped->nb_columns; i++)
        grouped->column_names[i] = my_strdup(to_agg[i - 1]);
    grouped->column_names[grouped->nb_columns] = NULL;
    return grouped;
}

static dataframe_t *init_grouped_types(dataframe_t *group, dataframe_t *df,
    const char *agg_by, const char **to_agg)
{
    int *indexes = malloc(sizeof(int) * group->nb_columns);

    if (indexes == NULL){
        free(group->column_names);
        free(group);
        return NULL;
    }
    indexes[0] = get_column_index(df, agg_by);
    for (int i = 1; i < group->nb_columns; i++)
        indexes[i] = get_column_index(df, to_agg[i - 1]);
    group->column_types = malloc(sizeof(column_type_t) * group->nb_columns);
    if (group->column_types == NULL){
        free(group->column_names);
        free(group);
        free(indexes);
        return NULL;
    }
    for (int i = 0; i < group->nb_columns; i++)
        group->column_types[i] = df->column_types[indexes[i]];
    return group;
}

dataframe_t *init_grouped_df(dataframe_t *df, const char *agg_by,
    const char **to_agg, void **values)
{
    dataframe_t *grouped = malloc(sizeof(*grouped));
    int *indexes;

    if (grouped == NULL)
        return NULL;
    grouped->separator = df->separator;
    grouped->nb_columns = const_len_word_array(to_agg) + 1;
    grouped->nb_rows = len_values(values);
    grouped = init_grouped_column_names(grouped, agg_by, to_agg);
    if (grouped == NULL)
        return NULL;
    grouped = init_grouped_types(grouped, df, agg_by, to_agg);
    if (grouped == NULL)
        return NULL;
    grouped = init_grouped_data(grouped, values);
    if (grouped == NULL)
        return NULL;
    return grouped;
}

dataframe_t *df_groupby(dataframe_t *df, const char *agg_by,
    const char **to_agg, void *(*agg_func)(void **, int))
{
    void **unique_values = df_get_unique_values(df, agg_by);
    dataframe_t *grouped = init_grouped_df(df, agg_by, to_agg, unique_values);
    void **values_with_same_agg_by;

    for (int i = 0; grouped != NULL && to_agg[i] != NULL; i++){
        for (int x = 0; x < grouped->nb_rows; x++){
            values_with_same_agg_by = get_values_with_same_agg_by(df,
                agg_by, to_agg[i], unique_values[x]);
            grouped->data[x][i + 1] = agg_func(values_with_same_agg_by,
                len_values(values_with_same_agg_by));
            free(values_with_same_agg_by);
        }
    }
    for (int x = 0; grouped != NULL && unique_values[x] != NULL; x++)
        grouped->data[x][grouped->nb_columns] = NULL;
    return grouped;
}
