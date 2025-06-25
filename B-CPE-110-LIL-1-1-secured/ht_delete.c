/*
** EPITECH PROJECT, 2025
** ht_delete.c
** File description:
** ht_delete.c
*/

#include "include/my.h"

int delete_ht_value(hashtable_t *ht, hashvalue_t *current,
    hashvalue_t *prev, int i)
{
    if (ht == NULL || current == NULL)
        return 84;
    if (prev == NULL)
        ht->values[i] = current->next;
    else
        prev->next = current->next;
    free(current->word);
    free(current->hash_value);
    free(current);
    return 0;
}

int ht_delete(hashtable_t *ht, char *key)
{
    int hashed_key = 0;
    int i = 0;
    hashvalue_t *current = NULL;
    hashvalue_t *prev = NULL;

    if (ht == NULL || key == NULL || ht->len <= 0)
        return 84;
    hashed_key = ht->hash(key, ht->len);
    i = hashed_key % ht->len;
    current = ht->values[i];
    while (current != NULL) {
        if (current->hash_key == hashed_key)
            return delete_ht_value(ht, current, prev, i);
        prev = current;
        current = current->next;
    }
    return 84;
}
