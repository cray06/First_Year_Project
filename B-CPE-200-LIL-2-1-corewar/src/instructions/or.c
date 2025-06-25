/*
** EPITECH PROJECT, 2025
** or.c
** File description:
** or.c
*/

#include "my.h"

void apply_or(robot_t *robot, int value1, int value2, char reg3)
{
    robot->registers[reg3] = value1 | value2;
    robot->carry = (robot->registers[reg3] == 0) ? 1 : 0;
    robot->prog_counter += 5;
}

void instruction_or(robot_t *robot, corewar_t *corewar)
{
    args_type_t *types = get_coding_byte(robot, corewar->memory);
    int value1 = 0;
    int value2 = 0;
    char reg3 = corewar->memory[robot->prog_counter + 4];

    if (robot == NULL || types == NULL || types[2] != T_REG
        || !validate_reg3(reg3)) {
        free(types);
        return;
    }
    value1 = get_value_from_type(types[0], robot, corewar->memory, 2);
    value2 = get_value_from_type(types[1], robot, corewar->memory, 3);
    if (value1 == -1 || value2 == -1) {
        free(types);
        return;
    }
    apply_or(robot, value1, value2, reg3 - 1);
    free(types);
}
