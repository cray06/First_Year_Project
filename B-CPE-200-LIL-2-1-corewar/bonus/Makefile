##
## EPITECH PROJECT, 2024
## makefile
## File description:
## makefile for bonus
##

SRC 	=	src/main.c \
			src/game_loop.c \
			src/execution.c \
			../src/op.c \
			../src/init/init.c \
			../src/utilities/read.c \
			../src/utilities/write_bytes.c \
			../src/parsing/array.c \
			../src/parsing/progs.c \
			src/instructions/live.c \
			../src/instructions/st.c \
			../src/instructions/add.c \
			../src/instructions/sub.c \
			../src/instructions/and.c \
			../src/instructions/load.c \
			../src/instructions/or.c \
			../src/instructions/xor.c \
			../src/instructions/ldi.c \
			../src/instructions/sti.c \
			../src/instructions/lld.c \
			../src/instructions/lldi.c \
			../src/instructions/fork.c \
			../src/instructions/lfork.c \
			../src/instructions/aff.c \
			../src/instructions/zjump.c \
			../src/utilities/get_param_size.c \
			../src/parsing/coding_byte.c \
			../lib/my_compute_power_rec.c \
			../lib/my_getnbr.c \
			../lib/my_put_nbr.c \
			../lib/my_strlen.c \
			../lib/my_strcmp.c \
			../lib/my_strncmp.c \
			../lib/my_putchar.c \
			../lib/my_strncpy.c \
			src/visualizer.c

NAME	=	corewar_bonus

INCLUDE = -I./include -I../include

OBJ = $(SRC:.c=.o)

%.o : %.c
	gcc $(INCLUDE) -c -o $@ $<

all: $(OBJ)
	gcc -o $(NAME) $(OBJ) -W -Wall -lncurses

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

debug: fclean
	gcc -g -o $(NAME) $(SRC) $(INCLUDE) -lncurses 