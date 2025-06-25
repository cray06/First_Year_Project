/*
** EPITECH PROJECT, 2024
** game.c
** File description:
** game.c
*/

#include "include/my.h"

void draw_plane(Game_t *game, int i)
{
    if (game->plane[i]->active && !game->plane[i]->removed) {
        if (game->show_sprites)
            sfRenderWindow_drawSprite(game->window,
                game->plane[i]->sprite, NULL);
        if (game->show_hitbox)
            sfRenderWindow_drawRectangleShape(game->window,
                game->plane[i]->rectangle, NULL);
    }
}

void draw_game(Game_t *game)
{
    sfRenderWindow_clear(game->window, sfBlack);
    sfRenderWindow_drawSprite(game->window, game->gameSprite, NULL);
    draw_towers(game);
    for (int i = 0; game->plane[i] != NULL; i++) {
        draw_plane(game, i);
    }
    sfRenderWindow_drawText(game->window, game->timer_text, NULL);
    sfRenderWindow_display(game->window);
}

void handle_game_events(Game_t *game)
{
    sfEvent event;

    while (sfRenderWindow_pollEvent(game->window, &event)) {
        if (event.type == sfEvtClosed) {
            sfRenderWindow_close(game->window);
        }
        if (event.type == sfEvtKeyPressed && event.key.code == sfKeyQ) {
            sfRenderWindow_close(game->window);
        }
        if (event.type == sfEvtKeyPressed && event.key.code == sfKeyL) {
            game->show_hitbox = !game->show_hitbox;
        }
        if (event.type == sfEvtKeyPressed && event.key.code == sfKeyS) {
            game->show_sprites = !game->show_sprites;
        }
    }
}

void game_loop(Game_t *game)
{
    sfTime time;
    char *timer_str = malloc(sizeof(char) * 10);

    if (timer_str == NULL)
        return;
    while (sfRenderWindow_isOpen(game->window)) {
        handle_game_events(game);
        activate_planes(game);
        update_planes(game);
        draw_towers(game);
        draw_game(game);
        time = sfClock_getElapsedTime(game->clock);
        game->seconds = time.microseconds / 1000000;
        int_to_str(game->seconds, timer_str);
        sfText_setString(game->timer_text, timer_str);
        sfRenderWindow_display(game->window);
        if (game->plane[0] == NULL) {
            sfRenderWindow_close(game->window);
        }
    }
}

int display_windows(Game_t *game)
{
    initialize_game(game);
    game_loop(game);
    destroy_all(game);
    return 0;
}
