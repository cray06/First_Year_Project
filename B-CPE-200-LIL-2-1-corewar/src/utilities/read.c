/*
** EPITECH PROJECT, 2025
** read
** File description:
** read
*/

#include "my.h"

int read_direct_value(char *memory, int index)
{
    int result = 0;
    int puissance = 0;

    for (int i = 3; i >= 0; i--){
        result += memory[index + i] * my_compute_power_rec(256, puissance);
        puissance++;
    }
    return result;
}

int read_indirect_value(char *memory, int index)
{
    int result = 0;
    int puissance = 0;

    result = memory[index + 1];
    return result;
}

int read_register_value(robot_t *robot, int reg)
{
    return robot->registers[reg];
}

void print_memory(char *memory)
{
    for (int i = 0; i < MEM_SIZE; i++){
        my_put_nbr((int){memory[i]});
        if (i + 1 < MEM_SIZE)
            write(1, " ", 1);
    }
    write(1, "\n", 1);
}

int swap_bytes(int value)
{
    return ((value & 0xFF000000) >> 24) |
        ((value & 0x00FF0000) >> 8) |
        ((value & 0x0000FF00) << 8) |
        ((value & 0x000000FF) << 24);
}
