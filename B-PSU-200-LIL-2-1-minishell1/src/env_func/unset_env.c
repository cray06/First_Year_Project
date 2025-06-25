/*
** EPITECH PROJECT, 2025
** unsetenv
** File description:
** unsetenv
*/

#include "my.h"
#include "lib.h"

void free_env_node(env_t *node)
{
    free(node->data);
    free(node->value);
    free(node);
}

int remove_env_node(env_t **envr, env_t *current, env_t *prev)
{
    if (prev == NULL)
        *envr = current->next;
    else
        prev->next = current->next;
    free_env_node(current);
    return 0;
}

int check_env_var(env_t *current, char *target)
{
    char *var_name = my_strdup(current->data);
    int result;

    if (var_name == NULL)
        return -1;
    var_name[my_strlen(var_name) - 1] = '\0';
    result = my_strcmp(var_name, target);
    free(var_name);
    return result;
}

int my_unsetenv(char **word, env_t **envr, char *buff)
{
    env_t *current;
    env_t *prev = NULL;
    int cmp_result;

    (void) buff;
    if (word[1] == NULL)
        return 1;
    current = *envr;
    while (current != NULL) {
        cmp_result = check_env_var(current, word[1]);
        if (cmp_result == -1)
            return 1;
        if (cmp_result == 0)
            return remove_env_node(envr, current, prev);
        prev = current;
        current = current->next;
    }
    return 0;
}
