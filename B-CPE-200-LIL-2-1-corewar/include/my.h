/*
** EPITECH PROJECT, 2025
** MY_H
** File description:
** MY_H
*/

#ifndef MY_H
    #define MY_H

    #include <unistd.h>
    #include <fcntl.h>
    #include <stdlib.h>
    #include <stdio.h>
    #include <stdint.h>
    #include <stdbool.h>
    #include "op.h"

typedef struct {
    FILE *file;
    int in_live;
    int cycles;
    int prog_counter;
    int prog_size;
    int adresse;
    char current_instruction;
    char name[PROG_NAME_LENGTH + 1];
    char comment[COMMENT_LENGTH + 1];
    int registers[REG_NUMBER];
    int carry;
} robot_t;

typedef struct {
    char *memory;
    int cycles;
    robot_t **robot_array;
    int cycle_to_die;
    int nb_live;
} corewar_t;

typedef struct {
    int code;
    void (*f)(robot_t *robot, corewar_t *corewar);
} instruction_t;

int my_strcmp(char const *s1, char const *s2);
int my_strlen(char const *str);
int my_compute_power_rec(int nb, int p);
int get_len_index_array(int *index_array);
int *add_index_in_array(int *array, int new_index);
int my_getnbr(char const *str);
char *my_strncpy(char *dest, char const *src, int n);
int is_in_array(int *array, int index);
robot_t **get_robot_array(int ac, char **av);
corewar_t *init_corewar(int ac, char **av);
void free_corewar(corewar_t *corewar);
robot_t *fill_robot_from_file(const char *filename);
void fill_robot_info(robot_t *robot);
int my_put_nbr(int nb);
void my_putchar(char c);
int swap_bytes(int value);
int my_strncmp(char const *s1, char const *s2, int n);
char *get_int_to_bin(int value);
args_type_t *get_coding_byte(robot_t *robot, unsigned char *memory);
bool check_types(args_type_t *types);
bool read_registers(char *memory, int pc, char *regs);
bool validate_registers(char *regs);
int read_direct_value(char *memory, int index);
int read_indirect_value(char *memory, int index);
int read_register_value(robot_t *robot, int reg);
bool validate_reg3(char reg3);
int get_value_from_type(args_type_t type, robot_t *robot,
    char *memory, int diff);
int set_value_from_type(args_type_t type, char *memory,
    robot_t *robot, int *pc_add);
int get_param_size(args_type_t *type, int is_index);
robot_t *create_forked_robot(robot_t *parent);
robot_t **add_robot_to_array(robot_t *forked, robot_t **robot_array);
void print_memory(char *memory);
robot_t *create_forked_robot(robot_t *parent);
robot_t **add_robot_to_array(robot_t *forked, robot_t **robot_array);
void print_memory(char *memory);
void write_4_bytes(char *memory, int value, int address);
int get_flag_value(int ac, char **av, char *flag);
void game_loop(corewar_t *corewar, int dump);

void instruction_st(robot_t *robot, corewar_t *corewar);
void instruction_live(robot_t *robot, corewar_t *corewar);
void instruction_ld(robot_t *robot, corewar_t *corewar);
void instruction_add(robot_t *robot, corewar_t *corewar);
void instruction_sub(robot_t *robot, corewar_t *corewar);
void instruction_and(robot_t *robot, corewar_t *corewar);
void instruction_or(robot_t *robot, corewar_t *corewar);
void instruction_xor(robot_t *robot, corewar_t *corewar);
void instruction_sti(robot_t *robot, corewar_t *corewar);
void instruction_fork(robot_t *robot, corewar_t *corewar);
void instruction_lfork(robot_t *robot, corewar_t *corewar);
void instruction_aff(robot_t *robot, corewar_t *corewar);
void zjump_instruction(robot_t *robot, corewar_t *corewar);
void ldi_instruction(robot_t *robot, corewar_t *corewar);
void lldi_instruction(robot_t *robot, corewar_t *corewar);
void instruction_lld(robot_t *robot, corewar_t *corewar);

#endif /*MY_H*/
