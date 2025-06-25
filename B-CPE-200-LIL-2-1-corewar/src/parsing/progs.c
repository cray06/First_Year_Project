/*
** EPITECH PROJECT, 2025
** progs
** File description:
** progs
*/

#include "my.h"

static int is_valid_file(char *filename)
{
    FILE *file = fopen(filename, "r");

    if (file == NULL)
        return 0;
    fclose(file);
    return 1;
}

int *get_progs_index(int ac, char **av)
{
    int *progs_index = NULL;

    for (int i = 1; i < ac; i++){
        if (av[i][0] != '-' &&
            ((i > 1 && av[i - 1][0] != '-') || i <= 1)
            && is_valid_file(av[i])){
            progs_index = add_index_in_array(progs_index, i);
        }
    }
    return progs_index;
}

int get_flag_value(int ac, char **av, char *flag)
{
    for (int i = 0; i < ac; i++){
        if (!my_strcmp(av[i], flag) && i + 1 < ac && av[i + 1][0] != '-')
            return my_getnbr(av[i + 1]);
    }
    return -1;
}

int *get_flags_index(int ac, char **av, char *flag)
{
    int *flags_index = NULL;

    for (int i = 1; i < ac; i++){
        if (i > 1 && !my_strcmp(av[i - 1], flag))
            flags_index = add_index_in_array(flags_index, i);
    }
    return flags_index;
}

static int set_prog_number(int *numbers_array)
{
    static int number = 0;
    int return_value;

    while (is_in_array(numbers_array, number)){
        number++;
    }
    return_value = number;
    number++;
    return return_value;
}

robot_t *set_new_robot(int *index, int *numbers_array, char **av)
{
    robot_t *new_robot = malloc(sizeof(robot_t));

    if (new_robot == NULL)
        return NULL;
    new_robot->file = fopen(av[index[0]], "r");
    new_robot->cycles = 0;
    if (index[1] < 0){
        new_robot->registers[0] = set_prog_number(numbers_array);
    } else
        new_robot->registers[0] = my_getnbr(av[index[1]]);
    new_robot->adresse = index[2] >= 0 ? my_getnbr(av[index[2]]) %
        MEM_SIZE : 0;
    new_robot->in_live = CYCLE_TO_DIE;
    new_robot->prog_counter = 0;
    return new_robot;
}

robot_t **get_robot_array(int ac, char **av)
{
    int *progs = get_progs_index(ac, av);
    int *addresses = get_flags_index(ac, av, "-a");
    int *numbers = get_flags_index(ac, av, "-n");
    robot_t **robot_array = malloc(sizeof(robot_t *) *
        (get_len_index_array(progs) + 1));
    int i = 0;
    int index[3];

    for (; robot_array != NULL && progs != NULL && progs[i] != -1; i++){
        index[0] = progs[i];
        index[1] = get_len_index_array(numbers) > i ? numbers[i] : -1;
        index[2] = get_len_index_array(addresses) > i ? addresses[i] : -1;
        robot_array[i] = set_new_robot(index, numbers, av);
    }
    if (robot_array != NULL)
        robot_array[i] = NULL;
    free(progs);
    free(addresses);
    free(numbers);
    return robot_array;
}
