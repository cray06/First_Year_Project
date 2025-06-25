/*
** EPITECH PROJECT, 2025
** signal.c
** File description:
** signal.c
*/

#include "my.h"
#include "lib.h"

int check_core_dump(void)
{
    struct stat buffer;

    return (stat("core", &buffer) == 0);
}

int check_signal(int status)
{
    if (WTERMSIG(status) == 11 && check_core_dump()) {
        my_putstr("Segmentation fault (core dumped)\n");
        return 0;
    }
    if (WTERMSIG(status) == 11) {
        my_putstr("Segmentation fault\n");
        return 0;
    }
    return 0;
}
