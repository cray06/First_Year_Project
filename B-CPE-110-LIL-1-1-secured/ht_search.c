/*
** EPITECH PROJECT, 2025
** ht_search.c
** File description:
** ht_search.c
*/

#include "include/my.h"

char *ht_search(hashtable_t *ht, char *key)
{
    int hashed_key = 0;
    int i = 0;
    hashvalue_t *current = NULL;

    if (ht == NULL || key == NULL || ht->len <= 0)
        return NULL;
    hashed_key = ht->hash(key, ht->len);
    i = hashed_key % ht->len;
    current = ht->values[i];
    while (current != NULL) {
        if (current->hash_key == hashed_key)
            return current->hash_value;
        current = current->next;
    }
    return NULL;
}
