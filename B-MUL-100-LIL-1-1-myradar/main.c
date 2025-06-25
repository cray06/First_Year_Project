/*
** EPITECH PROJECT, 2024
** main.c
** File description:
** Main File & Main Function
*/

#include "include/my.h"

void print_h_option(void)
{
    write(1, "Air traffic simulation panel\n", 29);
    write(1, "USAGE\n", 6);
    write(1, "  ./my_radar [OPTIONS] path_to_script\n", 38);
    write(1, "   path_to_script    The path to the script file.\n", 51);
    write(1, "OPTIONS\n", 8);
    write(1, "  -h                      print the usage and quit\n", 51);
    write(1, "USER INTERACTIONS\n", 19);
    write(1, "  'L' key         enable/disable hitboxes and areas.\n", 53);
    write(1, "  'S' key         enable/disable sprites.\n", 42);
}

int init_main(int argc, char *argv[], char **envp, Game_t **game)
{
    if (error_handling(argc, argv, envp) == 84) {
        write(2, "Error: Invalid arguments or environment\n", 39);
        return 84;
    }
    *game = malloc(sizeof(Game_t));
    if (*game == NULL) {
        write(2, "Error: Memory allocation failed\n", 31);
        return 84;
    }
    if (init_planes_and_towers(argv[1], *game) == 84) {
        write(2, "Error: Failed to initialize planes and towers\n", 45);
        return 84;
    }
    return 0;
}

int init_planes_and_towers(const char *path, Game_t *game)
{
    int nb_planes = nb_plane(path, game);
    int nb_towers = nb_tower(path, game);

    game->plane = malloc(sizeof(plane_parsing_t *) * (nb_planes + 1));
    game->tower = malloc(sizeof(tower_parsing_t *) * (nb_towers + 1));
    if (game->plane == NULL || game->tower == NULL) {
        write(2, "Error: Memory allocation failed for planes or towers\n", 52);
        return 84;
    }
    for (int i = 0; i <= nb_planes; i++)
        game->plane[i] = NULL;
    for (int i = 0; i <= nb_towers; i++)
        game->tower[i] = NULL;
    return 0;
}

int main(int argc, char *argv[], char **envp)
{
    Game_t *game;

    if (init_main(argc, argv, envp, &game) == 84)
        return 84;
    if (parse_info_plane(argv[1], game, game->plane) == 84) {
        write(2, "Error: Failed to parse plane information\n", 40);
        return 84;
    }
    if (parse_info_tower(argv[1], game, game->tower) == 84) {
        write(2, "Error: Failed to parse tower information\n", 40);
        return 84;
    }
    display_windows(game);
    return 0;
}
