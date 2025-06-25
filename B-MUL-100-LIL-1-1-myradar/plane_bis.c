/*
** EPITECH PROJECT, 2025
** plane_bis.c
** File description:
** plane_bis.c
*/

#include "include/my.h"

bool should_remove_plane(plane_parsing_t *plane,
    tower_parsing_t **tower, int nb_tower)
{
    return plane->x_current != plane->x_start &&
        plane->y_current != plane->y_start &&
        has_plane_reached_destination(plane, tower, nb_tower);
}

void remove_marked_planes(Game_t *game)
{
    for (int i = 0; game->plane[i] != NULL; i++) {
        if (game->plane[i]->removed) {
            remove_plane(game, i);
            i--;
        }
    }
}

void update_active_plane(Game_t *game, int i, quad_tree_t *qt)
{
    float dx = 0;
    float dy = 0;
    float angle = 0;

    if (game->plane[i]->active && !game->plane[i]->removed) {
        dx = game->plane[i]->x_end - game->plane[i]->x_start;
        dy = game->plane[i]->y_end - game->plane[i]->y_start;
        angle = atan2(dy, dx) * 180 / 3.14159265358979323846;
        update_plane_position(game->plane[i], dx, dy, angle);
        if (should_remove_plane(game->plane[i],
            game->tower, game->nb_tower)) {
            game->plane[i]->removed = true;
            return;
        }
        if (!is_in_control_area(game->plane[i], game->tower, game->nb_tower)) {
            insert(qt, game->plane[i]);
        }
    }
}
