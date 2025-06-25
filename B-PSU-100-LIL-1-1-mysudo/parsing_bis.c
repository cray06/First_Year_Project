/*
** EPITECH PROJECT, 2025
** parsing.c
** File description:
** parsing.c
*/

#include "include/my.h"

static void process_line(char *line, user_t *user_info)
{
    char **words;
    uid_t current_uid;

    words = my_str_to_word_array(line);
    if (sscanf(words[2], "%d", &current_uid) == 1) {
        if (current_uid == getuid()) {
            user_info->user = my_strdup(words[0]);
        }
    }
    free_word_array(words);
}

char *get_id(user_t *user_info)
{
    FILE *file = fopen("/etc/passwd", "r");
    char line[256];

    if (file == NULL || user_info == NULL)
        return NULL;
    user_info->user = NULL;
    while (fgets(line, sizeof(line), file)) {
        process_line(line, user_info);
        if (user_info->user != NULL)
            break;
    }
    fclose(file);
    return user_info->user;
}

int get_uid(user_t *user_info)
{
    FILE *file = fopen("/etc/passwd", "r");
    char line[256];
    char **words;

    if (file == NULL || user_info == NULL)
        return 0;
    while (fgets(line, sizeof(line), file)) {
        words = my_str_to_word_array(line);
        if (my_strcmp(user_info->u_user, words[0]) == 0) {
            return atoi(words[2]);
        }
    }
    return 0;
}

int get_gid(user_t *user_info)
{
    FILE *file = fopen("/etc/group", "r");
    char line[256];
    char **words;

    if (file == NULL || user_info == NULL)
        return 0;
    while (fgets(line, sizeof(line), file)) {
        words = my_str_to_word_array(line);
        if (my_strcmp(user_info->u_user, words[0]) == 0) {
            return atoi(words[2]);
        }
    }
    return 0;
}
