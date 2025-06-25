/*
** EPITECH PROJECT, 2025
** env_handling.c
** File description:
** env_handling.c
*/

#include "lib.h"
#include "my.h"

int count_env_nodes(env_t **envr)
{
    int count = 0;
    env_t *current = *envr;

    while (current != NULL) {
        count++;
        current = current->next;
    }
    return count;
}

char *create_env_string(env_t *node)
{
    int value_len = 0;
    char *env_str;

    if (node->value)
        value_len = my_strlen(node->value);
    env_str = malloc(my_strlen(node->data) + value_len + 1);
    if (env_str == NULL)
        return NULL;
    my_strcpy(env_str, node->data);
    if (node->value)
        my_strcat(env_str, node->value);
    return env_str;
}

char **env_to_array(env_t **envr)
{
    int count = count_env_nodes(envr);
    env_t *current = *envr;
    char **env_array = malloc(sizeof(char *) * (count + 1));
    int i = count - 1;

    if (env_array == NULL)
        return NULL;
    while (current != NULL) {
        env_array[i] = create_env_string(current);
        if (env_array[i] == NULL)
            return NULL;
        current = current->next;
        i--;
    }
    env_array[count] = NULL;
    return env_array;
}

char *search_in_env(env_t *envr, const char *key)
{
    while (envr != NULL) {
        if (my_strcmp(envr->data, key) == 0) {
            return envr->value;
        }
        envr = envr->next;
    }
    return NULL;
}

int print_env_list(char **word, env_t **envr, char *buff)
{
    env_t *current = *envr;
    env_t **temp = NULL;

    (void) word;
    (void) buff;
    temp = malloc(count_env_nodes(envr) * sizeof(env_t *));
    if (temp == NULL)
        return 84;
    current = *envr;
    for (int i = 0; i < count_env_nodes(envr); i++) {
        temp[i] = current;
        current = current->next;
    }
    for (int j = count_env_nodes(envr) - 1; j >= 0; j--) {
        my_putstr(temp[j]->data);
        my_putstr(temp[j]->value);
        my_putchar('\n');
    }
    free(temp);
    return 0;
}
