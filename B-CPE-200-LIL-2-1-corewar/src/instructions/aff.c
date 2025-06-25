/*
** EPITECH PROJECT, 2025
** aff.c
** File description:
** aff.c
*/

#include "my.h"

void instruction_aff(robot_t *robot, corewar_t *corewar)
{
    args_type_t *types = get_coding_byte(robot, corewar->memory);
    char reg;

    if (robot == NULL || types == NULL || types[0] != T_REG)
        return;
    reg = corewar->memory[robot->prog_counter + 2];
    if (reg < 1 || reg > REG_NUMBER) {
        free(types);
        return;
    }
    reg--;
    write(1, &(char){robot->registers[reg] % 256}, 1);
    robot->prog_counter += 3;
    free(types);
}
