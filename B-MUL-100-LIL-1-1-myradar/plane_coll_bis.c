/*
** EPITECH PROJECT, 2025
** plane_coll_bis.c
** File description:
** plane_coll_bis.c
*/

#include "include/my.h"

bool should_remove_planes(plane_parsing_t *plane1,
    plane_parsing_t *plane2,
    Game_t *game)
{
    return (!is_in_control_area(plane1, game->tower, game->nb_tower) &&
        !is_in_control_area(plane2, game->tower, game->nb_tower));
}

void remove_plane_pair(Game_t *game, int index1, int index2)
{
    if (game->plane[index1])
        game->plane[index1]->removed = true;
    if (game->plane[index2])
        game->plane[index2]->removed = true;
}

void process_collision(Game_t *game, plane_parsing_t *current_plane,
    plane_parsing_t *found_plane)
{
    if (found_plane != current_plane) {
        handle_plane_collision(game, current_plane, found_plane);
    }
}
