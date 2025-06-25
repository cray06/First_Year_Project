/*
** EPITECH PROJECT, 2024
** map_route.c
** File description:
** map_route.c
*/

#include "include/my.h"

char **generate_map(int size, const char *pattern)
{
    char **map;

    map = malloc(sizeof(char *) * (size + 1));
    for (int i = 0; i < size; i++) {
        map[i] = malloc(sizeof(char) * (size + 1));
        fill_row(map[i], size, pattern, i);
    }
    return map;
}

void fill_row(char *row, int size, const char *pattern, int row_index)
{
    int pattern_length = my_strlen(pattern);
    int pattern_index = size * row_index;

    for (int j = 0; j < size; j++) {
        row[j] = pattern[pattern_index % pattern_length];
        pattern_index++;
    }
    row[size] = '\0';
}

void fill_map(char **map, char *buffer, int start, struct map_size *size)
{
    for (int i = 0; i < size->y; i++) {
        map[i] = malloc(sizeof(char) * (size->x + 1));
        my_strncpy(map[i], buffer + start + (i * (size->x + 1)), size->x);
        map[i][size->x] = '\0';
    }
    map[size->y] = NULL;
}

void print_and_free_map(char **map, int rows, struct map_size *size)
{
    for (int i = 0; i < rows; i++) {
        write(1, map[i], size->x);
        my_putchar('\n');
        free(map[i]);
    }
    free(map);
}

void fill_square(char **map, int y, int x, int size)
{
    for (int i = y; i < y + size; i++) {
        for (int j = x; j < x + size; j++) {
            map[i][j] = 'x';
        }
    }
}
