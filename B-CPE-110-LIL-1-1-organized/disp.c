/*
** EPITECH PROJECT, 2024
** main.c
** File description:
** Main File
*/

#include "include/shell.h"

int disp(void *data, char **args)
{
    linked_t **list = data;
    linked_t *value = *list;

    (void)args;
    while (value != NULL) {
        my_putstr(value->type);
        my_putstr(" n°");
        my_put_nbr(value->id);
        my_putstr(" - ");
        my_putchar('"');
        my_putstr(value->name);
        my_putchar('"');
        my_putchar('\n');
        value = value->next;
    }
    return 0;
}
