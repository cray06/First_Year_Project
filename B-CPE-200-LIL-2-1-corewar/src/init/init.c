/*
** EPITECH PROJECT, 2025
** init
** File description:
** init
*/

#include "my.h"

static char *init_memory(void)
{
    char *memory = malloc(sizeof(char) * MEM_SIZE);

    if (memory == NULL)
        return NULL;
    for (int i = 0; i < MEM_SIZE; i++){
        memory[i] = 0;
    }
    return memory;
}

static int read_magic_number(FILE *file)
{
    int magic = 0;

    if (fread(&magic, sizeof(int), 1, file) != 1)
        return -1;
    magic = swap_bytes(magic);
    if (magic != COREWAR_EXEC_MAGIC)
        return -1;
    return magic;
}

static int read_program_name(FILE *file, char *name)
{
    if (fread(name, sizeof(char), PROG_NAME_LENGTH + 4, file)
        != PROG_NAME_LENGTH + 4)
        return 0;
    name[PROG_NAME_LENGTH] = '\0';
    return 1;
}

static int read_program_size(FILE *file)
{
    int prog_size = 0;

    if (fread(&prog_size, sizeof(int), 1, file) != 1)
        return -1;
    prog_size = swap_bytes(prog_size);
    return prog_size;
}

static int read_comment(FILE *file, char *comment)
{
    if (fread(comment, sizeof(char), COMMENT_LENGTH + 4, file)
        != COMMENT_LENGTH + 4)
        return 0;
    comment[COMMENT_LENGTH] = '\0';
    return 1;
}

int init_robot_info(robot_t *robot)
{
    char name[PROG_NAME_LENGTH + 1] = {0};
    char comment[COMMENT_LENGTH + 1] = {0};
    int magic = 0;

    if (robot == NULL || robot->file == NULL)
        return 84;
    magic = read_magic_number(robot->file);
    if (magic == -1)
        return 84;
    if (!read_program_name(robot->file, name))
        return 84;
    robot->prog_size = read_program_size(robot->file);
    if (robot->prog_size == -1)
        return 84;
    if (!read_comment(robot->file, comment))
        return 84;
    my_strncpy(robot->name, name, PROG_NAME_LENGTH + 1);
    my_strncpy(robot->comment, comment, COMMENT_LENGTH + 1);
    return 0;
}

static void write_instructions_in_memory(robot_t *robot, char *memory)
{
    char prog[robot->prog_size];

    for (int i = 0; i < robot->prog_size; i++)
        prog[i] = 0;
    if (fread(prog, sizeof(char), robot->prog_size, robot->file)
        != robot->prog_size)
        return;
    if (memory != NULL);
        my_strncpy(memory + robot->adresse, prog, robot->prog_size);
    fclose(robot->file);
}

static void init_adresses(robot_t *robot, robot_t **robot_array, int index)
{
    int max_prog = 0;

    for (; robot_array != NULL && robot_array[max_prog] != NULL; max_prog++);
    if (robot->adresse == 0 && max_prog > 0){
        robot->adresse = (MEM_SIZE / max_prog) * index;
        robot->prog_counter = robot->adresse;
    }
}

corewar_t *init_corewar(int ac, char **av)
{
    corewar_t *corewar = malloc(sizeof(corewar_t));

    if (corewar == NULL)
        return NULL;
    corewar->memory = init_memory();
    corewar->robot_array = get_robot_array(ac, av);
    corewar->nb_live = 0;
    corewar->cycle_to_die = CYCLE_TO_DIE;
    for (int i = 0; corewar->robot_array != NULL
        && corewar->robot_array[i] != NULL; i++){
        init_adresses(corewar->robot_array[i], corewar->robot_array, i);
        if (init_robot_info(corewar->robot_array[i]) == 84){
            free_corewar(corewar);
            return NULL;
        }
        write_instructions_in_memory(corewar->robot_array[i], corewar->memory);
        corewar->robot_array[i]->prog_counter =
            corewar->robot_array[i]->adresse;
    }
    return corewar;
}

void free_corewar(corewar_t *corewar)
{
    for (int i = 0; corewar->robot_array != NULL
        && corewar->robot_array[i] != NULL; i++){
        free(corewar->robot_array[i]);
    }
    if (corewar->robot_array != NULL)
        free(corewar->robot_array);
    if (corewar->memory != NULL)
        free(corewar->memory);
    if (corewar != NULL)
        free(corewar);
}
