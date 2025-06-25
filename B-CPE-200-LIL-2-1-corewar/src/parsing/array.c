/*
** EPITECH PROJECT, 2025
** array
** File description:
** array
*/
#include "my.h"

int get_len_index_array(int *index_array)
{
    int len = 0;

    for (; index_array != NULL && index_array[len] != -1; len++);
    return len;
}

int is_in_array(int *array, int index)
{
    for (int i = 0; array != NULL && array[i] != -1; i++){
        if (array[i] == index)
            return 1;
    }
    return 0;
}

int *add_index_in_array(int *array, int new_index)
{
    int len_array = get_len_index_array(array);
    int *new_array = malloc(sizeof(int) * (len_array + 2));
    int i = 0;

    if (new_array == NULL)
        return NULL;
    for (; array != NULL && i < len_array; i++)
        new_array[i] = array[i];
    new_array[i] = new_index;
    new_array[i + 1] = -1;
    free(array);
    return new_array;
}
