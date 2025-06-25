/*
** EPITECH PROJECT, 2025
** execution.c
** File description:
** Execution functions for bonus
*/

#include "../include/my.h"
#include "../include/visualizer.h"

const instruction_t instructions[] = {
    {1, &instruction_live},
    {2, &instruction_ld},
    {3, &instruction_st},
    {4, &instruction_add},
    {5, &instruction_sub},
    {6, &instruction_and},
    {7, &instruction_or},
    {8, &instruction_xor},
    {9, &zjump_instruction},
    {10, &ldi_instruction},
    {11, &instruction_sti},
    {12, &instruction_fork},
    {13, &instruction_lld},
    {14, &lldi_instruction},
    {15, &instruction_lfork},
    {16, &instruction_aff},
    {-1, NULL}
};

void execute_instruction(robot_t *robot, corewar_t *corewar)
{
    for (int i = 0; instructions[i].code != -1; i++) {
        if (corewar->memory[robot->prog_counter] == instructions[i].code) {
            instructions[i].f(robot, corewar);
        }
    }
    if (robot->prog_counter >= MEM_SIZE)
        robot->prog_counter = robot->prog_counter % MEM_SIZE;
}
