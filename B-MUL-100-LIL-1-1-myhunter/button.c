/*
** EPITECH PROJECT, 2024
** button.c
** File description:
** button.c
*/

#include "include/my.h"

bool is_button_pressed(sfRenderWindow* window, sfSprite* buttonSprite)
{
    sfVector2i mousePos = sfMouse_getPositionRenderWindow(window);
    sfFloatRect bounds = sfSprite_getGlobalBounds(buttonSprite);

    return sfFloatRect_contains(&bounds, mousePos.x, mousePos.y);
}

sfSprite *create_exit_button(const char *filepath)
{
    sfTexture *texture = sfTexture_createFromFile(filepath, NULL);
    sfSprite *buttonSprite = sfSprite_create();
    sfVector2f position = (sfVector2f){860, 590};

    sfSprite_setTexture(buttonSprite, texture, sfTrue);
    sfSprite_setPosition(buttonSprite, position);
    return buttonSprite;
}

sfSprite *create_start_button(const char *filepath)
{
    sfTexture *texture = sfTexture_createFromFile(filepath, NULL);
    sfSprite *buttonSprite = sfSprite_create();
    sfVector2f position = (sfVector2f){860, 490};

    sfSprite_setTexture(buttonSprite, texture, sfTrue);
    sfSprite_setPosition(buttonSprite, position);
    return buttonSprite;
}

sfSprite *create_retry_button(const char *filepath)
{
    sfTexture *texture = sfTexture_createFromFile(filepath, NULL);
    sfSprite *buttonSprite = sfSprite_create();
    sfVector2f position = (sfVector2f){860, 490};

    sfSprite_setTexture(buttonSprite, texture, sfTrue);
    sfSprite_setPosition(buttonSprite, position);
    return buttonSprite;
}

sfSprite *create_final_exit(const char *filepath)
{
    sfTexture *texture = sfTexture_createFromFile(filepath, NULL);
    sfSprite *buttonSprite = sfSprite_create();
    sfVector2f position = (sfVector2f){860, 590};

    sfSprite_setTexture(buttonSprite, texture, sfTrue);
    sfSprite_setPosition(buttonSprite, position);
    return buttonSprite;
}
