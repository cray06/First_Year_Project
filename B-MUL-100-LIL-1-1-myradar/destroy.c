/*
** EPITECH PROJECT, 2025
** destroy.c
** File description:
** destroy.c
*/

#include "include/my.h"

void destroy_all(Game_t *game)
{
    for (int i = 0; game->plane[i] != NULL; i++) {
        sfSprite_destroy(game->plane[i]->sprite);
        sfRectangleShape_destroy(game->plane[i]->rectangle);
        sfClock_destroy(game->plane[i]->clock);
        free(game->plane[i]);
    }
    for (int i = 0; game->tower[i] != NULL; i++) {
        sfCircleShape_destroy(game->tower[i]->circle);
        sfSprite_destroy(game->tower[i]->sprite);
        free(game->tower[i]);
    }
    sfRenderWindow_destroy(game->window);
    sfFont_destroy(game->font);
    sfTexture_destroy(game->texture);
    sfSprite_destroy(game->gameSprite);
    sfText_destroy(game->timer_text);
    free(game);
}
