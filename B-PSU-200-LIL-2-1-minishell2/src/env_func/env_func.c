/*
** EPITECH PROJECT, 2025
** fill_env.c
** File description:
** fill_env.c
*/

#include "lib.h"
#include "my.h"

void add_nlspath(env_t **envr)
{
    env_t *new_node = malloc(sizeof(env_t));

    if (new_node == NULL)
        return;
    new_node->data = my_strdup("NLSPATH=");
    new_node->value = my_strdup("/usr/share/locale/%L/LC_MESSAGES/%N.cat:"
        "/usr/share/locale/%l/LC_MESSAGES/%N.cat");
    new_node->next = *envr;
    *envr = new_node;
}

env_t **fill_env(env_t **envr, char **env)
{
    char **env_array = NULL;
    env_t *new_node;

    if (env == NULL)
        return NULL;
    for (int i = 0; env[i]; i++) {
        new_node = malloc(sizeof(env_t));
        if (new_node == NULL) {
            free_env(*envr);
            return NULL;
        }
        env_array = my_str_to_word_array(env[i], " \t=\n");
        new_node->data = my_strdup(my_strcat(env_array[0], "="));
        new_node->value = my_strdup(env_array[1]);
        new_node->next = *envr;
        *envr = new_node;
        free_word_array(env_array);
    }
    add_nlspath(envr);
    return envr;
}

void free_env(env_t *envr)
{
    env_t *tmp;

    while (envr != NULL) {
        tmp = envr->next;
        free(envr->data);
        if (envr->value != NULL)
            free(envr->value);
        free(envr);
        envr = tmp;
    }
}
