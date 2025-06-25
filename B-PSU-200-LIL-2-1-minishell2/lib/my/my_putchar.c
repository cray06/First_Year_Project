/*
** EPITECH PROJECT, 2024
** my_putchar.c
** File description:
** my_putchar.c
*/

#include "lib.h"

void my_putchar(char c)
{
    write(1, &c, 1);
}
