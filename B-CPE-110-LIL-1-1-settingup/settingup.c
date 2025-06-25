/*
** EPITECH PROJECT, 2024
** settingup.c
** File description:
** settingup main file
*/

#include "include/my.h"

int str_to_number(const char *str)
{
    int number = 0;
    int i = 0;

    while (str[i] != 10) {
        if (str[i] < '0' || str[i] > '9')
            return -1;
        number = number * 10 + (str[i] - '0');
        i++;
    }
    return number;
}

static int is_valid_char(char c)
{
    if (c == '.' || c == 'o') {
        return 84;
    }
    return 0;
}

static int validate_map(char **map, int rows, int cols)
{
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++)
            return (is_valid_char(map[i][j]) - 1);
    }
    return 0;
}

static int validate_line_lengths(char **map, int rows)
{
    int length = my_strlen(map[0]);

    for (int i = 1; i < rows; i++) {
        if (my_strlen(map[i]) != length)
            return 84;
    }
    return 0;
}

static int validate_first_line(char **map)
{
    if (map == NULL || map[0] == NULL ||
        map[0][0] == '\0' || map[0][0] == '0') {
        write(2, "Invalid first line or empty map", 31);
        return 84;
    }
    return 0;
}

int settingup(const char *filepath)
{
    struct map_size size;
    char **map = NULL;

    get_size(filepath, &size);
    if (size.y == -1 || size.y == 0) {
        write(2, "Invalid y size", 14);
        return 84;
    }
    if (get_size(filepath, &size) == 84)
        return 84;
    map = read_map(filepath, &size);
    if (validate_first_line(map) == 84)
        return 84;
    if (validate_map(map, size.y, size.x) == 84)
        return 84;
    if (validate_line_lengths(map, size.y) == 84)
        return 84;
    find_largest_square(map, &size, NULL);
    print_and_free_map(map, size.y, &size);
    return 0;
}

int generate_and_solve(int size, const char *pattern)
{
    struct map_size map_size = {size, size};
    char **map = generate_map(size, pattern);

    for (int i = 0; i < my_strlen(pattern); i++)
        if (pattern[i] != 'o' && pattern[i] != '.') {
            write(2, "Pattern must only be o and .", 28);
            return 84;
        }
    find_largest_square(map, &map_size, pattern);
    print_and_free_map(map, size, &map_size);
    return 0;
}

int size_null(int size)
{
    if (size <= 0) {
        write(2, "Invalid size", 13);
        return 84;
    }
    return 0;
}

int main(int argc, char *argv[])
{
    int size;

    if (argc == 2) {
        return settingup(argv[1]);
    } else if (argv[2][0] != '\0' && argc == 3) {
        size = my_getnbr(argv[1]);
        size_null(size);
        generate_and_solve(size, argv[2]);
    } else {
        write(2, "Invalid number of args", 22);
        return 84;
    }
    return 0;
}
