/*
** EPITECH PROJECT, 2024
** game_manage.c
** File description:
** game_manage.c
*/

#include "include/my.h"

void init_game_elements(Game_t *game)
{
    sfTexture *gameTexture;

    game->clock = sfClock_create();
    game->frame = 0;
    game->score = 0;
    game->hearts = 3;
    initialize_ducks(game);
    initialize_hearts(game);
    gameTexture = sfTexture_createFromFile("ressource/game_bg.png", NULL);
    game->gameSprite = sfSprite_create();
    sfSprite_setTexture(game->gameSprite, gameTexture, sfTrue);
}

void game_loop(Game_t *game, sfSprite *cursorSprite)
{
    while (sfRenderWindow_isOpen(game->window)) {
        sfRenderWindow_setFramerateLimit(game->window, 60);
        sfRenderWindow_setMouseCursorVisible(game->window, sfFalse);
        handle_game_events(game);
        update_ducks(game);
        check_duck_positions(game);
        handle_events(game->window, cursorSprite);
        draw_game(game, cursorSprite);
    }
}

void display_game(Game_t *game)
{
    sfTexture *gameTexture =
        sfTexture_createFromFile("ressource/game_bg.png", NULL);
    sfSprite *cursorSprite = create_cursor("ressource/cursor.png");

    init_game_elements(game);
    game_loop(game, cursorSprite);
    cleanup_game(game, gameTexture);
    sfSprite_destroy(cursorSprite);
}
