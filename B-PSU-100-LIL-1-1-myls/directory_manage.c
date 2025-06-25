/*
** EPITECH PROJECT, 2024
** directory_management.c
** File description:
** directory_manage
*/

#include "include/my.h"

DIR* open_directory(const char *path)
{
    DIR *dir = opendir(path);

    if (!dir) {
        perror("opendir");
        return NULL;
    }
    return dir;
}

void display_directory_contents(int argc, char *argv[], char *flags)
{
    DIR *dir;

    if (argc == 1) {
        dir = open_directory("./");
        print_files_in_directory(dir, flags, argc, argv);
    }
    if (argc == 2) {
        dir = open_directory(argv[1]);
        if (dir != NULL) {
            print_files_in_directory(dir, flags, argc, argv[1]);
            closedir(dir);
        }
    }
}

void display_multiple_directories(int argc, char *argv[], char *flags)
{
    int i = 1;
    DIR *dir;

    while (i < argc) {
        dir = open_directory(argv[i]);
        if (dir != NULL) {
            my_putstr(argv[i]);
            my_putchar('\n');
            print_files_in_directory(dir, flags, argc, argv[i]);
            closedir(dir);
        }
        if (i != argc - 1)
            my_putchar('\n');
        i++;
    }
}
