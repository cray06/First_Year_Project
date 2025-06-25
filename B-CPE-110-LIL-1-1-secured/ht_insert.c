/*
** EPITECH PROJECT, 2025
** ht_insert.c
** File description:
** ht_insert.c
*/

#include "include/my.h"

void create_index(hashtable_t *ht, char *key,
    char *value, int hashed_key)
{
    hashvalue_t *new_item = malloc(sizeof(hashvalue_t));
    int i = 0;

    if (new_item == NULL || ht->len <= 0)
        return;
    i = hashed_key % ht->len;
    new_item->hash_key = hashed_key;
    new_item->hash_value = my_strdup(value);
    new_item->word = my_strdup(key);
    new_item->next = NULL;
    ht->values[i] = new_item;
}

void add_value(hashtable_t *ht, char *key, char *value, int hashed_key)
{
    int i = 0;
    hashvalue_t *new_item = malloc(sizeof(hashvalue_t));
    hashvalue_t *current = NULL;

    if (new_item == NULL)
        return;
    i = hashed_key % ht->len;
    current = ht->values[i];
    while (current != NULL && current->hash_key == hashed_key) {
        free(current->hash_value);
        current->hash_value = my_strdup(value);
        return;
    }
    new_item->hash_key = hashed_key;
    new_item->word = my_strdup(key);
    new_item->hash_value = my_strdup(value);
    new_item->next = NULL;
    current->next = new_item;
}

int ht_insert(hashtable_t *ht, char *key, char *value)
{
    int hashed_key = 0;

    if (ht == NULL || key == NULL || value == NULL)
        return 84;
    hashed_key = ht->hash(key, ht->len);
    if (ht->values[hashed_key % ht->len] == NULL)
        create_index(ht, key, value, hashed_key);
    else
        add_value(ht, key, value, hashed_key);
    return 0;
}
