#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>
#include "asm.h"
#include "op.h"

int swap_endian(int num) {
    return ((num >> 24) & 0xff) |
        ((num << 8) & 0xff0000) |
        ((num >> 8) & 0xff00) |
        ((num << 24) & 0xff000000);
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <champion_file>\n", argv[0]);
        return 84;
    }
    int fd = open(argv[1], O_RDONLY);
    if (fd == -1) {
        perror("Cannot open file");
        return 84;
    }
    header_t header;
    if (read(fd, &header, sizeof(header_t)) != sizeof(header_t)) {
        perror("Error reading header");
        close(fd);
        return 84;
    }
    int swapped_magic = swap_endian(header.magic);
    int actual_magic = swapped_magic & 0x00FFFFFF;
    if (actual_magic != COREWAR_EXEC_MAGIC) {
        fprintf(stderr, "Error: Invalid magic number\n");
        close(fd);
        return 84;
    }
    int corrected_size = swap_endian(header.prog_size);
    printf("Champion name: %s\n", header.prog_name);
    printf("Description: %s\n", header.comment);
    printf("Code size: %d bytes\n", corrected_size);
    close(fd);
    return 0;
}