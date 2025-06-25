/*
** EPITECH PROJECT, 2024
** my.h
** File description:
** my.h
*/

#ifndef MY_H
    #define MY_H

    #include <stdbool.h>
    #include <stdlib.h>
    #include <stddef.h>
    #include <stdio.h>
    #include <stdarg.h>
    #include <string.h>
    #include <unistd.h>
    #include <SFML/Graphics.h>
    #include <SFML/System.h>
    #include <SFML/Window.h>
    #include <time.h>
    #include <fcntl.h>

typedef struct {
    sfSprite* sprite;
    float speed;
} duck_t;

typedef struct {
    sfRenderWindow* window;
    sfSprite* menuSprite;
    sfSprite* startButtonSprite;
    sfSprite* exitButtonSprite;
    sfSprite* logoSprite;
    sfCursor *cursor;
} Menu_t;

typedef struct {
    sfRenderWindow* window;
    sfSprite* gameSprite;
    duck_t *ducks[4];
    sfSprite* heartSprites[3];
    int hearts;
    int score;
    int frame;
    sfClock* clock;
} Game_t;

int my_strlen(char const *str);
void handle_events(sfRenderWindow *window, sfSprite *cursorSprite);
void draw_menu(Menu_t *menu);
int display_windows(void);
sfSprite *create_start_button(const char *filepath);
sfSprite *create_exit_button(const char *filepath);
sfSprite *create_logo(const char *filepath);
void handle_start_button(Menu_t *menu);
duck_t *create_duck(const char *filepath);
void animate_duck(duck_t *duck, int frame);
void move_duck(duck_t *duck, float offsetX, float offsetY);
void destroy_duck(duck_t *duck);
sfSprite *create_heart(const char *filepath);
bool display_game_lost(sfRenderWindow* window);
void display_game(Game_t *game);
void handle_game_events(Game_t *game);
void update_ducks(Game_t *game);
void check_duck_positions(Game_t *game);
void draw_game(Game_t *game, sfSprite *cursorSprite);
void initialize_ducks(Game_t *game);
void initialize_hearts(Game_t *game);
void cleanup_menu(Menu_t *menu, sfTexture *menuTexture);
bool handle_lost_events(sfRenderWindow* window,
    sfSprite* retryButtonSprite, sfSprite* exitButtonSprite);
bool is_button_pressed(sfRenderWindow* window, sfSprite* buttonSprite);
void handle_window_close_event(sfRenderWindow* window, sfEvent event);
void handle_mouse_button_pressed(sfRenderWindow* window,
    sfSprite* buttonSprite, sfEvent event);
void handle_exit_button_pressed(sfRenderWindow* window,
    sfSprite* buttonSprite, sfEvent event);
void get_score_text(int score, char *scoreText);
sfSprite *create_retry_button(const char *filepath);
void cleanup_game(Game_t *game, sfTexture *gameTexture);
void check_duck_click(Game_t *game, sfVector2i mousePos);
sfSprite *create_final_exit(const char *filepath);
sfSprite *create_cursor(const char *filepath);
int my_putstr(char const *str);
int my_put_nbr(int nb);
void my_putchar(char c);
char *my_strcpy(char *dest, char const *src);
int my_strncmp(const char *s1, const char *s2, int n);
int verif_env(char **envp);

#endif
