/*
** EPITECH PROJECT, 2025
** visualizer.c
** File description:
** Visualizer for Corewar using ncurses
*/

#include <ncurses.h>
#include <unistd.h>
#include "../include/my.h"
#include "../include/visualizer.h"

#define WINDOW_WIDTH 128
#define WINDOW_HEIGHT 64
#define MEMORY_WIDTH 128
#define MEMORY_HEIGHT 64
#define INFO_WIDTH 40
#define INFO_HEIGHT 64
#define BYTES_PER_LINE 32
#define SCROLL_SPEED 8

static WINDOW *memory_win;
static WINDOW *info_win;
static int colors[4] = {COLOR_RED, COLOR_GREEN, COLOR_BLUE, COLOR_YELLOW};
static int scroll_offset = 0;

void init_ncurses(void)
{
    initscr();
    start_color();
    noecho();
    curs_set(0);
    use_default_colors();
    init_pair(1, COLOR_RED, COLOR_BLACK);
    init_pair(2, COLOR_GREEN, COLOR_BLACK);
    init_pair(3, COLOR_BLUE, COLOR_BLACK);
    init_pair(4, COLOR_YELLOW, COLOR_BLACK);
    init_pair(5, COLOR_WHITE, COLOR_BLACK);
    init_pair(6, COLOR_BLACK, COLOR_WHITE);
    keypad(stdscr, TRUE);
    timeout(0);
}

void create_windows(void)
{
    memory_win = newwin(MEMORY_HEIGHT, MEMORY_WIDTH, 0, 0);
    info_win = newwin(INFO_HEIGHT, INFO_WIDTH, 0, MEMORY_WIDTH + 1);
    box(memory_win, 0, 0);
    box(info_win, 0, 0);
    wrefresh(memory_win);
    wrefresh(info_win);
}

void handle_scroll(int key)
{
    int max_scroll = (MEM_SIZE / BYTES_PER_LINE) - (MEMORY_HEIGHT - 2);

    if (key == KEY_UP && scroll_offset > 0) {
        scroll_offset -= SCROLL_SPEED;
        if (scroll_offset < 0)
            scroll_offset = 0;
    } else if (key == KEY_DOWN && scroll_offset < max_scroll) {
        scroll_offset += SCROLL_SPEED;
        if (scroll_offset > max_scroll)
            scroll_offset = max_scroll;
    }
}

void display_memory(corewar_t *corewar)
{
    int x = 1;
    int y = 1;
    int color;
    int current_pc;
    int start_addr = scroll_offset * BYTES_PER_LINE;

    wclear(memory_win);
    box(memory_win, 0, 0);
    
    for (int i = start_addr; i < MEM_SIZE && y < MEMORY_HEIGHT - 1; i += BYTES_PER_LINE) {
        mvwprintw(memory_win, y, 1, "%04x:", i);
        x = 7;
        for (int j = 0; j < BYTES_PER_LINE && (i + j) < MEM_SIZE; j++) {
            color = 5;
            current_pc = i + j;
            
            for (int k = 0; corewar->robot_array[k] != NULL; k++) {
                if (current_pc >= corewar->robot_array[k]->adresse &&
                    current_pc < corewar->robot_array[k]->adresse + corewar->robot_array[k]->prog_size) {
                    color = k + 1;
                    break;
                }
            }
            
            for (int k = 0; corewar->robot_array[k] != NULL; k++) {
                if (current_pc == corewar->robot_array[k]->prog_counter) {
                    wattron(memory_win, COLOR_PAIR(6));
                    mvwprintw(memory_win, y, x, "%02x", (unsigned char)corewar->memory[current_pc]);
                    wattroff(memory_win, COLOR_PAIR(6));
                    x += 3;
                    continue;
                }
            }
            
            wattron(memory_win, COLOR_PAIR(color));
            mvwprintw(memory_win, y, x, "%02x", (unsigned char)corewar->memory[current_pc]);
            wattroff(memory_win, COLOR_PAIR(color));
            x += 3;
        }
        y++;
    }
    wrefresh(memory_win);
}

void display_info(corewar_t *corewar)
{
    int y = 1;

    wclear(info_win);
    box(info_win, 0, 0);
    
    mvwprintw(info_win, y++, 2, "CYCLE: %d", corewar->cycles);
    mvwprintw(info_win, y++, 2, "CYCLE_TO_DIE: %d", corewar->cycle_to_die);
    mvwprintw(info_win, y++, 2, "NBR_LIVE: %d", corewar->nb_live);
    y++;
    
    for (int i = 0; corewar->robot_array[i] != NULL; i++) {
        wattron(info_win, COLOR_PAIR(i + 1));
        mvwprintw(info_win, y++, 2, "Player %d: %s", 
            corewar->robot_array[i]->registers[0],
            corewar->robot_array[i]->name);
        mvwprintw(info_win, y++, 2, "  Lives: %d", corewar->robot_array[i]->in_live);
        mvwprintw(info_win, y++, 2, "  PC: %d", corewar->robot_array[i]->prog_counter);
        mvwprintw(info_win, y++, 2, "  Cycles: %d", corewar->robot_array[i]->cycles);
        wattroff(info_win, COLOR_PAIR(i + 1));
        y++;
    }
    wrefresh(info_win);
}

void cleanup_ncurses(void)
{
    delwin(memory_win);
    delwin(info_win);
    endwin();
}

void visualizer_loop(corewar_t *corewar)
{
    int key;
    init_ncurses();
    create_windows();

    while (!win_condition(corewar)) {
        display_memory(corewar);
        display_info(corewar);
        key = getch();
        if (key == 'q')
            break;
        handle_scroll(key);
        for (int i = 0; corewar->robot_array[i] != NULL; i++) {
            can_be_executed(corewar->robot_array[i], corewar);
        }
        corewar->cycles++;
        usleep(100000);
    }
    cleanup_ncurses();
}
