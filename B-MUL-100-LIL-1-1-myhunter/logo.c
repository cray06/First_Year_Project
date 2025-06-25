/*
** EPITECH PROJECT, 2024
** logo.c
** File description:
** logo.c
*/

#include "include/my.h"

sfSprite *create_logo(const char *filepath)
{
    sfTexture *texture = sfTexture_createFromFile(filepath, NULL);
    sfSprite *logoSprite = sfSprite_create();
    sfVector2f position = (sfVector2f){860, 390};

    sfSprite_setTexture(logoSprite, texture, sfTrue);
    sfSprite_setPosition(logoSprite, position);
    return logoSprite;
}
