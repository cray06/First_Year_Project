/*
** EPITECH PROJECT, 2024
** my_putchar
** File description:
** my_putchar function
*/

#include "../include/my.h"

void my_putchar(char c)
{
    write(1, &c, 1);
}
