/*
** EPITECH PROJECT, 2025
** game_loop.c
** File description:
** Game loop functions for bonus
*/

#include "../include/my.h"
#include "../include/visualizer.h"

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
    for (int i = 0; array != NULL && array[i] != -1; i++) {
        if (array[i] == index)
            return 1;
    }
    return 0;
}

int win_condition(corewar_t *corewar)
{
    int nb_in_live = 0;
    int *passed = NULL;

    for (int i = 0; corewar->robot_array[i] != NULL; i++) {
        if (corewar->robot_array[i]->in_live > 0 &&
            !is_passed(corewar->robot_array[i]->registers[0], passed)) {
            nb_in_live++;
            passed = add_index_to_array(corewar->robot_array[i]->registers[0],
                passed);
        }
    }
    free(passed);
    if (nb_in_live >= 2)
        return 0;
    return 1;
}

void can_be_executed(robot_t *robot, corewar_t *corewar)
{
    op_t op = op_tab[16];

    if (robot->in_live <= 0)
        return;
    robot->in_live--;
    for (int i = 0; op_tab[i].mnemonique != NULL; i++) {
        if (op_tab[i].code == corewar->memory[robot->prog_counter]) {
            op = op_tab[i];
        }
    }
    if (robot->cycles == op.nbr_cycles && robot->cycles != 0) {
        execute_instruction(robot, corewar);
        robot->cycles = 0;
    } else {
        robot->cycles++;
        if (robot->cycles > 1001)
            robot->cycles = 0;
    }
}
