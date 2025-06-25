/*
** EPITECH PROJECT, 2024
** my_getnbr
** File description:
** my_getnbr
*/

int my_getnbr(char const *str)
{
    int number = 0;
    int i = 0;
    int sign = 1;

    while (str[i] == '+' || str[i] == '-') {
        if (str[i] == '-') {
            sign *= -1;
        }
        i++;
    }
    while (str[i] >= '0' && str[i] <= '9') {
        number = number * 10 + (str[i] - '0');
        i++;
    }
    return number * sign;
}
