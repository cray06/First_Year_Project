/*
** EPITECH PROJECT, 2025
** live.c
** File description:
** live.c for bonus
*/

#include "../../include/my.h"

robot_t **get_robot_from_id(corewar_t *corewar, int id)
{
    robot_t **array = NULL;

    for (int i = 0; corewar->robot_array[i] != NULL; i++) {
        if (corewar->robot_array[i]->registers[0] == id)
            array = add_robot_to_array(corewar->robot_array[i], array);
    }
    return array;
}

void instruction_live(robot_t *robot, corewar_t *corewar)
{
    int player_number = 0;
    robot_t **robot_live;

    if (robot == NULL || corewar->memory == NULL)
        return;
    player_number = read_direct_value(corewar->memory,
        robot->prog_counter + 1);
    robot_live = get_robot_from_id(corewar, player_number);
    if (robot_live != NULL) {
        corewar->nb_live++;
        for (int i = 0; robot_live[i] != NULL; i++)
            robot_live[i]->in_live = corewar->cycle_to_die;
        if (corewar->nb_live == NBR_LIVE) {
            corewar->cycle_to_die -= CYCLE_DELTA;
            corewar->nb_live = 0;
        }
        free(robot_live);
    }
    robot->prog_counter = robot->prog_counter + 5;
} 