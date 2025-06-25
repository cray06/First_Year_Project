/*
** EPITECH PROJECT, 2024
** tower.c
** File description:
** tower.c
*/

#include "include/my.h"

sfCircleShape *create_circle(Game_t *game, int i)
{
    sfCircleShape *circle = sfCircleShape_create();

    sfCircleShape_setRadius(circle, game->tower[i]->radius * 5);
    sfCircleShape_setPosition(circle, (sfVector2f)
        {game->tower[i]->x_pos - game->tower[i]->radius * 5,
        game->tower[i]->y_pos -
        game->tower[i]->radius * 5});
    sfCircleShape_setFillColor(circle, sfTransparent);
    sfCircleShape_setOutlineColor(circle, sfRed);
    sfCircleShape_setOutlineThickness(circle, 3);
    return circle;
}

void create_tower(Game_t *game)
{
    sfTexture *texture = NULL;
    sfSprite *sprite = NULL;
    sfCircleShape *circle = NULL;

    for (int i = 0; game->tower[i] != NULL; i++) {
        if (game->tower[i]->radius == 0) {
            game->tower[i]->radius = 1;
        }
        circle = create_circle(game, i);
        texture = sfTexture_createFromFile("ressource/tower.png", NULL);
        sprite = sfSprite_create();
        sfSprite_setTexture(sprite, texture, sfTrue);
        sfSprite_setPosition(sprite, (sfVector2f)
            {game->tower[i]->x_pos - 51, game->tower[i]->y_pos - 51});
        game->tower[i]->sprite = sprite;
        game->tower[i]->circle = circle;
    }
}

void draw_towers(Game_t *game)
{
    for (int i = 0; game->tower[i] != NULL; i++) {
        if (game->show_hitbox && game->tower[i]->circle != NULL) {
            sfRenderWindow_drawCircleShape(game->window,
                game->tower[i]->circle, NULL);
        }
        if (game->show_sprites && game->tower[i]->sprite != NULL) {
            sfRenderWindow_drawSprite(game->window,
                game->tower[i]->sprite, NULL);
        }
    }
}
