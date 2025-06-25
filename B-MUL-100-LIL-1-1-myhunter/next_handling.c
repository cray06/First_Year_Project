/*
** EPITECH PROJECT, 2024
** next_handling.c
** File description:
** next_handling.c
*/

#include "include/my.h"

void handle_start_button(Menu_t *menu)
{
    sfEvent event;

    while (sfRenderWindow_pollEvent(menu->window, &event)) {
        handle_window_close_event(menu->window, event);
        if (event.type == sfEvtMouseButtonPressed) {
            handle_mouse_button_pressed(menu->window,
                menu->startButtonSprite, event);
            handle_exit_button_pressed(menu->window,
                menu->exitButtonSprite, event);
        }
    }
}

void handle_events(sfRenderWindow *window, sfSprite *cursorSprite)
{
    sfEvent event;
    sfVector2i mousePos;
    sfVector2f cursorPos;
    sfFloatRect spriteBounds;

    mousePos = sfMouse_getPositionRenderWindow(window);
    spriteBounds = sfSprite_getGlobalBounds(cursorSprite);
    cursorPos.x = mousePos.x - spriteBounds.width / 2;
    cursorPos.y = mousePos.y - spriteBounds.height / 2;
    sfSprite_setPosition(cursorSprite, cursorPos);
    sfSprite_setScale(cursorSprite, (sfVector2f){0.4f, 0.4f});
    while (sfRenderWindow_pollEvent(window, &event))
        if (event.type == sfEvtClosed)
            sfRenderWindow_close(window);
}
