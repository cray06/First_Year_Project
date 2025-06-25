/*
** EPITECH PROJECT, 2025
** error_handling.c
** File description:
** error_handling.c
*/

#include "include/my.h"

int err_creation_ht(hashtable_t *ht, int (*hash)(char *, int), int len)
{
    if (ht == NULL)
        return 84;
    if (hash == NULL)
        return 84;
    if (len <= 0 || len > 214783647)
        return 84;
    return 0;
}
