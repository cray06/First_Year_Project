/*
** EPITECH PROJECT, 2024
** main_menu.c
** File description:
** main_menu.c
*/

#include "include/my.h"

sfSprite *create_cursor(const char *filepath)
{
    sfTexture *texture = sfTexture_createFromFile(filepath, NULL);
    sfSprite *cursorSprite = sfSprite_create();

    sfSprite_setTexture(cursorSprite, texture, sfTrue);
    return cursorSprite;
}

void draw_menu(Menu_t *menu)
{
    sfRenderWindow_clear(menu->window, sfBlack);
    sfRenderWindow_drawSprite(menu->window, menu->menuSprite, NULL);
    sfRenderWindow_drawSprite(menu->window, menu->logoSprite, NULL);
    sfRenderWindow_drawSprite(menu->window, menu->startButtonSprite, NULL);
    sfRenderWindow_drawSprite(menu->window, menu->exitButtonSprite, NULL);
    sfRenderWindow_display(menu->window);
}

void draw_game(Game_t *game, sfSprite *cursorSprite)
{
    sfText* scoreDisplay = sfText_create();
    sfFont* font = sfFont_createFromFile("ressource/font.ttf");
    char scoreText[20];

    sfRenderWindow_clear(game->window, sfBlack);
    sfRenderWindow_drawSprite(game->window, game->gameSprite, NULL);
    for (int i = 0; i < 4; i++)
        sfRenderWindow_drawSprite(game->window, game->ducks[i]->sprite, NULL);
    for (int i = 0; i < game->hearts; i++)
        sfRenderWindow_drawSprite(game->window, game->heartSprites[i], NULL);
    get_score_text(game->score, scoreText);
    sfText_setString(scoreDisplay, scoreText);
    sfText_setFont(scoreDisplay, font);
    sfText_setCharacterSize(scoreDisplay, 24);
    sfText_setPosition(scoreDisplay, (sfVector2f){1750, 25});
    sfRenderWindow_drawText(game->window, scoreDisplay, NULL);
    sfRenderWindow_drawSprite(game->window, cursorSprite, NULL);
    sfRenderWindow_display(game->window);
    sfText_destroy(scoreDisplay);
    sfFont_destroy(font);
}

int display_windows(void)
{
    Menu_t menu;
    sfTexture *menuTexture =
        sfTexture_createFromFile("ressource/gradient.png", NULL);
    sfSprite *cursorSprite = create_cursor("ressource/cursor.png");

    menu.window = sfRenderWindow_create((sfVideoMode){1920, 1080, 32},
        "My Hunter", sfResize | sfClose, NULL);
    menu.menuSprite = sfSprite_create();
    menu.startButtonSprite = create_start_button("ressource/start_button.png");
    menu.exitButtonSprite = create_exit_button("ressource/exit_button.png");
    menu.logoSprite = create_logo("ressource/logo.png");
    sfSprite_setTexture(menu.menuSprite, menuTexture, sfTrue);
    while (sfRenderWindow_isOpen(menu.window)) {
        handle_start_button(&menu);
        draw_menu(&menu);
    }
    cleanup_menu(&menu, menuTexture);
    sfSprite_destroy(cursorSprite);
    return EXIT_SUCCESS;
}
