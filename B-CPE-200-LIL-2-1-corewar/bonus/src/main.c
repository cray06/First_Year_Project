/*
** EPITECH PROJECT, 2025
** main.c
** File description:
** Main file for bonus part
*/

#include "../include/my.h"
#include "../include/visualizer.h"

int main(int ac, char **av)
{
    corewar_t *corewar = init_corewar(ac, av);

    if (corewar == NULL)
        return 84;
    if (corewar->robot_array == NULL || corewar->memory == NULL) {
        free_corewar(corewar);
        return 84;
    }
    corewar->cycles = 0;
    visualizer_loop(corewar);
    return 0;
}
