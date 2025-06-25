/*
** EPITECH PROJECT, 2025
** game_bis.c
** File description:
** game_bis.c
*/

#include "include/my.h"

void activate_planes(Game_t *game)
{
    sfTime time = sfClock_getElapsedTime(game->clock);
    float elapsed = sfTime_asSeconds(time);

    for (int i = 0; game->plane[i] != NULL; i++) {
        if (!game->plane[i]->active && elapsed >= game->plane[i]->delay) {
            game->plane[i]->active = true;
            game->plane[i]->x_current = game->plane[i]->x_start;
            game->plane[i]->y_current = game->plane[i]->y_start;
            sfSprite_setPosition(game->plane[i]->sprite,
                (sfVector2f){game->plane[i]->x_start,
                    game->plane[i]->y_start});
            sfRectangleShape_setPosition(game->plane[i]->rectangle,
                (sfVector2f){game->plane[i]->x_start,
                    game->plane[i]->y_start});
            sfClock_restart(game->plane[i]->clock);
        }
    }
}
