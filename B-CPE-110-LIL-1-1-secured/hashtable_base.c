/*
** EPITECH PROJECT, 2025
** hashtable_base.c
** File description:
** hashtable_base.c
*/

#include "include/my.h"

hashtable_t *new_hashtable(int (*hash)(char *, int), int len)
{
    hashtable_t *ht = malloc(sizeof(hashtable_t));

    if (ht == NULL)
        return NULL;
    if (err_creation_ht(ht, hash, len) == 84)
        return NULL;
    ht->hash = hash;
    ht->len = len;
    ht->values = malloc(sizeof(hashvalue_t *) * len);
    if (ht->values == NULL)
        return NULL;
    for (int i = 0; i < len; i++)
        ht->values[i] = NULL;
    return ht;
}

void delete_hashtable(hashtable_t *ht)
{
    hashvalue_t *current;
    hashvalue_t *next;

    if (ht == NULL)
        return;
    for (int i = 0; i < ht->len; i++) {
        current = ht->values[i];
        while (current != NULL) {
            next = current->next;
            free(current->word);
            free(current->hash_value);
            free(current);
            current = next;
        }
    }
    free(ht->values);
    free(ht);
}
