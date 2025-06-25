/*
** EPITECH PROJECT, 2025
** coding_byte
** File description:
** coding_byte
*/

#include "my.h"

char *get_int_to_bin(int value)
{
    char *bin = malloc(sizeof(char) * 9);

    if (bin == NULL)
        return NULL;
    bin[8] = '\0';
    for (int i = 7; i >= 0; i--){
        if (value % 2 == 1){
            bin[i] = '1';
            value--;
        } else
            bin[i] = '0';
        value = value / 2;
    }
    return bin;
}

static void edit_type_array(args_type_t *types, char *bin)
{
    for (int i = 0; i < 4; i++){
        if (!my_strncmp(bin + (i * 2), "11", 2))
            types[i] = T_IND;
        if (!my_strncmp(bin + (i * 2), "00", 2))
            types[i] = 0;
        if (!my_strncmp(bin + (i * 2), "10", 2))
            types[i] = T_DIR;
        if (!my_strncmp(bin + (i * 2), "01", 2))
            types[i] = T_REG;
    }
    free(bin);
}

args_type_t *get_coding_byte(robot_t *robot, unsigned char *memory)
{
    args_type_t *types;
    char *bin;

    bin = get_int_to_bin(memory[robot->prog_counter + 1]);
    if (bin == NULL)
        return NULL;
    types = malloc(sizeof(args_type_t) * 4);
    if (types == NULL)
        return NULL;
    edit_type_array(types, bin);
    return types;
}
