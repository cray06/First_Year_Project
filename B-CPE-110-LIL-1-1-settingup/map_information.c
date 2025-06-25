/*
** EPITECH PROJECT, 2024
** map_information.c
** File description:
** map_information.c
*/

#include "include/my.h"

static char *read_file_content(const char *filepath)
{
    int fd;
    char *buffer;
    long long int bytes_read;
    struct stat st;

    stat(filepath, &st);
    buffer = malloc(st.st_size + 1);
    fd = open(filepath, O_RDONLY);
    if (fd == -1) {
        write(2, "Invalid File", 12);
        free(buffer);
        return 0;
    }
    bytes_read = read(fd, buffer, st.st_size);
    buffer[bytes_read] = '\0';
    close(fd);
    return buffer;
}

int get_size(const char *filepath, struct map_size *size)
{
    char *buffer = NULL;
    int i = 0;

    buffer = read_file_content(filepath);
    if (buffer == 0) {
        size->y = -1;
        return 84;
    }
    size->y = str_to_number(buffer);
    if (size->y * size->y >= 1100000 || size->y == -1)
        return 84;
    for (size->x = 0; buffer[size->x] != '\n'; size->x++);
    size->x++;
    i = error_handling(buffer, size, 0);
    free(buffer);
    return i;
}

static int open_file(const char *filepath, char **buffer, struct stat *st)
{
    int fd = open(filepath, O_RDONLY);

    if (fd == -1) {
        write(2, "Invalid File", 12);
        return 84;
    }
    stat(filepath, st);
    *buffer = malloc(st->st_size + 1);
    return fd;
}

static char **allocate_map(int y)
{
    return malloc(sizeof(char *) * (y + 1));
}

char **read_map(const char *filepath, struct map_size *size)
{
    int fd;
    int line_start = 0;
    char *buffer = NULL;
    long long int bytes_read;
    char **map;
    struct stat st;

    fd = open_file(filepath, &buffer, &st);
    if (fd == -1) {
        free(buffer);
        return NULL;
    }
    bytes_read = read(fd, buffer, st.st_size);
    buffer[bytes_read] = '\0';
    while (buffer[line_start] != '\n')
        line_start++;
    map = allocate_map(size->y);
    fill_map(map, buffer, line_start + 1, size);
    free(buffer);
    return map;
}
