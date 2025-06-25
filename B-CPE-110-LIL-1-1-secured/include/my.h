/*
** EPITECH PROJECT, 2023
** B-CPE-110 : Secured
** File description:
** hashtable.h
*/

#ifndef HASHTABLE_H
    #define HASHTABLE_H

    #include <stdbool.h>
    #include <stdlib.h>
    #include <stddef.h>
    #include <stdio.h>
    #include <stdarg.h>
    #include <string.h>
    #include <unistd.h>
    #include <stdbool.h>

typedef struct hashvalue_s {
    int hash_key;
    char *hash_value;
    char *word;
    struct hashvalue_s *next;
} hashvalue_t;

typedef struct hashtable_s {
    int len;
    int (*hash)(char *, int);
    hashvalue_t **values;
} hashtable_t;

// Hash function
int hash(char *key, int len);

// Create & destro table
hashtable_t *new_hashtable(int (*hash)(char *, int), int len);
void delete_hashtable(hashtable_t *ht);

// Handle table
int ht_insert(hashtable_t *ht, char *key, char *value);
int ht_delete(hashtable_t *ht, char *key);
char *ht_search(hashtable_t *ht, char *key);
void ht_dump(hashtable_t *ht);

// Main Function
int err_creation_ht(hashtable_t *ht, int (*hash)(char *, int), int len);
int my_putstr(char const *str);
int my_put_nbr(int nb);
void my_putchar(char c);
int my_strlen(char const *str);
char *my_strdup(char const *src);


#endif /* HASHTABLE_H */
