/*
** EPITECH PROJECT, 2025
** setenv.c
** File description:
** setenv.c
*/

#include "my.h"
#include "lib.h"

env_t *create_env_node(char *name, char *value)
{
    env_t *new_node = malloc(sizeof(env_t));

    if (new_node == NULL)
        return NULL;
    new_node->data = my_strcat(my_strdup(name), "=");
    if (value != NULL)
        new_node->value = my_strdup(value);
    else
        new_node->value = NULL;
    return new_node;
}

int update_existing_env(env_t *current, char *name, char *new_value)
{
    char *var_name = my_strdup(current->data);

    if (var_name == NULL)
        return 1;
    var_name[my_strlen(var_name) - 1] = '\0';
    if (my_strcmp(var_name, name) == 0) {
        free(var_name);
        free(current->value);
        if (new_value != NULL)
            current->value = my_strdup(new_value);
        else
            current->value = NULL;
        return 0;
    }
    free(var_name);
    return -1;
}

int my_setenv(char **word, env_t **envr, char *buff)
{
    env_t *current = *envr;
    int update_result;
    env_t *new_node = NULL;

    (void) buff;
    if (word[1] == NULL)
        return 1;
    new_node = create_env_node(word[1], word[2]);
    while (current != NULL) {
        update_result = update_existing_env(current, word[1], word[2]);
        if (update_result != -1)
            return update_result;
        current = current->next;
    }
    if (new_node == NULL)
        return 1;
    new_node->next = *envr;
    *envr = new_node;
    return 0;
}
