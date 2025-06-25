##
## EPITECH PROJECT, 2024
## Makefile
## File description:
## Makefile
##

SRC =	main.c \
		add.c \
		disp.c \
		del.c \
		sort.c \
		comp.c \
		my_getnbr.c \
		my_strcmp.c \
		my_strdup.c \
		my_putchar.c \
		my_putstr.c \
		my_strlen.c \
		my_put_nbr.c \

OBJ =     $(SRC:.c=.o)

NAME =    organized

CFLAGS = -Wall -Wextra

ALL = $(NAME)
$(NAME):    $(OBJ)
	gcc -o $(NAME) $(SRC) -L. -lshell

clean:
	rm -f *.o;
	rm -f lib/my/*.o

fclean:     clean
	rm -f ./$(NAME)

re:    fclean all

all: $(NAME)
