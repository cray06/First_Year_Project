/*
** EPITECH PROJECT, 2025
** add.c
** File description:
** add.c
*/

#include "my.h"

bool read_registers(char *memory, int pc, char *regs)
{
    regs[0] = memory[pc + 2];
    regs[1] = memory[pc + 3];
    regs[2] = memory[pc + 4];
    return true;
}

void instruction_add(robot_t *robot, corewar_t *corewar)
{
    char regs[3] = {0, 0, 0};
    args_type_t *types = get_coding_byte(robot, corewar->memory);

    if (robot == NULL || types == NULL)
        return;
    if (!read_registers(corewar->memory, robot->prog_counter, regs)) {
        free(types);
        return;
    }
    regs[0]--;
    regs[1]--;
    regs[2]--;
    robot->registers[regs[2]] =
        robot->registers[regs[0]] + robot->registers[regs[1]];
    robot->carry = (robot->registers[regs[2]] == 0) ? 1 : 0;
    robot->prog_counter += 5;
    free(types);
}
