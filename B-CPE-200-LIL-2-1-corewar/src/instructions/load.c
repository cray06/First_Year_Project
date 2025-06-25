/*
** EPITECH PROJECT, 2025
** load
** File description:
** load
*/

#include "my.h"

void instruction_ld(robot_t *robot, corewar_t *core)
{
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
            read_indirect_value(core->memory, robot->prog_counter + pc_add)
            % IDX_MOD);
        pc_add += IND_SIZE;
    }
    robot->registers[core->memory[robot->prog_counter + pc_add] - 1] = value;
    robot->carry = value == 0 ? 1 : 0;
    robot->prog_counter += pc_add + 1;
    free(types);
}
