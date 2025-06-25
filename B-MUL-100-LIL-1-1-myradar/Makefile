##
## EPITECH PROJECT, 2024
## Makefile
## File description:
## Makefile
##

SRC =     main.c \
	  parse.c \
	  parse_bis.c \
	  nbr_element.c \
	  game.c \
	  game_bis.c \
	  tower.c \
	  plane.c \
	  plane_bis.c \
	  quadtree.c \
	  quadtree_bis.c \
	  init.c \
	  plane_coll.c \
	  plane_coll_bis.c \
	  destroy.c \
	  error_handling.c \
	  src/my_strlen.c \
	  src/my_put_nbr.c \
	  src/my_putchar.c \
	  src/my_strcpy.c \
	  src/my_putstr.c \
	  src/verif_env.c \
	  src/my_strncmp.c \
	  src/my_str_to_word_array.c \
	  src/my_getnbr.c \
	  src/my_is_digit.c \
	  src/int_to_str.c \
	  -lcsfml-graphics \
	  -lcsfml-window \
	  -lcsfml-system \
	  -lcsfml-audio \
	  -lm \

OBJ =     $(SRC:.c=.o)

NAME =    my_radar

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
