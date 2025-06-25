/*
** EPITECH PROJECT, 2025
** check_sudoers.c
** File description:
** check_sudoers.c
*/

#include "include/my.h"

void check_groups_in(int *in_sudoers, int i, user_t *user_info)
{
    for (int j = 0; user_info->groups[j] != NULL; j++) {
        if (my_strcmp(user_info->sudo_ers[i], user_info->groups[j]) == 0) {
                *in_sudoers = 1;
        }
    }
}

int check_in_sudoers(user_t *user_info)
{
    int in_sudoers = 0;

    for (int i = 0; user_info->sudo_ers[i] != NULL; i++)
        check_groups_in(&in_sudoers, i, user_info);
    if (in_sudoers == 0) {
        printf("%s is not in the sudoers file.\n", user_info->user);
        return 84;
    }
    return 0;
}
