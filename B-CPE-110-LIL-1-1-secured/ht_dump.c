/*
** EPITECH PROJECT, 2025
** ht_dump.c
** File description:
** ht_dump.c
*/

#include "include/my.h"

void print_reverse(hashvalue_t **temp, int count)
{
    for (int j = count - 1; j >= 0; j--) {
        my_putstr("> ");
        my_put_nbr(temp[j]->hash_key);
        my_putstr(" - ");
        my_putstr(temp[j]->hash_value);
        my_putchar('\n');
    }
}

void ht_dump(hashtable_t *ht)
{
    hashvalue_t *current = NULL;
    hashvalue_t **temp = malloc(sizeof(hashvalue_t));
    int count;

    if (ht == NULL)
        return;
    for (int i = 0; i < ht->len; i++) {
        current = ht->values[i];
        my_putstr("[");
        my_put_nbr(i);
        my_putstr("]:\n");
        count = 0;
        while (current != NULL) {
            temp[count] = current;
            count++;
            current = current->next;
        }
        print_reverse(temp, count);
    }
}
