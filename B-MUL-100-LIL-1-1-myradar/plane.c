/*
** EPITECH PROJECT, 2024
** plane.c
** File description:
** plane.c
*/

#include "include/my.h"

void update_plane_position(plane_parsing_t *plane,
    float dx, float dy, float angle)
{
    sfTime time = sfClock_getElapsedTime(plane->clock);
    float seconds = sfTime_asSeconds(time);
    float distance = sqrt(dx * dx + dy * dy);
    float progress = (plane->plane_speed * seconds / distance);

    if (progress > 1.0f)
        progress = 1.0f;
    plane->x_current = plane->x_start + (dx * progress);
    plane->y_current = plane->y_start + (dy * progress);
    sfSprite_setOrigin(plane->sprite, (sfVector2f){10, 10});
    sfRectangleShape_setOrigin(plane->rectangle, (sfVector2f){10, 10});
    sfSprite_setPosition(plane->sprite,
        (sfVector2f){plane->x_current, plane->y_current});
    sfSprite_setRotation(plane->sprite, angle + 90);
    sfRectangleShape_setPosition(plane->rectangle,
        (sfVector2f){plane->x_current, plane->y_current});
    sfRectangleShape_setRotation(plane->rectangle, angle + 90);
}

bool has_plane_reached_destination(plane_parsing_t *plane,
    tower_parsing_t **towers, int num_towers)
{
    float dx = 0;
    float dy = 0;
    float distance = 0;

    for (int i = 0; i < num_towers; i++) {
        dx = plane->x_current - towers[i]->x_pos;
        dy = plane->y_current - towers[i]->y_pos;
        distance = sqrt(dx * dx + dy * dy);
        if (distance < 1.0f) {
            return true;
        }
    }
    return false;
}

void update_planes(Game_t *game)
{
    quad_tree_t *qt = create_quadtree((Rectangleshape_t){0, 0, 1920, 1080}, 4);

    for (int i = 0; game->plane[i] != NULL; i++) {
        update_active_plane(game, i, qt);
    }
    check_plane_collisions(game, qt);
    free_quadtree(qt);
    remove_marked_planes(game);
}

void remove_plane(Game_t *game, int index)
{
    if (game->plane[index] != NULL) {
        free(game->plane[index]);
        game->destroyed_plane++;
        for (int j = index; game->plane[j] != NULL; j++)
            game->plane[j] = game->plane[j + 1];
    }
}

void free_quadtree(quad_tree_t *qt)
{
    if (qt == NULL)
        return;
    free_quadtree(qt->topleft);
    free_quadtree(qt->topright);
    free_quadtree(qt->bottomleft);
    free_quadtree(qt->bottomright);
    free(qt->planes);
    free(qt);
}
