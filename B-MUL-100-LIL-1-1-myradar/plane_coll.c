/*
** EPITECH PROJECT, 2025
** plane_coll.c
** File description:
** plane_coll.c
*/

#include "include/my.h"

int find_plane_index(Game_t *game, plane_parsing_t *plane)
{
    for (int i = 0; game->plane[i] != NULL; i++) {
        if (game->plane[i] == plane) {
            return i;
        }
    }
    return -1;
}

void handle_plane_collision(Game_t *game,
    plane_parsing_t *plane1, plane_parsing_t *plane2)
{
    Rectangleshape_t rect1;
    Rectangleshape_t rect2;
    int index1;
    int index2;

    if (!plane1 || !plane2 || !plane1->rectangle || !plane2->rectangle)
        return;
    rect1 = (Rectangleshape_t){plane1->x_current - 14, plane1->y_current - 14,
        20, 20};
    rect2 = (Rectangleshape_t){plane2->x_current - 14, plane2->y_current - 14,
        20, 20};
    if (!rectangles_intersect(rect1, rect2))
        return;
    if (!should_remove_planes(plane1, plane2, game))
        return;
    index1 = find_plane_index(game, plane1);
    index2 = find_plane_index(game, plane2);
    if (index1 >= 0 && index2 >= 0 && index1 < game->nb_plane
        && index2 < game->nb_plane)
        remove_plane_pair(game, index1, index2);
}

void check_plane_collisions(Game_t *game, quad_tree_t *qt)
{
    int count = 0;
    Rectangleshape_t range;
    plane_parsing_t *found[game->nb_plane];

    for (int i = 0; game->plane[i] != NULL; i++) {
        range = (Rectangleshape_t){
            game->plane[i]->x_current - 14,
            game->plane[i]->y_current - 14,
            20,
            20
        };
        count = 0;
        search(qt, range, found, &count);
        for (int j = 0; j < count; j++) {
            process_collision(game, game->plane[i], found[j]);
        }
    }
}
