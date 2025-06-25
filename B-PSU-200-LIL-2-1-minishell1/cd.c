/*
** EPITECH PROJECT, 2025
** cd.c
** File description:
** cd.c
*/

#include "lib.h"
#include "my.h"

int word_array_len(char **words)
{
    int i = 0;

    while (words[i] != NULL)
        i++;
    return i;
}

void try_open(char *cmd, char *path)
{
    int fd = open(path, O_RDONLY);

    if (fd == -1) {
        my_putstr(cmd);
        my_putstr(": Not a directory.\n");
    } else {
        my_putstr(cmd);
        my_putstr(": No such file or directory.\n");
    }
}

int handle_home_path(char **words, env_t **envr)
{
    char *home_path = NULL;

    if (word_array_len(words) == 1 || my_strcmp(words[1], "~") == 0) {
        home_path = search_in_env(*envr, "HOME=");
        if (home_path != NULL && chdir(home_path) == 0) {
            free_word_array(words);
            return 0;
        }
        free_word_array(words);
        return 1;
    }
    return -1;
}

int my_cd(char **word, env_t **envr, char *buff)
{
    char **words = my_str_to_word_array(buff, " \t");
    int home_result;

    (void) word;
    home_result = handle_home_path(words, envr);
    if (home_result != -1)
        return home_result;
    if (word_array_len(words) == 2) {
        if (chdir(words[1]) == -1) {
            try_open(words[0], words[1]);
            free_word_array(words);
            return 1;
        }
    }
    free_word_array(words);
    return 0;
}
