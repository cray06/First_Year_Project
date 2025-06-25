/*
** EPITECH PROJECT, 2024
** heart.c
** File description:
** heart.c
*/

#include "include/my.h"

void initialize_hearts(Game_t *game)
{
    sfVector2f position;
    sfVector2f scale;

    for (int i = 0; i < 3; i++) {
        game->heartSprites[i] = create_heart("ressource/heart.png");
        position = (sfVector2f){10 + i * 65, 20};
        scale = (sfVector2f){0.2, 0.2};
        sfSprite_setScale(game->heartSprites[i], scale);
        sfSprite_setPosition(game->heartSprites[i], position);
    }
}

sfSprite *create_heart(const char *filepath)
{
    sfTexture *texture = sfTexture_createFromFile(filepath, NULL);
    sfSprite *heartSprite = sfSprite_create();

    sfSprite_setTexture(heartSprite, texture, sfTrue);
    return heartSprite;
}
