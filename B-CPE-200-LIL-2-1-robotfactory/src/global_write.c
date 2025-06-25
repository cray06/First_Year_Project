/*
** EPITECH PROJECT, 2025
** global_write.c
** File description:
** global_write.c
*/

#include "asm.h"

void handling_index(write_file_t *write_file, int i, int is_index)
{
    if (is_index) {
        fwrite(&(int){invert_hexa_value(
            get_direct_value(write_file->line->args[i])) >> 16},
            IND_SIZE, 1, write_file->cor_file);
    } else
        fwrite(&(int){invert_hexa_value(
            get_direct_value(write_file->line->args[i]))},
            DIR_SIZE, 1, write_file->cor_file);
}

void handle_case(write_file_t *write_file, int i, int is_index_case)
{
    if (get_direct_value(write_file->line->args[i]) != 84)
        handling_index(write_file, i, is_index_case);
    if (get_register(write_file->line->args[i]) != 84)
        fwrite(&(int){get_register(write_file->line->args[i])},
            REG_SIZE, 1, write_file->cor_file);
    if (get_indirect_value(write_file->line->args[i]) != 84)
        fwrite(&(int){invert_hexa_value(
            get_indirect_value(write_file->line->args[i])) >> 16},
            IND_SIZE, 1, write_file->cor_file);
    if (is_label(write_file->line->args[i])){
        fwrite(&(int){invert_hexa_value(get_bytes_label(
            get_label_value(write_file->line->args[i]),
            write_file->line->index, write_file->list)) >> 16},
            IND_SIZE, 1, write_file->cor_file);
    }
}

void check_for_size(write_file_t *write_file, int i, op_t op)
{
    if (is_index(op) == 1) {
        handle_case(write_file, i, 1);
    } else
        handle_case(write_file, i, 0);
}

void write_line(line_t *line, FILE *cor_file, linked_list_t *list)
{
    op_t op = get_op(line->args[0]);
    write_file_t write_file = {line, cor_file, list};

    fwrite(&op.code, sizeof(char), 1, cor_file);
    if (check_second_byte_writable(op))
        fwrite(&(int){binary_to_decimal(get_binary_second_byte(line))},
            sizeof(char), 1, cor_file);
    for (int i = 0; line->args[i] != NULL; i++)
        check_for_size(&write_file, i, op);
}

void write_body(linked_list_t *list, FILE *cor_file, linked_list_t *list_full)
{
    linked_list_t *current = list;

    if (current != NULL && current->next != NULL)
        write_body(current->next, cor_file, list_full);
    if (current != NULL &&
        get_op((line_t *){current->data}->args[0]).mnemonique != NULL)
        write_line(current->data, cor_file, list_full);
}
