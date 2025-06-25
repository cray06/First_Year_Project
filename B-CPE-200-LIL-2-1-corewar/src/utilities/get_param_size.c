/*
** EPITECH PROJECT, 2025
** get_param_size.c
** File description:
** get_param_size.c
*/

#include "my.h"

int get_param_size(args_type_t *type, int is_index)
{
    int size = 0;

    for (int i = 0; i < 3; i++){
        if (type[i] == T_REG)
            size += REG_SIZE;
        if (type[i] == T_DIR && !is_index)
            size += DIR_SIZE;
        if (type[i] == T_DIR && is_index)
            size += IND_SIZE;
        if (type[i] == T_IND)
            size += IND_SIZE;
    }
    return size;
}
