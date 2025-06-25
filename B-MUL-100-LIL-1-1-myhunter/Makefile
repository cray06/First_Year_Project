##
## EPITECH PROJECT, 2024
## Makefile
## File description:
## Makefile
##

SRC =     main.c \
	  src/my_strlen.c \
	  src/my_put_nbr.c \
	  src/my_putchar.c \
	  src/my_strcpy.c \
	  src/my_putstr.c \
	  src/verif_env.c \
	  src/my_strncmp.c \
	  menu.c \
	  button.c \
	  cleanup.c \
	  duck.c \
	  event_handling.c \
	  game_management.c \
	  get_score.c \
	  heart.c \
	  logo.c \
	  lost_screen.c \
	  next_handling.c \
	  next_duck.c \
	  -lcsfml-graphics \
	  -lcsfml-window \
	  -lcsfml-system \
	  -lcsfml-audio \

OBJ =     $(SRC:.c=.o)

NAME =    my_hunter

CFLAGS = -Wall -Wextra

ALL = $(NAME)

$(NAME):    $(OBJ)
	gcc -o $(NAME) $(OBJ)

clean:
	rm -f *.o;
	rm -f src/*.o

fclean:     clean
	rm -f ./$(NAME)

re:    fclean all

debug:
	gcc -o $(NAME) $(SRC) -g

all: $(NAME)
