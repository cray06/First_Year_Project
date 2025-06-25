/*
** EPITECH PROJECT, 2025
** type_to_type
** File description:
** type_to_type
*/
#include "dataframe.h"

void change_int_type(dataframe_t *dataframe, int row, int column)
{
    int *temp = malloc(sizeof(int));

    if (temp != NULL){
        *temp = atoi(dataframe->data[row][column]);
        free(dataframe->data[row][column]);
        dataframe->data[row][column] = temp;
    }
}

void change_uint_type(dataframe_t *dataframe, int row, int column)
{
    unsigned int *temp = malloc(sizeof(unsigned int));

    if (temp != NULL){
        *temp = atoi(dataframe->data[row][column]);
        free(dataframe->data[row][column]);
        dataframe->data[row][column] = temp;
    }
}

void change_float_type(dataframe_t *dataframe, int row, int column)
{
    float *temp = malloc(sizeof(float));

    if (temp != NULL){
        *temp = atof(dataframe->data[row][column]);
        free(dataframe->data[row][column]);
        dataframe->data[row][column] = temp;
    }
}

void change_bool_type(dataframe_t *dataframe, int row, int column)
{
    bool *temp = malloc(sizeof(bool));

    if (temp != NULL){
        if (strcmp(my_strlowcase(dataframe->data[row][column]), "true"))
            *temp = true;
        if (strcmp(my_strlowcase(dataframe->data[row][column]), "false"))
            *temp = false;
        free(dataframe->data[row][column]);
        dataframe->data[row][column] = temp;
    }
}

void change_string_type(dataframe_t *dataframe, int row, int column,
    column_type_t current_type)
{
    char *temp = malloc(sizeof(char *));

    if (temp == NULL)
        return;
    if (current_type == INT)
        sprintf(temp, "%d", *(int *)dataframe->data[row][column]);
    if (current_type == UINT)
        sprintf(temp, "%u", *(unsigned int *)dataframe->data[row][column]);
    if (current_type == FLOAT)
        sprintf(temp, "%f", *(float *)dataframe->data[row][column]);
    if (current_type == BOOL){
        if (*(bool *){dataframe->data[row][column]} == true)
            strcpy(temp, "true");
        else
            strcpy(temp, "false");
    }
    free(dataframe->data[row][column]);
    dataframe->data[row][column] = temp;
}
