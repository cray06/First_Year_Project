/*
** EPITECH PROJECT, 2025
** sti.c
** File description:
** sti.c
*/

#include "my.h"

static void handle_sti_error(args_type_t *types)
{
    if (types != NULL)
        free(types);
    return;
}

void instruction_sti(robot_t *robot, corewar_t *corewar)
{
    args_type_t *types = get_coding_byte(robot, corewar->memory);
    int value1 = 0;
    int value2 = 0;
    int value3 = 0;
    int address = 0;
    char reg1 = corewar->memory[robot->prog_counter + 2];

    if (robot == NULL || types == NULL || types[0] != T_REG
        || !validate_reg3(reg1))
        return handle_sti_error(types);
    reg1--;
    value1 = robot->registers[reg1];
    value2 = read_indirect_value(corewar->memory, robot->prog_counter + 3);
    value3 = read_indirect_value(corewar->memory, robot->prog_counter + 5);
    address = (robot->prog_counter + ((value2 + value3) % IDX_MOD)) % MEM_SIZE;
    write_4_bytes(corewar->memory, value1, address);
    robot->prog_counter += 2 + get_param_size(types, 1);
    free(types);
}
