/*
** EPITECH PROJECT, 2024
** main.c
** File description:
** Main File
*/

#include "include/shell.h"

void show_del(const linked_t *del)
{
    my_putstr(del->type);
    my_putstr(" n°");
    my_put_nbr(del->id);
    my_putstr(" - ");
    my_putchar(34);
    my_putstr(del->name);
    my_putchar(34);
    my_putstr(" deleted.");
    my_putchar('\n');
}

void delete_node(linked_t **list, linked_t *previous, linked_t *current)
{
    if (previous == NULL) {
        *list = current->next;
    } else {
        previous->next = current->next;
    }
    show_del(current);
    free(current);
}

void check_and_delete_node(linked_t **list, linked_t **previous,
    linked_t **current, int id_to_delete)
{
    if ((*current)->id == id_to_delete) {
        delete_node(list, *previous, *current);
        if (*previous == NULL) {
            *current = *list;
        } else {
            *current = (*previous)->next;
        }
    } else {
        *previous = *current;
        *current = (*current)->next;
    }
}

int deleting(linked_t **list, int id_to_delete)
{
    linked_t *current = *list;
    linked_t *previous = NULL;
    int deleted = 0;

    if (current == NULL)
        return 84;
    while (current != NULL) {
        check_and_delete_node(list, &previous, &current, id_to_delete);
        if (current == NULL || current->id != id_to_delete) {
            deleted = 1;
        }
    }
    if (!deleted)
        return 84;
    return 0;
}

int del(void *data, char **args)
{
    linked_t **list = data;
    int id_to_delete = 0;
    int result = 0;

    if (args[0] == NULL || data == NULL)
        return 84;
    for (int i = 0; args[i]; i++) {
        id_to_delete = my_getnbr(args[i]);
        if (id_to_delete < 0 || args[i] == NULL)
            return 84;
        result = deleting(list, id_to_delete);
        if (result == 84) {
            return 84;
        }
    }
    return 0;
}
