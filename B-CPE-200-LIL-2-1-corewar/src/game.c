/*
** EPITECH PROJECT, 2025
** main.c
** File description:
** main.c
*/

#include "my.h"

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
}

void can_be_executed(robot_t *robot, corewar_t *corewar)
{
    op_t op = op_tab[16];

    if (robot->in_live <= 0)
        return;
    robot->in_live--;
    for (int i = 0; op_tab[i].mnemonique != NULL; i++){
        if (op_tab[i].code == corewar->memory[robot->prog_counter]){
            op = op_tab[i];
        }
    }
    if (robot->cycles == op.nbr_cycles && robot->cycles != 0){
        execute_instruction(robot, corewar);
        robot->cycles = 0;
    } else {
        robot->cycles++;
        if (robot->cycles > 1001)
            robot->cycles = 0;
    }
}

static int *add_index_to_array(int index, int *array)
{
    int i = 0;
    int *new_array;

    for (; array != NULL && array[i] != -1; i++);
    new_array = malloc(sizeof(int) * (i + 2));
    if (new_array == NULL) {
        return array;
    }
    for (int j = 0; j < i; j++)
        new_array[j] = array[j];
    new_array[i] = index;
    new_array[i + 1] = -1;
    free(array);
    return new_array;
}

static int is_passed(int index, int *array)
{
    for (int i = 0; array != NULL && array[i] != -1; i++){
        if (array[i] == index)
            return 1;
    }
    return 0;
}

static void display_winner(corewar_t *corewar)
{
    for (int i = 0; corewar->robot_array[i] != NULL; i++){
        if (corewar->robot_array[i]->in_live > 0){
            write(1, "The player ", 11);
            my_put_nbr(corewar->robot_array[i]->registers[0]);
            write(1, "(", 1);
            write(1, corewar->robot_array[i]->name,
                my_strlen(corewar->robot_array[i]->name));
            write(1, ") has won.\n", 12);
        }
    }
}

int win_condition(corewar_t *corewar)
{
    int nb_in_live = 0;
    int *passed = NULL;

    for (int i = 0; corewar->robot_array[i] != NULL; i++){
        if (corewar->robot_array[i]->in_live > 0 &&
            !is_passed(corewar->robot_array[i]->registers[0], passed)){
            nb_in_live++;
            passed = add_index_to_array(corewar->robot_array[i]->registers[0],
                passed);
        }
    }
    free(passed);
    if (nb_in_live >= 2)
        return 0;
    display_winner(corewar);
    return 1;
}

void game_loop(corewar_t *corewar, int dump)
{
    int finish = 0;

    while (!finish){
        if (dump == corewar->cycles)
            break;
        for (int i = 0; corewar->robot_array[i] != NULL; i++){
            can_be_executed(corewar->robot_array[i], corewar);
            finish = win_condition(corewar);
        }
        corewar->cycles++;
    }
    if (dump > -1)
        print_memory(corewar->memory);
    free_corewar(corewar);
}
