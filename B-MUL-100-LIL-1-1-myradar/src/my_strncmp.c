/*
** EPITECH PROJECT, 2024
** my_strncmp.c
** File description:
** my_strncmp
*/

int my_strncmp(const char *s1, const char *s2, int n)
{
    if (n == 0) {
        return 0;
    }
    while (n > 0 && (*s1 != '\0' || *s2 != '\0')) {
        if (*s1 != *s2) {
            return *s1 - *s2;
        }
        s1++;
        s2++;
        n--;
    }
    return 0;
}
