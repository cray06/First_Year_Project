/*
** EPITECH PROJECT, 2025
** main.c
** File description:
** main.c
*/

#include "my.h"

int main(int ac, char **av)
{
    corewar_t *corewar = init_corewar(ac, av);

    if (corewar == NULL)
        return 84;
    if (corewar->robot_array == NULL || corewar->memory == NULL){
        free_corewar(corewar);
        return 84;
    }
    corewar->cycles = 0;
    game_loop(corewar, get_flag_value(ac, av, "-dump"));
    return 0;
}
