/*
** EPITECH PROJECT, 2024
** lost_screen.c
** File description:
** lost_screen.c
*/

#include "include/my.h"

void setup_lost_screen(sfSprite **lostSprite, sfTexture **lostTexture,
    sfSprite **retryButton, sfSprite **exitButton)
{
    *lostTexture = sfTexture_createFromFile("ressource/Game_lost.png", NULL);
    *lostSprite = sfSprite_create();
    *retryButton = create_retry_button("ressource/retry_button.png");
    *exitButton = create_final_exit("ressource/exit_button.png");
    sfSprite_setTexture(*lostSprite, *lostTexture, sfTrue);
}

void cleanup_lost_screen(sfSprite *lostSprite, sfTexture *lostTexture,
    sfSprite *retryButton, sfSprite *exitButton)
{
    sfSprite_destroy(lostSprite);
    sfTexture_destroy(lostTexture);
    sfSprite_destroy(retryButton);
    sfSprite_destroy(exitButton);
}

bool display_game_lost(sfRenderWindow *window)
{
    sfSprite *lostSprite;
    sfSprite *retryButton;
    sfSprite *exitButton;
    sfTexture *lostTexture;
    bool returnToMenu = false;

    setup_lost_screen(&lostSprite, &lostTexture, &retryButton, &exitButton);
    while (sfRenderWindow_isOpen(window) && !returnToMenu) {
        if (handle_lost_events(window, retryButton, exitButton)) {
            returnToMenu = true;
        }
        sfRenderWindow_setMouseCursorVisible(window, sfTrue);
        sfRenderWindow_clear(window, sfBlack);
        sfRenderWindow_drawSprite(window, lostSprite, NULL);
        sfRenderWindow_drawSprite(window, retryButton, NULL);
        sfRenderWindow_drawSprite(window, exitButton, NULL);
        sfRenderWindow_display(window);
    }
    cleanup_lost_screen(lostSprite, lostTexture, retryButton, exitButton);
    return returnToMenu;
}
