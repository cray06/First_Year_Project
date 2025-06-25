/*
** EPITECH PROJECT, 2025
** init.c
** File description:
** init.c
*/

#include "include/my.h"

void initialize_game(Game_t *game)
{
    game->texture = sfTexture_createFromFile("ressource/background.png", NULL);
    game->window = sfRenderWindow_create(
        (sfVideoMode){1920, 1080, 32},
        "My Radar", sfClose, NULL);
    game->gameSprite = sfSprite_create();
    sfSprite_setTexture(game->gameSprite, game->texture, sfTrue);
    sfRenderWindow_setFramerateLimit(game->window, 60);
    create_tower(game);
    game->destroyed_plane = 0;
    game->show_hitbox = true;
    game->show_sprites = true;
    initialize_planes(game);
    timer(game);
}

void timer(Game_t *game)
{
    game->clock = sfClock_create();
    game->font = sfFont_createFromFile("ressource/font.ttf");
    game->timer_text = sfText_create();
    sfText_setFont(game->timer_text, game->font);
    sfText_setCharacterSize(game->timer_text, 24);
    sfText_setPosition(game->timer_text, (sfVector2f){1800, 20});
    sfText_setColor(game->timer_text, sfBlack);
}

void initialize_plane_sprite(Game_t *game, int i)
{
    sfTexture *planeTexture =
        sfTexture_createFromFile("ressource/plane.png", NULL);

    game->plane[i]->sprite = sfSprite_create();
    sfSprite_setTexture(game->plane[i]->sprite, planeTexture, sfTrue);
    game->plane[i]->x_current = game->plane[i]->x_start;
    game->plane[i]->y_current = game->plane[i]->y_start;
    sfSprite_setPosition(game->plane[i]->sprite,
        (sfVector2f){game->plane[i]->x_start, game->plane[i]->y_start});
}

void initialize_plane_rectangle(Game_t *game, int i)
{
    game->plane[i]->rectangle = sfRectangleShape_create();
    sfRectangleShape_setSize(game->plane[i]->rectangle,
        (sfVector2f){20, 20});
    sfRectangleShape_setFillColor(game->plane[i]->rectangle,
        sfTransparent);
    sfRectangleShape_setOutlineColor(game->plane[i]->rectangle, sfGreen);
    sfRectangleShape_setOutlineThickness(game->plane[i]->rectangle, 1);
    sfRectangleShape_setPosition(game->plane[i]->rectangle,
        (sfVector2f){game->plane[i]->x_start, game->plane[i]->y_start});
    game->plane[i]->clock = sfClock_create();
}

void initialize_planes(Game_t *game)
{
    for (int i = 0; game->plane[i] != NULL; i++) {
        initialize_plane_sprite(game, i);
        initialize_plane_rectangle(game, i);
        game->plane[i]->active = false;
        game->plane[i]->removed = false;
        game->plane[i]->x_current = game->plane[i]->x_start;
        game->plane[i]->y_current = game->plane[i]->y_start;
    }
}
