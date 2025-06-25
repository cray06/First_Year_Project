/*
** EPITECH PROJECT, 2024
** duck.c
** File description:
** duck.c
*/

#include "include/my.h"

void update_ducks(Game_t *game)
{
    sfTime time = sfClock_getElapsedTime(game->clock);
    float seconds = time.microseconds / 1000000.0;

    if (seconds > 0.1) {
        for (int i = 0; i < 4; i++) {
            animate_duck(game->ducks[i], game->frame);
            move_duck(game->ducks[i], 1.0f * (game->score / 15) + 1, 0.0f);
        }
        game->frame = (game->frame + 1) % 3;
        sfClock_restart(game->clock);
    }
}

void check_duck_positions(Game_t *game)
{
    sfVector2f duckPosition;
    sfVector2f newPosition;
    bool reset_game;

    for (int i = 0; i < 4; i++) {
        duckPosition = sfSprite_getPosition(game->ducks[i]->sprite);
        if (duckPosition.x <= 1920)
            continue;
        game->hearts--;
        reset_game = (game->hearts == 0 && display_game_lost(game->window));
        if (reset_game) {
            game->score = 0;
            game->hearts = 3;
            initialize_ducks(game);
            initialize_hearts(game);
            return;
        }
        newPosition = (sfVector2f){0, rand() % 960};
        sfSprite_setPosition(game->ducks[i]->sprite, newPosition);
    }
}

void initialize_ducks(Game_t *game)
{
    sfVector2f position;

    for (int i = 0; i < 4; i++) {
        game->ducks[i] = create_duck("ressource/duck.png");
        position = (sfVector2f){0, rand() % 960};
        sfSprite_setPosition(game->ducks[i]->sprite, position);
    }
}
