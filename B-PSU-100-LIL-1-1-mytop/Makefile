##
## EPITECH PROJECT, 2024
## Makefile
## File description:
## Makefile
##

SRC =     main.c \
		first_line.c \
		printing_time.c \
		header_info.c \
		printing_type.c \
		second_line.c \
		third_line.c \
		fourth_line.c \
		fourth_line_calc.c \
		fifth_line.c \
		body_info.c \
		body_parsing.c \
		body_read.c \
		get_user.c \

OBJ =     $(SRC:.c=.o)

NAME =    my_top

CFLAGS = -Wall -Wextra

ALL = $(NAME)

$(NAME):    $(OBJ)
	gcc -o $(NAME) $(SRC) -l ncurses

clean:
	rm -f *.o;
	rm -f lib/my/*.o

fclean:     clean
	rm -f ./$(NAME)

re:    fclean all

all: $(NAME)
