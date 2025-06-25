/*
** EPITECH PROJECT, 2024
** heart.c
** File description:
** heart.c
*/

#include "include/my.h"

void cleanup_game(Game_t *game, sfTexture *gameTexture)
{
    for (int i = 0; i < 4; i++)
        destroy_duck(game->ducks[i]);
    for (int i = 0; i < 3; i++)
        sfSprite_destroy(game->heartSprites[i]);
    sfSprite_destroy(game->gameSprite);
    sfTexture_destroy(gameTexture);
    sfClock_destroy(game->clock);
}

void cleanup_menu(Menu_t *menu, sfTexture *menuTexture)
{
    sfSprite_destroy(menu->menuSprite);
    sfSprite_destroy(menu->startButtonSprite);
    sfSprite_destroy(menu->exitButtonSprite);
    sfSprite_destroy(menu->logoSprite);
    sfTexture_destroy(menuTexture);
    sfRenderWindow_destroy(menu->window);
}
