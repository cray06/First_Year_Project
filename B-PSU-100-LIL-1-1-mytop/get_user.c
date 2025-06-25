/*
** EPITECH PROJECT, 2024
** main.c
** File description:
** main.c
*/

#include "include/my.h"

void get_user_name_from_line(char *line, int uid,
    char *user_name, size_t size)
{
    char *colon1 = strchr(line, ':');
    char *username;
    char *colon2;
    char *uid_str;
    char *colon3;

    if (!colon1)
        return;
    *colon1 = '\0';
    username = line;
    colon2 = strchr(colon1 + 1, ':');
    if (!colon2)
        return;
    uid_str = colon2 + 1;
    colon3 = strchr(uid_str, ':');
    if (colon3)
        *colon3 = '\0';
    if (atoi(uid_str) == uid)
        strncpy(user_name, username, size);
}

void get_user_name(int uid, char *user_name, size_t size)
{
    FILE *passwd_file;
    char line[256];

    passwd_file = fopen("/etc/passwd", "r");
    if (passwd_file == NULL) {
        snprintf(user_name, size, "%d", uid);
        return;
    }
    while (fgets(line, sizeof(line), passwd_file)) {
        get_user_name_from_line(line, uid, user_name, size);
        if (strncmp(user_name, line, size) != 0) {
            fclose(passwd_file);
            return;
        }
    }
    snprintf(user_name, size, "%d", uid);
    fclose(passwd_file);
}
