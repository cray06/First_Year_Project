/*
** EPITECH PROJECT, 2025
** ldi.c
** File description:
** ldi.c
*/

#include "my.h"

int set_value_from_type(args_type_t type, char *memory,
    robot_t *robot, int *pc_add)
{
    int value;

    if (type == T_IND){
        value = read_indirect_value(memory, robot->prog_counter +
            read_indirect_value(memory, robot->prog_counter + *pc_add)
            % IDX_MOD);
        *pc_add += IND_SIZE;
    }
    if (type == T_DIR){
        value = read_indirect_value(memory, robot->prog_counter + *pc_add);
        *pc_add += IND_SIZE;
    }
    if (type == T_REG){
        value = robot->registers[memory[robot->prog_counter] - 1];
        *pc_add += 1;
    }
    return value;
}

void ldi_instruction(robot_t *robot, corewar_t *corewar)
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
        robot->prog_counter + (value1 + value2) % IDX_MOD);
    reg = corewar->memory[robot->prog_counter + pc_add] - 1;
    robot->registers[reg] = value3;
    robot->carry = value3 == 0 ? 1 : 0;
    robot->prog_counter += pc_add + 1;
    free(types);
}
