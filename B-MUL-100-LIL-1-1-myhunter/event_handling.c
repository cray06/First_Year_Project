/*
** EPITECH PROJECT, 2024
** event_handling.c
** File description:
** event_handling.c
*/

#include "include/my.h"

void handle_game_events(Game_t *game)
{
    sfEvent event;
    sfVector2i mousePos;

    while (sfRenderWindow_pollEvent(game->window, &event)) {
        if (event.type == sfEvtClosed) {
            sfRenderWindow_close(game->window);
        }
        if (event.type == sfEvtMouseButtonPressed) {
            mousePos = sfMouse_getPositionRenderWindow(game->window);
            check_duck_click(game, mousePos);
        }
    }
}

bool handle_lost_events(sfRenderWindow* window, sfSprite* retryButtonSprite,
    sfSprite* exitButtonSprite)
{
    sfEvent event;

    while (sfRenderWindow_pollEvent(window, &event)) {
        if (event.type == sfEvtClosed) {
            sfRenderWindow_close(window);
        }
        if (event.type == sfEvtMouseButtonPressed &&
            is_button_pressed(window, retryButtonSprite)) {
            return true;
        }
        if (event.type == sfEvtMouseButtonPressed &&
            is_button_pressed(window, exitButtonSprite)) {
            sfRenderWindow_close(window);
        }
    }
    return false;
}

void handle_window_close_event(sfRenderWindow* window, sfEvent event)
{
    if (event.type == sfEvtClosed) {
        sfRenderWindow_close(window);
    }
}

void handle_mouse_button_pressed(sfRenderWindow* window,
    sfSprite* buttonSprite, sfEvent event)
{
    sfVector2i mousePos;
    sfFloatRect bounds;

    if (event.mouseButton.button == sfMouseLeft) {
        mousePos = sfMouse_getPositionRenderWindow(window);
        bounds = sfSprite_getGlobalBounds(buttonSprite);
        if (sfFloatRect_contains(&bounds, mousePos.x, mousePos.y)) {
            display_game(&(Game_t){.window = window});
        }
    }
}

void handle_exit_button_pressed(sfRenderWindow* window,
    sfSprite* buttonSprite, sfEvent event)
{
    sfVector2i mousePos;
    sfFloatRect bounds;

    if (event.mouseButton.button == sfMouseLeft) {
        mousePos = sfMouse_getPositionRenderWindow(window);
        bounds = sfSprite_getGlobalBounds(buttonSprite);
        if (sfFloatRect_contains(&bounds, mousePos.x, mousePos.y)) {
            sfRenderWindow_close(window);
        }
    }
}
