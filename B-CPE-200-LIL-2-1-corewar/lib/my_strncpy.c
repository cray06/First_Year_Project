/*
** EPITECH PROJECT, 2024
** my_strncpy.c
** File description:
** copy n characters from a string into another
*/

char *my_strncpy(char *dest, char *src, int n)
{
    int taille = 0;
    int i = 0;

    while (src[taille] != '\0')
        taille++;
    for (; i < n; i++)
        dest[i] = src[i];
    while (i < n){
        dest[i] = '\0';
        i++;
    }
    return dest;
}
