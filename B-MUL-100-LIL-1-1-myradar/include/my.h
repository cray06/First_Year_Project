/*
** EPITECH PROJECT, 2025
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
    #include <math.h>

typedef struct {
    int x_start;
    int y_start;
    int x_end;
    int y_end;
    int plane_speed;
    int delay;
    int x_current;
    int y_current;
    bool removed;
    bool active;
    sfSprite *sprite;
    sfRectangleShape *rectangle;
    sfClock *clock;
} plane_parsing_t;

typedef struct tower_parsing_s {
    int x_pos;
    int y_pos;
    int radius;
    sfCircleShape *circle;
    sfSprite *sprite;
} tower_parsing_t;

typedef struct {
    float left;
    float top;
    float width;
    float height;
} Rectangleshape_t;

typedef struct quad_tree_t {
    Rectangleshape_t border;
    int capacity;
    plane_parsing_t **planes;
    int count;
    struct quad_tree_t *topleft;
    struct quad_tree_t *topright;
    struct quad_tree_t *bottomleft;
    struct quad_tree_t *bottomright;
} quad_tree_t;

typedef struct {
    plane_parsing_t **plane;
    tower_parsing_t **tower;
    sfRenderWindow *window;
    sfSprite *gameSprite;
    int nb_plane;
    int nb_tower;
    int destroyed_plane;
    bool show_hitbox;
    bool show_sprites;
    int seconds;
    sfTexture *texture;
    sfClock *clock;
    sfText *timer_text;
    sfFont *font;
} Game_t;

int my_strlen(char const *str);
int my_putstr(char const *str);
int my_put_nbr(int nb);
void int_to_str(int n, char *str);
void initialize_game(Game_t *game);
int error_handling(int argc, char *argv[], char **envp);
int init_planes_and_towers(const char *path, Game_t *game);
void check_plane_collisions(Game_t *game, quad_tree_t *qt);
int find_plane_index(Game_t *game, plane_parsing_t *plane);
void my_putchar(char c);
char *my_strcpy(char *dest, char const *src);
int my_strncmp(const char *s1, const char *s2, int n);
int verif_env(char **envp);
char **my_str_to_word_array(char const *str);
int my_getnbr(char const *str);
bool my_is_all_digit(char *str);
bool my_is_digit(char c);
int parse_info_tower(const char *path, Game_t *game,
    tower_parsing_t **tower_list);
int parse_info_plane(const char *path, Game_t *game,
    plane_parsing_t **plane_list);
int nb_plane(const char *path, Game_t *game);
int nb_tower(const char *path, Game_t *game);
void destroy_all(Game_t *game);
void print_h_option(void);
void create_tower(Game_t *game);
void draw_towers(Game_t *game);
int display_windows(Game_t *game);
void update_plane_position(plane_parsing_t *plane,
    float dx, float dy, float angle);
bool has_plane_reached_destination(plane_parsing_t *plane,
    tower_parsing_t **towers, int num_towers);
void update_planes(Game_t *game);
void remove_plane(Game_t *game, int index);
void initialize_planes(Game_t *game);
void timer(Game_t *game);
quad_tree_t *create_quadtree(Rectangleshape_t boundary, int capacity);
bool insert(quad_tree_t *qt, plane_parsing_t *plane);
void search(quad_tree_t *qt, Rectangleshape_t range,
    plane_parsing_t **found, int *count);
bool check_collision(plane_parsing_t *plane1,
    plane_parsing_t *plane2);
bool rectangles_intersect(Rectangleshape_t rect1, Rectangleshape_t rect2);
bool is_in_border(Rectangleshape_t boundary, plane_parsing_t *plane);
void free_quadtree(quad_tree_t *qt);
bool is_in_control_area(plane_parsing_t *plane,
    tower_parsing_t **towers, int num_towers);
void activate_planes(Game_t *game);
bool validate_plane_args(char **word_array);
bool should_remove_planes(plane_parsing_t *plane1,
    plane_parsing_t *plane2,
    Game_t *game);
void remove_plane_pair(Game_t *game, int index1, int index2);
void process_collision(Game_t *game, plane_parsing_t *current_plane,
    plane_parsing_t *found_plane);
void handle_plane_collision(Game_t *game,
    plane_parsing_t *plane1, plane_parsing_t *plane2);
void update_active_plane(Game_t *game, int i, quad_tree_t *qt);
void remove_marked_planes(Game_t *game);

#endif
