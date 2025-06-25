/*
** EPITECH PROJECT, 2024
** main.c
** File description:
** Main File
*/

#include "include/shell.h"

int compare_by_id(linked_t *a, linked_t *b)
{
    return a->id - b->id;
}

int compare_by_name(linked_t *a, linked_t *b)
{
    return my_strcmp(a->name, b->name);
}

int compare_by_type(linked_t *a, linked_t *b)
{
    return my_strcmp(a->type, b->type);
}
