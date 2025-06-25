/*
** EPITECH PROJECT, 2024
** main.c
** File description:
** main.c
*/

#include "include/my.h"

void print_arguments(int argc, char *argv[])
{
    for (int i = 0; i < argc; i++) {
        my_putstr(argv[i]);
        my_putchar(' ');
    }
    my_putchar('\n');
}

void handle_argument_check(int *argc, char *argv[])
{
    char *flags = get_flag(argc, argv);
    int new_argc = *argc;
    int move_index = 1;

    for (int i = 1; i < new_argc; i++) {
        if (argv[i][0] != '-') {
            argv[move_index] = argv[i];
            move_index++;
        }
    }
    *argc = move_index;
    if (*argc == 1 || *argc == 2) {
        display_directory_contents(*argc, argv, flags);
    } else if (*argc > 2) {
        display_multiple_directories(*argc, argv, flags);
    }
}

int main(int argc, char *argv[])
{
    handle_argument_check(&argc, argv);
    return 0;
}
