/*
** EPITECH PROJECT, 2025
** flag_command.c
** File description:
** flag_command.c
*/

#include "include/my.h"

void process_flags(char *argv[], user_t *user_info)
{
    if (u_flag(argv)) {
        user_info->u_user = my_strdup(argv[u_flag(argv) + 1]);
        user_info->user_id = get_uid(user_info);
    }
    if (g_flag(argv)) {
        user_info->u_user = my_strdup(argv[g_flag(argv) + 1]);
        user_info->group_id = get_gid(user_info);
    }
    user_info->groups = get_group(user_info);
    if (!u_flag(argv) && !g_flag(argv))
        user_info->sudo_ers = get_sudoers(user_info);
}

int u_flag(char **av)
{
    for (int i = 1; av[i] != NULL && av[i][0] == '-'; i++) {
        if (av[i][my_strlen(av[i]) - 1] == 'u')
            return i;
    }
    return 0;
}

int g_flag(char **av)
{
    for (int i = 1; av[i] != NULL && av[i][0] == '-'; i++) {
        if (av[i][my_strlen(av[i]) - 1] == 'g')
            return i;
    }
    return 0;
}

char **command(char **av)
{
    int flag_u = u_flag(av);
    int flag_g = g_flag(av);
    int skip = 1;

    if (flag_u)
        skip = flag_u + 2;
    else if (flag_g)
        skip = flag_g + 2;
    return &av[skip];
}
