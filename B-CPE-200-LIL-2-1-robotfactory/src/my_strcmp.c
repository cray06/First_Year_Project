/*
** EPITECH PROJECT, 2024
** my_strcmp.c
** File description:
** reproduce the behavior of the strcmp function
*/
#include <unistd.h>

int my_strcmp(char const *s1, char const *s2)
{
    int i = 0;

    if (s1 == NULL && s2 != NULL)
        return s2[i];
    if (s2 == NULL && s1 != NULL)
        return s1[i];
    while (s1 != NULL && s2 != NULL &&
        s1[i] == s2[i] && s1[i] != '\0' && s2[i] != '\0')
        i++;
    if (s1 == NULL && s2 == NULL)
        return 0;
    return s1[i] - s2[i];
}
