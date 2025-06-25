/*
** EPITECH PROJECT, 2025
** visualizer.h
** File description:
** Header for visualizer
*/

#ifndef VISUALIZER_H_
    #define VISUALIZER_H_

    #include "../include/my.h"

    void init_ncurses(void);
    void create_windows(void);
    void display_memory(corewar_t *corewar);
    void display_info(corewar_t *corewar);
    void cleanup_ncurses(void);
    void visualizer_loop(corewar_t *corewar);

    int win_condition(corewar_t *corewar);
    void can_be_executed(robot_t *robot, corewar_t *corewar);
    void execute_instruction(robot_t *robot, corewar_t *corewar);

#endif /* VISUALIZER_H_ */ 