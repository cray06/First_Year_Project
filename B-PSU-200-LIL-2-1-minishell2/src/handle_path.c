/*
** EPITECH PROJECT, 2025
** handle_path.c
** File description:
** handle_path.c
*/

#include "lib.h"
#include "my.h"

char *get_path(env_t **envr)
{
    env_t *current = *envr;

    while (current != NULL) {
        if (my_strncmp(current->data, "PATH=", 5) == 0)
            return current->value;
        current = current->next;
    }
    return NULL;
}

char *get_command_path(command_t *value, env_t **envr, char *command)
{
    char *path = get_path(envr);
    char *command_path = NULL;
    int fd = 0;

    value->all_path = my_str_to_word_array(path, " \t:");
    for (int i = 0; value->all_path[i] != NULL; i++) {
        command_path = malloc(strlen(value->all_path[i])
            + strlen(command) + 2);
        if (command_path == NULL)
            return NULL;
        command_path[0] = '\0';
        my_strcat(command_path, value->all_path[i]);
        my_strcat(command_path, "/");
        my_strcat(command_path, command);
        fd = open(command_path, O_RDONLY);
        if (fd != -1)
            return command_path;
        free(command_path);
    }
    return NULL;
}
