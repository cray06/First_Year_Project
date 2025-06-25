/*
** EPITECH PROJECT, 2024
** my_getnbr.c
** File description:
** returns a number sent to the fonction as a string
*/

int my_getnbr(char const *str)
{
    int nb = 0;
    int i = 0;
    int nb_minus = 0;

    while (str[i] == '+' || str[i] == '-'){
        if (str[i] == '-'){
            nb_minus++;
        }
        i++;
    }
    while (str[i] <= 57 && str[i] >= 48 && str[i] != '\0'){
        nb = nb * 10;
        nb = nb + (str[i] - 48);
        i++;
    }
    if (nb_minus % 2 != 0) {
        nb *= (-1);
    }
    return nb;
}
