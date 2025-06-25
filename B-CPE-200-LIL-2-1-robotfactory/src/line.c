/*
** EPITECH PROJECT, 2025
** line
** File description:
** line
*/
#include "asm.h"

op_t get_op(char *instruction)
{
    int i = 0;

    for (; instruction != NULL && op_tab[i].mnemonique != NULL; i++){
        if (!my_strcmp(op_tab[i].mnemonique, instruction))
            return op_tab[i];
    }
    return (op_t){NULL, 0, {0}, 0, 0, NULL};
}

int is_index(op_t op)
{
    if (op.mnemonique != NULL &&
        op.mnemonique[my_strlen(op.mnemonique) - 1] == 'i')
        return 1;
    return 0;
}

int check_second_byte_writable(op_t op)
{
    for (int i = 0; i < op.nbr_args; i++)
        if (op.type[i] % 2 != 0)
            return 1;
    return 0;
}

char *get_binary_second_byte(line_t *line)
{
    char *result = malloc(sizeof(char) * (8 + 1));
    int i = 1;

    if (result == NULL)
        return NULL;
    result[0] = '\0';
    for (; line->args[i] != NULL; i++) {
        if (line->args[i][0] == DIRECT_CHAR)
            my_strcat(result, "10");
        if (line->args[i][0] == 'r')
            my_strcat(result, "01");
        if (line->args[i][0] != 'r' && line->args[i][0] != DIRECT_CHAR)
            my_strcat(result, "11");
    }
    for (; i <= MAX_ARGS_NUMBER; i++)
        my_strcat(result, "00");
    return result;
}

int get_bytes_label(char *label, int index, linked_list_t *list)
{
    linked_list_t *current = list;
    int coef;
    int size = 0;

    while (current != NULL && (line_t *){current->data}->index != index
        && my_strcmp((line_t *){current->data}->label, label) != 0)
        current = current->next;
    if (current == NULL)
        return 0;
    if ((line_t *){current->data}->index == index)
        coef = -1;
    if (!my_strcmp((line_t *){current->data}->label, label))
        coef = 1;
    while (current != NULL &&
        ((line_t *){current->data}->index != index || coef == -1)
        && (my_strcmp((line_t *){current->data}->label, label) || coef == 1)) {
            current = current->next;
            size += (line_t *){current->data}->size_line;
    }
    return size * coef;
}
