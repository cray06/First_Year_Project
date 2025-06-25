/*
** EPITECH PROJECT, 2024
** error_handling.c
** File description:
** error_handling.c
*/

#include "include/my.h"

int error_handling(char *buffer, struct map_size *size, int nb_lines)
{
    int len_line = size->x;
    int i = size->x;

    for (; buffer[len_line] != '\n' && buffer[len_line] != '\0'; len_line++);
    size->x = len_line - size->x;
    for (len_line = 0; buffer[i] != '\0'; i++) {
        if (buffer[i] == '\n' && size->x != len_line) {
            write(2, "Lines are not equal", 19);
            return 84;
        }
        if (buffer[i] == '\n' && size->x == len_line) {
            len_line = 0;
            nb_lines++;
        } else
            len_line++;
    }
    if (nb_lines != size->y)
        write(2, "Invalid number of lines", 23);
    return 0;
}
