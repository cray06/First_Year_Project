/*
** EPITECH PROJECT, 2025
** zjump.c
** File description:
** zjump.c
*/

#include "my.h"

void zjump_instruction(robot_t *robot, corewar_t *corewar)
{
    int value;

    if (robot->carry == 1){
        value = read_indirect_value(corewar->memory, robot->prog_counter + 1);
        robot->prog_counter += value % IDX_MOD;
    }
}
