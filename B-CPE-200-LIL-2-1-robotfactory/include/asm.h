/*
** EPITECH PROJECT, 2025
** bootstrap
** File description:
** bootstrap
*/

#ifndef BOOTSTRAP_H
    #define BOOTSTRAP_H

    #include <unistd.h>
    #include <fcntl.h>
    #include <stdlib.h>
    #include <stdio.h>
    #include <stdint.h>
    #include <stdbool.h>
    #include "op.h"

typedef struct line {
    char *label;
    char **args;
    char **array;
    int size_line;
    int index;
} line_t;

typedef struct linked_list {
    void *data;
    struct linked_list *next;
} linked_list_t;

typedef struct write_file {
    line_t *line;
    FILE *cor_file;
    linked_list_t *list;
} write_file_t;

char **my_str_to_word_array(char const *str, char *delimiters);
int my_strlen(char const *str);
char *my_strcat(char *dest, char const *src);
char *my_strcpy(char *dest, char const *src);
char *my_strdup(char const *src);
int my_strncmp(char const *s1, char const *s2, int n);
void free_word_array(char **word_array);
int len_word_array(char **word_array);
int my_strcmp(char const *s1, char const *s2);
void push_to_list(linked_list_t **begin, void *data);
line_t *set_line(char **array);
header_t get_header_file(linked_list_t *list);
char *my_strncpy(char *dest, char const *src, int n);
int my_compute_power_rec(int nb, int p);
int binary_to_decimal(char *binaire);
void write_line(line_t *line, FILE *cor_file, linked_list_t *list);
void write_body(linked_list_t *list, FILE *cor_file, linked_list_t *list_full);
op_t get_op(char *mnemonique);
int check_second_byte_writable(op_t op);
char *get_binary_second_byte(line_t *line);
int get_register(char *line);
bool my_isnumber(const char *str);
int my_getnbr(char const *str);
int get_direct_value(char *line);
uint32_t invert_hexa_value(uint32_t hexa_value);
int get_indirect_value(char *line);
int is_index(op_t op);
int get_size_of_line(char **args);
int is_label(char *argument);
char *get_label_value(char *line);
int get_bytes_label(char *label, int index, linked_list_t *list);
int check_file(linked_list_t *list);
int my_str_is_number(char *str);
int is_number(char c);

#endif /*BOOTSTRAP_H*/
