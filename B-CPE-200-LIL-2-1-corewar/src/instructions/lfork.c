/*
** EPITECH PROJECT, 2025
** lfork.c
** File description:
** lfork.c
*/

#include "my.h"

void instruction_lfork(robot_t *robot, corewar_t *corewar)
{
    int diff = 0;
    robot_t *forked;

    if (robot == NULL || corewar->memory == NULL || corewar == NULL)
        return;
    diff = read_indirect_value(corewar->memory, robot->prog_counter + 1);
    forked = create_forked_robot(robot);
    if (forked == NULL)
        return;
    forked->prog_counter = (robot->prog_counter + diff) % MEM_SIZE;
    corewar->robot_array = add_robot_to_array(forked, corewar->robot_array);
    robot->prog_counter += 3;
}
