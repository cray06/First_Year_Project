/*
** EPITECH PROJECT, 2025
** binaire
** File description:
** binaire
*/
#include "asm.h"

int binary_to_decimal(char *binaire)
{
    int result = 0;

    for (int i = my_strlen(binaire) - 1; i >= 0; i--){
        if (binaire[i] == '1')
            result += my_compute_power_rec(2, (my_strlen(binaire) - 1) - i);
    }
    free(binaire);
    return result;
}
