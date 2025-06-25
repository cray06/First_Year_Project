/*
** EPITECH PROJECT, 2025
** error_handling.c
** File description:
** error_handling.c
*/

#include "include/my.h"

int check_images_exist(void)
{
    const char *images[] = {
        "ressource/font.ttf", NULL
    };
    FILE *fd;

    for (int i = 0; images[i] != NULL; i++) {
        fd = fopen(images[i], "r");
        if (fd == NULL) {
            my_putstr("Failed to load image : ");
            my_putstr(images[i]);
            return 84;
        } else {
            fclose(fd);
        }
    }
    return 0;
}

int error_handling(int argc, char *argv[], char **envp)
{
    if (envp[0] == NULL) {
        write(2, "You need to have an environment", 31);
        return 84;
    }
    if (verif_env(envp) == 84)
        return 84;
    if (argc > 2)
        return 84;
    if (argc == 2 && (argv[1][0] == 'h' || argv[1][1] == 'h')) {
        print_h_option();
        return 0;
    }
    if (check_images_exist() == 84)
        return 84;
    return 0;
}
