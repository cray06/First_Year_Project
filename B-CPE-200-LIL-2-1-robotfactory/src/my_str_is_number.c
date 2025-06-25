/*
** EPITECH PROJECT, 2025
** my_str_is_number
** File description:
** my_str_is_number
*/

int is_number(char c)
{
    if (c < 48 || c > 57)
        return 0;
    return 1;
}

int my_str_is_number(char *str)
{
    for (int i = 0; str[i] != '\0'; i++){
        if (!is_number(str[i]) && (i == 0 && str[i] != '-'))
            return 0;
    }
    return 1;
}
