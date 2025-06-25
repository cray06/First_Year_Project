/*
** EPITECH PROJECT, 2025
** lldi.c
** File description:
** lldi.c
*/

#include "my.h"

void lldi_instruction(robot_t *robot, corewar_t *corewar)
{
    args_type_t *types = get_coding_byte(robot, corewar->memory);
    int pc_add = 2;
    int value1;
    int value2;
    int value3;
    int reg;

    if (types == NULL)
        return;
    value1 = set_value_from_type(types[0], corewar->memory, robot, &pc_add);
    value2 = set_value_from_type(types[0], corewar->memory, robot, &pc_add);
    value3 = read_direct_value(corewar->memory,
        robot->prog_counter + (value1 + value2));
    reg = corewar->memory[robot->prog_counter + pc_add] - 1;
    robot->registers[reg] = value3;
    robot->carry = value3 == 0 ? 1 : 0;
    robot->prog_counter += pc_add + 1;
    free(types);
}
