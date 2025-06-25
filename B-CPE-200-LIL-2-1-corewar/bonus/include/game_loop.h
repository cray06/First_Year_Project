/*
** EPITECH PROJECT, 2025
** game_loop.h
** File description:
** Header for game loop functions
*/

#ifndef GAME_LOOP_H_
    #define GAME_LOOP_H_

    #include "../include/my.h"

    void process_cycle(corewar_t *corewar, int *cycle_to_die, int *nbr_live);
    int check_game_end(corewar_t *corewar);
    robot_t *get_winner(corewar_t *corewar);
    void bonus_game_loop(corewar_t *corewar);
    void can_be_executed(robot_t *robot, corewar_t *corewar);
    int win_condition(corewar_t *corewar);
    void execute_instruction(robot_t *robot, corewar_t *corewar);
    void process_cycle(corewar_t *corewar, int *cycle_to_die, int *nbr_live);

#endif /* GAME_LOOP_H_ */ 