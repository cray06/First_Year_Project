/*
** EPITECH PROJECT, 2025
** hash.c
** File description:
** hash.c
*/

#include "include/my.h"

int hash(char *key, int len)
{
    int crypted_hash = 0;
    int calc = 0;

    if (len <= 0 || key == NULL)
        return 84;
    for (int i = 0; key[i] != '\0'; i++) {
        calc = ((key[i] * key[i]) % len) * key[i];
        crypted_hash += calc;
        calc = 0;
    }
    if (crypted_hash > 2100000000) {
        crypted_hash *= -1;
        crypted_hash /= 4;
    } else
        crypted_hash /= 2;
    return crypted_hash;
}
