/*
** EPITECH PROJECT, 2024
** main.c
** File description:
** Main File & Main Function
*/

#include "include/my.h"

int check_images_exist(void)
{
    const char *images[] = {
        "ressource/duck.png", "ressource/heart.png", "ressource/font.ttf",
        "ressource/game_bg.png", "ressource/gradient.png",
        "ressource/start_button.png", "ressource/exit_button.png",
        "ressource/logo.png", "ressource/Game_lost.png",
        "ressource/cursor.png", "ressource/retry_button.png", NULL
    };
    int fd = 0;

    for (int i = 0; images[i] != NULL; i++) {
        fd = open(images[i], O_RDONLY);
        if (fd == -1) {
            my_putstr("Failed to load image : ");
            my_putstr(images[i]);
            return 84;
        } else {
            close(fd);
        }
    }
    return 0;
}

int main(int argc, char *argv[], char **envp)
{
    const char *help = "My_Hunter is an epitech project, based"
    " on the original duck hunt.\nUsage: ./my_hunter\n";

    if (envp[0] == NULL) {
        write(2, "You need to have an environment", 31);
        return 84;
    }
    if (verif_env(envp) == 84)
        return 84;
    if (argc == 2 && (argv[1][0] == 'h' || argv[1][1] == 'h')) {
        write(1, help, my_strlen(help));
        return 0;
    }
    if (check_images_exist() == 84)
        return 84;
    display_windows();
    return 0;
}
