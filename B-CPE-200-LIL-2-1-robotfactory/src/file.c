/*
** EPITECH PROJECT, 2025
** file
** File description:
** file
*/
#include "asm.h"
#include "op.h"

static int is_valid_label(char *label, linked_list_t *list)
{
    linked_list_t *current = list;

    while (current != NULL){
        if (!my_strcmp((line_t *){current->data}->label, label)){
            return 1;
        }
        current = current->next;
    }
    return 0;
}

static int check_type(char *argument, op_t op, int index)
{
    if (argument[0] == 'r' && op.type[index] % 2 >= T_REG)
        return 1;
    if ((my_str_is_number(argument) || !my_strncmp(argument, "%:", 2))
        && op.type[index] % 8 >= T_IND)
        return 1;
    if (argument[0] == DIRECT_CHAR && op.type[index] % 4 >= T_DIR)
        return 1;
    return 0;
}

int check_error_arguments(char **args, op_t op, linked_list_t *list)
{
    for (int i = 0; args[i] != NULL && args[i][0] != COMMENT_CHAR; i++){
        if (args[i][0] != 'r' && args[i][0] != DIRECT_CHAR &&
            !is_number(args[i][0]) && args[i][0] != '-')
            return 0;
        if (!my_str_is_number(args[i] + 1) && (my_strncmp("%:", args[i], 2) ||
            !is_valid_label(args[i] + 2, list)))
            return 0;
        if (!check_type(args[i], op, i))
            return 0;
    }
    return 1;
}

static int get_nb_args(char **args)
{
    int nb = 0;

    for (int i = 0; args[i] != NULL && args[i][0] != COMMENT_CHAR; i++){
        nb++;
    }
    return nb;
}

static int check_only_one_label(char *label, linked_list_t *list)
{
    int nb = 0;
    linked_list_t *current = list;

    while (current != NULL){
        if (!my_strcmp((line_t *){current->data}->label, label))
            nb++;
        if (nb > 1)
            return 0;
        current = current->next;
    }
    return 1;
}

static int check_champion_info(char **args)
{
    int static nb_name = 0;
    int static nb_comment = 0;

    if (len_word_array(args) != 2)
        return 0;
    if (!my_strcmp(args[0], NAME_CMD_STRING))
        nb_name++;
        if (!my_strcmp(args[1], "") || my_strlen(args[1]) > PROG_NAME_LENGTH)
            return 0;
    if (!my_strcmp(args[0], COMMENT_CMD_STRING))
        nb_comment++;
        if (!my_strcmp(args[1], "") || my_strlen(args[1]) > COMMENT_LENGTH)
            return 0;
    if (nb_comment <= 1 && nb_name <= 1)
        return 1;
    else
        return 0;
}

int check_error_line(char **args, char *label, linked_list_t *list)
{
    op_t op;

    if (len_word_array(args) == 0 || args[0][0] == '#')
        return 1;
    if (!my_strcmp(args[0], COMMENT_CMD_STRING) ||
        !my_strcmp(args[0], NAME_CMD_STRING))
        return check_champion_info(args);
    op = get_op(args[0]);
    if (op.mnemonique == NULL)
        return 0;
    if (get_nb_args(args + 1) != op.nbr_args)
        return 0;
    if (label != NULL && !check_only_one_label(label, list))
        return 0;
    return check_error_arguments(args + 1, op, list);
}

static int can_get_infos(linked_list_t *list)
{
    linked_list_t *current = list;

    while (current != NULL){
        if (!my_strcmp((line_t *){current->data}->args[0], NAME_CMD_STRING))
            return 1;
        current = current->next;
    }
    return 0;
}

int check_file(linked_list_t *list)
{
    linked_list_t *current = list;

    if (!can_get_infos(list))
        return 0;
    while (current != NULL){
        if (!check_error_line((line_t *){current->data}->args,
            (line_t *){current->data}->label, list) ||
            my_strlen((line_t *){current->data}->label) == 0)
            return 0;
        current = current->next;
    }
    return 1;
}
