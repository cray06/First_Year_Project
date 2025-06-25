/*
** EPITECH PROJECT, 2024
** main.c
** File description:
** Main File & Main Function
*/

#include "../include/my.h"

int verif_env(char **envp)
{
    for (int i = 0; envp[i] != NULL; i++)
        if (my_strncmp(envp[i], "DISPLAY", 7) == 0)
            return 0;
    write(2, "DISPLAY env variable not found", 30);
    return 84;
}
