/*
** EPITECH PROJECT, 2025
** parsing.c
** File description:
** parsing.c
*/

#include "lib.h"
#include "my.h"

char *get_full_path(char *buff, char **paths, char **buffer)
{
    char *npath = NULL;
    int fd = 0;

    for (int i = 0; paths[i] != NULL; i++) {
        npath =
            malloc(sizeof(char) * (my_strlen(paths[i]) + my_strlen(buff) + 2));
        if (npath == NULL)
            return NULL;
        npath[0] = '\0';
        my_strcat(npath, paths[i]);
        my_strcat(npath, "/");
        my_strcat(npath, buffer[0]);
        fd = open(npath, O_RDONLY);
        if (fd != -1) {
            close(fd);
            return npath;
        }
        free(npath);
    }
    return NULL;
}

static int is_builtin_command(char **buffer, char **command)
{
    for (int i = 0; i < 5; i++)
        if (my_strcmp(buffer[0], command[i]) == 0)
            return 1;
    return 0;
}

char *get_command(char *buff, char *path, char **command)
{
    char **paths = my_str_to_word_array(path, " \t:");
    char **buffer = my_str_to_word_array(buff, " \t");
    char *fullpath = NULL;
    char *result = NULL;

    if (buff == NULL || path == NULL)
        return NULL;
    if (is_builtin_command(buffer, command)) {
        result = my_strdup(buff);
        free_word_array(paths);
        free_word_array(buffer);
        return result;
    }
    fullpath = get_full_path(buff, paths, buffer);
    free_word_array(paths);
    free_word_array(buffer);
    if (fullpath != NULL)
        return fullpath;
    else
        return my_strdup(buff);
}

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
