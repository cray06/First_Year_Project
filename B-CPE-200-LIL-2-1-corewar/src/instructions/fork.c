/*
** EPITECH PROJECT, 2025
** fork.c
** File description:
** fork.c
*/

#include "my.h"

robot_t *create_forked_robot(robot_t *parent)
{
    robot_t *forked = malloc(sizeof(robot_t));

    if (forked == NULL)
        return NULL;
    forked->file = NULL;
    forked->in_live = parent->in_live;
    forked->cycles = 0;
    forked->prog_size = parent->prog_size;
    forked->adresse = parent->adresse;
    forked->current_instruction = parent->current_instruction;
    my_strncpy(forked->name, parent->name, PROG_NAME_LENGTH + 1);
    my_strncpy(forked->comment, parent->comment, COMMENT_LENGTH + 1);
    for (int i = 0; i < REG_NUMBER; i++)
        forked->registers[i] = parent->registers[i];
    forked->carry = parent->carry;
    return forked;
}

robot_t **add_robot_to_array(robot_t *forked, robot_t **robot_array)
{
    int i = 0;
    robot_t **new_array;

    for (; robot_array != NULL && robot_array[i] != NULL; i++);
    new_array = malloc(sizeof(robot_t *) * (i + 2));
    if (new_array == NULL) {
        free(forked);
        return robot_array;
    }
    for (int j = 0; j < i; j++)
        new_array[j] = robot_array[j];
    new_array[i] = forked;
    new_array[i + 1] = NULL;
    free(robot_array);
    return new_array;
}

void instruction_fork(robot_t *robot, corewar_t *corewar)
{
    int diff = 0;
    robot_t *forked;

    if (robot == NULL || corewar->memory == NULL || corewar == NULL)
        return;
    diff = read_indirect_value(corewar->memory, robot->prog_counter + 1);
    diff = (diff % IDX_MOD);
    forked = create_forked_robot(robot);
    if (forked == NULL)
        return;
    forked->prog_counter = (robot->prog_counter + diff) % MEM_SIZE;
    corewar->robot_array = add_robot_to_array(forked, corewar->robot_array);
    robot->prog_counter += 3;
}
