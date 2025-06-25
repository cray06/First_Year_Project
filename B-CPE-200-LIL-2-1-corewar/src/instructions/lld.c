/*
** EPITECH PROJECT, 2025
** lld.c
** File description:
** lld.c
*/

#include "my.h"

void instruction_lld(robot_t *robot, corewar_t *core)
{
    int reg;
    int value = 0;
    int pc_add = 2;
    args_type_t *types = get_coding_byte(robot, core->memory);

    if (types == NULL)
        return;
    if (types[0] == T_DIR){
        value = read_direct_value(core->memory, robot->prog_counter + pc_add);
        pc_add += DIR_SIZE;
    } else if (types[0] == T_IND){
        value = read_direct_value(core->memory, robot->prog_counter +
            read_indirect_value(core->memory, robot->prog_counter + pc_add));
        pc_add += IND_SIZE;
    }
    reg = core->memory[robot->prog_counter + pc_add] - 1;
    robot->registers[reg] = value;
    robot->carry = value == 0 ? 1 : 0;
    robot->prog_counter += pc_add + 1;
    free(types);
}
