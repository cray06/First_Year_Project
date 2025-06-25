/*
** EPITECH PROJECT, 2024
** map_parsing.c
** File description:
** map_parsing.c
*/

#include "include/my.h"

static int count_char(const char *pattern, char c)
{
    int char_number = 0;

    for (int i = 0; i < my_strlen(pattern); i++)
        if (pattern[i] == c)
            char_number++;
    return char_number;
}

void find_largest_square(char **map, struct map_size *size,
    const char *pattern)
{
    int max_size = (size->x < size->y) ? size->x : size->y;

    max_size = pattern != NULL && my_strchr(pattern, 'o') ?
        count_char(pattern, '.') : max_size;
    for (int square_size = max_size; square_size > 0; square_size--) {
        if (try_find_square(map, size, square_size))
            return;
    }
}

int try_find_square(char **map, struct map_size *size, int square_size)
{
    for (int i = 0; i <= size->y - square_size; i++) {
        if (check_column(map, i, size, square_size))
            return 1;
    }
    return 0;
}

int check_column(char **map, int i, struct map_size *size, int square_size)
{
    for (int j = 0; j <= size->x - square_size; j++) {
        if (check_square_row(map, i, j, square_size) == 1) {
            fill_square(map, i, j, square_size);
            return 1;
        }
    }
    return 0;
}

int check_square_row(char **map, int y, int x, int size)
{
    for (int i = y; i < y + size; i++) {
        if (check_square_cell(map, i, x, size) == 0)
            return 0;
    }
    return 1;
}

int check_square_cell(char **map, int y, int x, int size)
{
    for (int j = x; j < x + size; j++) {
        if (map[y][j] == 'o')
            return 0;
    }
    return 1;
}
