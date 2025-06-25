/*
** EPITECH PROJECT, 2025
** value_parsing.c
** File description:
** value_parsing.c
*/

#include "asm.h"
#include "op.h"

int get_register(char *line)
{
    if (line == NULL)
        return 0;
    for (int i = 0; line[i] != '\0'; i++)
        if (line[0] == 'r')
            return my_getnbr(line + 1);
    return 84;
}

int get_direct_value(char *line)
{
    if (line == NULL)
        return 0;
    for (int i = 0; line[i] != '\0'; i++)
        if (line[0] == DIRECT_CHAR && my_isnumber(line + 1))
            return my_getnbr(line + 1);
    return 84;
}

int get_indirect_value(char *line)
{
    if (line == NULL)
        return 0;
    for (int i = 0; line[i] != '\0'; i++)
        if (my_isnumber(line))
            return my_getnbr(line);
    return 84;
}

char *get_label_value(char *line)
{
    if (line == NULL)
        return NULL;
    if (!my_strncmp(line, "%:", 2))
        return line + 2;
    return NULL;
}
