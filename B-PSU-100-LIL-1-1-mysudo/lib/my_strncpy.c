/*
** EPITECH PROJECT, 2024
** DAY06
** File description:
** str n copy
*/

char *my_strncpy(char *dest, char const *src, int n)
{
    for (int i = 0; i < n; i++)
        dest[i] = src[i];
    return dest;
}
