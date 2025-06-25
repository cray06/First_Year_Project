##
## EPITECH PROJECT, 2024
## Makefile
## File description:
## Makefile
##

SRC =     main.c \
		parsing.c \
		signal_checking.c \
		cd.c \
		exec.c \
		src/env_func/env_func_bis.c \
		src/env_func/env_func.c \
		src/env_func/setenv.c \
		src/env_func/unset_env.c \
		lib/my/my_str_to_word_array.c \
		lib/my/my_strlen.c \
		lib/my/my_put_nbr.c \
		lib/my/my_putchar.c \
		lib/my/my_putstr.c \
		lib/my/my_strncmp.c \
		lib/my/my_strcmp.c \
		lib/my/my_strstr.c \
		lib/my/my_strcat.c \
		lib/my/my_strdup.c \
		lib/my/free_word_array.c \
		lib/my/my_strcpy.c \

OBJ =     $(SRC:.c=.o)

NAME =    mysh

CFLAGS = -Wall -Wextra -I./include

ALL = $(NAME)

$(NAME):    $(OBJ)
	gcc -o $(NAME) $(SRC) $(CFLAGS) -g

clean:
	rm -f *.o;
	rm -f lib/my/*.o
	rm -f src/env_func/*.o

fclean:     clean
	rm -f ./$(NAME)

re:    fclean all

all: $(NAME)
