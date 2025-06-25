/*
** EPITECH PROJECT, 2025
** st.c
** File description:
** st.c
*/

#include "my.h"

void handle_reg_type(robot_t *robot, char reg1, char *memory, int pc)
{
    char reg2 = memory[pc + 3];

    reg2--;
    robot->registers[reg2] = robot->registers[reg1];
}

void handle_ind_type(robot_t *robot, char reg1, char *memory, int pc)
{
    short value = 0;
    int address = 0;
    int reg_value = robot->registers[reg1];

    value = (memory[pc + 3] << 8) | memory[pc + 4];
    value = swap_bytes(value);
    address = (robot->prog_counter + (value % IDX_MOD)) % MEM_SIZE;
    write_4_bytes(memory, reg_value, address);
}

void instruction_st(robot_t *robot, corewar_t *corewar)
{
    args_type_t *types = get_coding_byte(robot, corewar->memory);
    char reg1 = 0;

    if (types == NULL)
        return;
    reg1 = corewar->memory[robot->prog_counter + 2];
    reg1--;
    if (types[1] == T_REG){
        handle_reg_type(robot, reg1, corewar->memory, robot->prog_counter);
        robot->prog_counter += 4;
    }
    if (types[1] == T_IND){
        handle_ind_type(robot, reg1, corewar->memory, robot->prog_counter);
        robot->prog_counter += 5;
    }
    free(types);
}
