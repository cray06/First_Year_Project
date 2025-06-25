/*
** EPITECH PROJECT, 2024
** nbr_element.c
** File description:
** nbr_element.c
*/

#include "include/my.h"

int nb_plane(const char *path, Game_t *game)
{
    FILE *fp = fopen(path, "r");
    char *buffer = NULL;
    size_t len = 0;
    ssize_t read = 0;
    int nbr_plane = 0;

    if (fp == NULL)
        return 84;
    read = getline(&buffer, &len, fp);
    while (read != -1) {
        if (buffer[0] == 'A')
            nbr_plane++;
        read = getline(&buffer, &len, fp);
    }
    game->nb_plane = nbr_plane;
    return game->nb_plane;
}

int nb_tower(const char *path, Game_t *game)
{
    FILE *fp = fopen(path, "r");
    char *buffer = NULL;
    size_t len = 0;
    ssize_t read = 0;
    int nbr_tower = 0;

    if (fp == NULL)
        return 84;
    read = getline(&buffer, &len, fp);
    while (read != -1) {
        if (buffer[0] == 'T')
            nbr_tower++;
        read = getline(&buffer, &len, fp);
    }
    game->nb_tower = nbr_tower;
    return game->nb_tower;
}
