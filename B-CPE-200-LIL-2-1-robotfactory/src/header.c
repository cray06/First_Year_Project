/*
** EPITECH PROJECT, 2025
** header.c
** File description:
** header.c
*/
#include "op.h"
#include "asm.h"

static int get_nb_bytes_intstructions(char *instruction)
{
    for (int i = 0; instruction != NULL && op_tab[i].mnemonique != NULL; i++){
        if (!my_strcmp(instruction, op_tab[i].mnemonique))
            return check_second_byte_writable(get_op(instruction)) ? 2 : 1;
    }
    return 0;
}

int is_label(char *argument)
{
    if (!my_strncmp(argument, "%:", 2))
        return 1;
    return 0;
}

static int get_nb_bytes_argument(char *argument, int is_index)
{
    if (argument[0] == 'r')
        return REG_SIZE;
    if (argument[0] == DIRECT_CHAR && !is_index && !is_label(argument))
        return DIR_SIZE;
    else
        return IND_SIZE;
}

int get_size_of_line(char **args)
{
    int size = get_nb_bytes_intstructions(args[0]);
    int index = is_index(get_op(args[0]));

    for (int i = 1; size > 0 && args[i] != NULL; i++){
        if (my_strcmp(args[0], NAME_CMD_STRING) &&
            my_strcmp(args[0], COMMENT_CMD_STRING))
            size += get_nb_bytes_argument(args[i], index);
    }
    return size;
}

int get_size_body(linked_list_t *list)
{
    int size = 0;
    linked_list_t *current = list;

    while (current != NULL){
        size += (line_t *){current->data}->size_line;
        current = current->next;
    }
    return size;
}

uint32_t invert_hexa_value(uint32_t hexa_value)
{
    uint32_t axeh = 0;

    for (int i = 0; i < 4; i++)
        axeh = (axeh << 8) | ((hexa_value >> (8 * i)) & 0xFF);
    return axeh;
}

header_t get_header_file(linked_list_t *list)
{
    header_t new_header;
    linked_list_t *current = list;

    new_header.magic = invert_hexa_value(COREWAR_EXEC_MAGIC);
    my_strncpy(new_header.prog_name, "", PROG_NAME_LENGTH + 4);
    my_strncpy(new_header.comment, "", COMMENT_LENGTH + 4);
    while (current != NULL){
        if ((line_t *){current->data}->args[0] != NULL &&
            !my_strcmp((line_t *){current->data}->args[0], NAME_CMD_STRING))
            my_strncpy(new_header.prog_name,
                (line_t *){current->data}->args[1], PROG_NAME_LENGTH + 4);
        if ((line_t *){current->data}->args[0] != NULL &&
            !my_strcmp((line_t *){current->data}->args[0], COMMENT_CMD_STRING))
            my_strncpy(new_header.comment,
                (line_t *){current->data}->args[1], COMMENT_LENGTH + 4);
        current = current->next;
    }
    new_header.prog_size = invert_hexa_value(get_size_body(list));
    return new_header;
}
