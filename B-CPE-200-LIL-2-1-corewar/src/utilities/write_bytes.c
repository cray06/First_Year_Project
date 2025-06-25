/*
** EPITECH PROJECT, 2025
** write_bytes.c
** File description:
** Functions to write bytes to memory
*/

#include "my.h"

void write_4_bytes(char *memory, int value, int address)
{
    memory[address] = (value >> 24) & 0xFF;
    memory[(address + 1) % MEM_SIZE] = (value >> 16) & 0xFF;
    memory[(address + 2) % MEM_SIZE] = (value >> 8) & 0xFF;
    memory[(address + 3) % MEM_SIZE] = value & 0xFF;
}
