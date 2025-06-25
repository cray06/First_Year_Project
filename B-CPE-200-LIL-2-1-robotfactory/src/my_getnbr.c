/*
** EPITECH PROJECT, 2024
** my_getnbr
** File description:
** my_getnbr
*/

#include "asm.h"

void multipli(int nb_minimal, int number)
{
    if (nb_minimal % 2 != 0) {
        number *= (-1);
    }
}

int my_getnbr(char const *str)
{
    int number = 0;
    int i = 0;
    int nb_minimal = 1;

    while (str[i] == '+' || str[i] == '-') {
        if (str[i] == '-'){
            nb_minimal *= -1;
        }
        i++;
    }
    while (str[i] <= 57 && str[i] >= 48){
        number = number * 10;
        number = number + (str[i] - 48);
        i++;
    }
    return number * nb_minimal;
}
