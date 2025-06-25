/*
** EPITECH PROJECT, 2024
** main.c
** File description:
** Main File
*/

#include "include/shell.h"

int checker(const char *str)
{
    if (my_strcmp(str, "WIRE") == 0 ||
        my_strcmp(str, "SENSOR") == 0 ||
        my_strcmp(str, "PROCESSOR") == 0 ||
        my_strcmp(str, "DEVICE") == 0 ||
        my_strcmp(str, "ACTUATOR") == 0)
        return true;
    return false;
}

void show_new(const linked_t *new)
{
    my_putstr(new->type);
    my_putstr(" n°");
    my_put_nbr(new->id);
    my_putstr(" - ");
    my_putchar(34);
    my_putstr(new->name);
    my_putchar(34);
    my_putstr(" added.");
    my_putchar('\n');
}

int create_new(linked_t **list, const char *type,
    const char *name, int *id_counter)
{
    linked_t *new = malloc(sizeof(linked_t));

    if (new == NULL)
        return 84;
    new->type = my_strdup(type);
    new->name = my_strdup(name);
    new->id = *id_counter;
    (*id_counter)++;
    new->id = new->id + 1;
    show_new(new);
    new->next = *list;
    *list = new;
    return 0;
}

int add(void *data, char **args)
{
    static int id_counter = -1;
    linked_t **list = data;

    if (args[0] == NULL || args[1] == NULL || data == NULL)
        return 84;
    for (int i = 0; args[i] != NULL; i += 2) {
        if (checker(args[i]) == false)
            return 84;
        if (create_new(list, args[i], args[i + 1], &id_counter) != 0)
            return 84;
    }
    return 0;
}
