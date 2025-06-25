/*
** EPITECH PROJECT, 2025
** parsing.c
** File description:
** parsing.c
*/

#include "include/my.h"

char **get_group(user_t *user_info)
{
    FILE *file = fopen("/etc/group", "r");
    char line[256];
    char **words;
    int j = 1;

    user_info->groups = malloc(sizeof(char *) * 10000);
    if (file == NULL)
        return NULL;
    user_info->groups[0] = my_strdup(user_info->user);
    while (fgets(line, sizeof(line), file)) {
        words = my_str_to_word_array(line);
        if (my_strstr(words[3], user_info->user) != NULL) {
            user_info->groups[j] = my_strdup(words[0]);
            j++;
        }
    }
    user_info->groups[j] = NULL;
    return user_info->groups;
}

void process_sudoers_line(char **words, user_t *user_info, int *j)
{
    if (words[0][0] != '#' && words[0][0] != '\n') {
        if (words[0][0] == '%')
            user_info->sudo_ers[*j] = my_strdup(words[0] + 1);
        else
            user_info->sudo_ers[*j] = my_strdup(words[0]);
        (*j)++;
    }
}

char **get_sudoers(user_t *user_info)
{
    FILE *file = fopen("/etc/sudoers", "r");
    char line[256];
    char **words;
    int j = 0;

    user_info->sudo_ers = malloc(sizeof(char *) * 10000);
    if (file == NULL || user_info->sudo_ers == NULL)
        return NULL;
    while (fgets(line, sizeof(line), file)) {
        words = my_str_to_word_array(line);
        process_sudoers_line(words, user_info, &j);
    }
    user_info->sudo_ers[j] = NULL;
    return user_info->sudo_ers;
}

int check_passwd(char *passwd, user_t *user_info)
{
    FILE *file = fopen("/etc/shadow", "r");
    char line[256];
    char **words;

    if (file == NULL)
        return 84;
    while (fgets(line, sizeof(line), file)) {
        words = my_str_to_word_array(line);
        if (my_strcmp(user_info->user, words[0]) == 0
            && my_strcmp(words[1], crypt(passwd, words[1])) == 0) {
            free_word_array(words);
            fclose(file);
            return 1;
        }
    }
    fclose(file);
    return 0;
}
