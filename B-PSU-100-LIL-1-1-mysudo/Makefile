##
## EPITECH PROJECT, 2024
## Makefile
## File description:
## Makefile
##

SRC =     main.c \
		parsing.c \
		free.c \
		parsing_bis.c \
		checking_sudoers.c \
		flag_command.c \
		lib/my_strncmp.c \
		lib/my_str_to_word_array.c \
		lib/my_strlen.c \
		lib/my_strdup.c \
		lib/my_strcmp.c \
		lib/my_strncpy.c \
		lib/my_strstr.c \

OBJ =     $(SRC:.c=.o)

NAME =    my_sudo

CFLAGS = -Wall -Wextra

ALL = $(NAME)

$(NAME):    $(OBJ)
	gcc -o $(NAME) $(SRC) -lcrypt

clean:
	rm -f *.o;
	rm -f lib/*.o

fclean:     clean
	rm -f ./$(NAME)

re:    fclean all

all: $(NAME)
