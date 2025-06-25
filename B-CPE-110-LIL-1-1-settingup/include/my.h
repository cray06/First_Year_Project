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
    #include <fcntl.h>
    #include <string.h>
    #include <unistd.h>
    #include <sys/stat.h>

struct map_size {
    int x;
    int y;
};

int str_to_number(const char *str);
int settingup(const char *filepath);
int generate_and_solve(int size, const char *pattern);
int size_null(int size);
int error_handling(char *buffer, struct map_size *size, int nb_lines);
void find_largest_square(char **map, struct map_size *size,
    const char *pattern);
int try_find_square(char **map, struct map_size *size, int square_size);
int check_column(char **map, int i, struct map_size *size, int square_size);
int check_square_row(char **map, int y, int x, int size);
int check_square_cell(char **map, int y, int x, int size);
int get_size(const char *filepath, struct map_size *size);
char **read_map(const char *filepath, struct map_size *size);
void fill_square(char **map, int y, int x, int size);
void print_and_free_map(char **map, int rows, struct map_size *size);
void fill_map(char **map, char *buffer, int start, struct map_size *size);
void fill_row(char *row, int size, const char *pattern, int row_index);
char **generate_map(int size, const char *pattern);
int my_getnbr(char const *str);
void my_putchar(char c);
int my_putstr(char const *str);
char *my_strncpy(char *dest, char const *src, int n);
int my_strlen(char const *str);
char *my_strchr(const char *s, int c);

#endif
