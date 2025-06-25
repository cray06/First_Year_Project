/*
** EPITECH PROJECT, 2024
** parse.c
** File description:
** Parsing
*/

#include "include/my.h"

plane_parsing_t *parsing_plane(plane_parsing_t **list_plane,
    char *buffer, int a)
{
    plane_parsing_t *plane = malloc(sizeof(plane_parsing_t));
    char **word_array = my_str_to_word_array(buffer);

    if (plane == NULL || !validate_plane_args(word_array)) {
        free(plane);
        return NULL;
    }
    plane->x_start = my_getnbr(word_array[1]);
    plane->y_start = my_getnbr(word_array[2]);
    plane->x_end = my_getnbr(word_array[3]);
    plane->y_end = my_getnbr(word_array[4]);
    plane->plane_speed = my_getnbr(word_array[5]);
    plane->delay = my_getnbr(word_array[6]);
    plane->removed = false;
    list_plane[a] = plane;
    free(word_array);
    return plane;
}

tower_parsing_t *parsing_tower(tower_parsing_t **list_tower,
    char *buffer, int a)
{
    tower_parsing_t *tower = malloc(sizeof(tower_parsing_t));
    char **word_array = my_str_to_word_array(buffer);

    if (tower == NULL)
        return NULL;
    for (int i = 1; i <= 3; i++) {
        if (word_array[i] == NULL || my_is_all_digit(word_array[i]) == false) {
            free(tower);
            return NULL;
        }
    }
    tower->x_pos = my_getnbr(word_array[1]);
    tower->y_pos = my_getnbr(word_array[2]);
    tower->radius = my_getnbr(word_array[3]);
    list_tower[a] = tower;
    free(word_array);
    return tower;
}

int parse_info_plane(const char *path, Game_t *game,
    plane_parsing_t **plane_list)
{
    FILE *fp = fopen(path, "r");
    char *buffer = NULL;
    size_t len = 0;
    ssize_t read = 0;

    if (fp == NULL)
        return 84;
    read = getline(&buffer, &len, fp);
    for (int a = 0; read != -1;) {
        if (buffer[0] != 'A' && buffer[0] != 'T')
            return 84;
        if (buffer[0] == 'A' && parsing_plane(plane_list, buffer, a) == NULL)
            return 84;
        if (buffer[0] == 'A')
            a++;
        read = getline(&buffer, &len, fp);
    }
    game->plane = plane_list;
    free(buffer);
    return 0;
}

int parse_info_tower(const char *path, Game_t *game,
    tower_parsing_t **tower_list)
{
    FILE *fp = fopen(path, "r");
    char *buffer = NULL;
    size_t len = 0;
    ssize_t read = 0;

    if (fp == NULL)
        return 84;
    read = getline(&buffer, &len, fp);
    for (int a = 0; read != -1;) {
        if (buffer[0] != 'A' && buffer[0] != 'T')
            return 84;
        if (buffer[0] == 'T' && parsing_tower(tower_list, buffer, a) == NULL)
            return 84;
        if (buffer[0] == 'T')
            a++;
        read = getline(&buffer, &len, fp);
    }
    game->tower = tower_list;
    free(buffer);
    return 0;
}
