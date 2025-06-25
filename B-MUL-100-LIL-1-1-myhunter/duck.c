/*
** EPITECH PROJECT, 2024
** duck.c
** File description:
** duck.c
*/

#include "include/my.h"

duck_t *create_duck(const char *filepath)
{
    duck_t *duck = malloc(sizeof(duck_t));
    sfTexture *texture;

    if (!duck)
        return NULL;
    duck->sprite = sfSprite_create();
    texture = sfTexture_createFromFile(filepath, NULL);
    if (!texture) {
        free(duck);
        return NULL;
    }
    sfSprite_setTexture(duck->sprite, texture, sfTrue);
    duck->speed = 5.0f;
    return duck;
}

void destroy_duck(duck_t *duck)
{
    sfTexture* texture = (sfTexture*)sfSprite_getTexture(duck->sprite);

    sfTexture_destroy(texture);
    sfSprite_destroy(duck->sprite);
    free(duck);
}

void move_duck(duck_t *duck, float offsetX, float offsetY)
{
    sfVector2f position = sfSprite_getPosition(duck->sprite);

    position.x += offsetX * duck->speed;
    position.y += offsetY;
    sfSprite_setPosition(duck->sprite, position);
}

void animate_duck(duck_t *duck, int frame)
{
    sfIntRect rect = { frame * 110, 0, 110, 110 };

    sfSprite_setTextureRect(duck->sprite, rect);
}

void check_duck_click(Game_t *game, sfVector2i mousePos)
{
    sfFloatRect bounds;
    sfVector2f newPosition;

    for (int i = 0; i < 4; i++) {
        bounds = sfSprite_getGlobalBounds(game->ducks[i]->sprite);
        if (sfFloatRect_contains(&bounds, mousePos.x, mousePos.y)) {
            game->score++;
            newPosition = (sfVector2f){0, rand() % 880};
            sfSprite_setPosition(game->ducks[i]->sprite, newPosition);
        }
    }
}
