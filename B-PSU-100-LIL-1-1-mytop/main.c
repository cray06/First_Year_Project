/*
** EPITECH PROJECT, 2024
** main.c
** File description:
** main.c
*/

#include "include/my.h"

void parse_args(int argc, char *argv[], float *delay)
{
    for (int i = 1; i < argc; i++) {
        if (strcmp(argv[i], "-d") == 0 && i + 1 < argc) {
            *delay = atof(argv[i + 1]);
            i++;
        }
    }
}

void setup_screen(void)
{
    initscr();
    noecho();
    cbreak();
    curs_set(0);
    nodelay(stdscr, TRUE);
}

void handle_delay(float delay)
{
    int ch;

    for (int i = 0; i < (int)(delay * 10); i++) {
        usleep(100000);
        ch = getch();
        if (ch == 'q') {
            endwin();
            exit(0);
        }
    }
}

void main_loop(float delay)
{
    int ch;

    while (1) {
        clear();
        print_top();
        print_processes();
        refresh();
        ch = getch();
        if (ch == 'q') {
            endwin();
            return;
        }
        handle_delay(delay);
    }
}

int main(int argc, char *argv[])
{
    float delay = 3.0;

    parse_args(argc, argv, &delay);
    setup_screen();
    main_loop(delay);
    endwin();
    return 0;
}
