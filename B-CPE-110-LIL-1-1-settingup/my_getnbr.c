/*
** EPITECH PROJECT, 2024
** my_getnbr
** File description:
** my_getnbr
*/

void multiplication(int nb_min, int number)
{
    if (nb_min % 2 != 0) {
        number *= (-1);
    }
}

int my_getnbr(char const *str)
{
    int number = 0;
    int i = 0;
    int nb_min = 1;

    while (str[i] == '+' || str[i] == '-') {
        if (str[i] == '-'){
            nb_min *= -1;
        }
        i++;
    }
    while (str[i] <= 57 && str[i] >= 48){
        number = number * 10;
        number = number + (str[i] - 48);
        i++;
    }
    return number * nb_min;
}
