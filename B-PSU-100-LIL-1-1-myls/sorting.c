/*
** EPITECH PROJECT, 2024
** sorting.c
** File description:
** sorting output
*/

#include "include/my.h"

int my_strcasecmp(const char *s1, const char *s2)
{
    char c1;
    char c2;

    while (*s1 && *s2) {
        c1 = *s1;
        c2 = *s2;
        c1 = (c1 >= 'A' && c1 <= 'Z') ? c1 + 32 : c1;
        c2 = (c2 >= 'A' && c2 <= 'Z') ? c2 + 32 : c2;
        if (c1 != c2) {
            return c1 < c2 ? -1 : 1;
        }
        s1++;
        s2++;
    }
    if (*s1 == '\0' && *s2 == '\0')
        return 0;
    if (*s1 == '\0')
        return -1;
    return 1;
}

void my_swap_files(struct FileInfo *a, struct FileInfo *b)
{
    struct FileInfo temp = *a;

    *a = *b;
    *b = temp;
}

void sort_files(struct DirectoryContent *content, int count, char *flags)
{
    int reverse = reverse_list(flags);
    int last_index;
    int comparaison;
    int condition;

    for (int i = 0; i < count - 1; i++) {
        last_index = i;
        for (int j = i + 1; j < count; j++) {
            comparaison = my_strcasecmp(content->files[last_index].name,
                content->files[j].name);
            condition = reverse ? comparaison < 0 : comparaison > 0;
            last_index = condition ? j : last_index;
        }
        if (last_index != i) {
            my_swap_files(&content->files[i], &content->files[last_index]);
        }
    }
}

void sort_file_time(struct DirectoryContent *content, int count, char *flags)
{
    int reverse = time_sorting(flags);
    int last_index;
    time_t comparison;
    int condition;

    for (int i = 0; i < count - 1; i++) {
        last_index = i;
        for (int j = i + 1; j < count; j++) {
            comparison = content->files[last_index].mod_time_comp -
                content->files[j].mod_time_comp;
            condition = reverse ? comparison < 0 : comparison > 0;
            last_index = condition ? j : last_index;
        }
        if (last_index != i) {
            my_swap_files(&content->files[i], &content->files[last_index]);
        }
    }
}
