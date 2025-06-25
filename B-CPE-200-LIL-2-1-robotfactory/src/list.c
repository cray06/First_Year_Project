/*
** EPITECH PROJECT, 2025
** list
** File description:
** list
*/
#include "asm.h"

line_t *set_line(char **array)
{
    line_t *line = malloc(sizeof(*line));
    static int index = 0;

    if (line == NULL)
        return NULL;
    line->array = array;
    if (array[0] != NULL && array[0][my_strlen(array[0]) - 1] == ':' &&
        array[0][0] != '#'){
        array[0][my_strlen(array[0]) - 1] = '\0';
        line->label = array[0];
        line->args = array + 1;
    } else {
        line->label = NULL;
        line->args = array;
    }
    line->size_line = get_size_of_line(line->args);
    line->index = index;
    index++;
    return line;
}

void push_to_list(linked_list_t **begin, void *data)
{
    linked_list_t *new_linked_list = malloc(sizeof(*new_linked_list));

    if (new_linked_list != NULL)
        new_linked_list->data = data;
        new_linked_list->next = *begin;
        *begin = new_linked_list;
}
