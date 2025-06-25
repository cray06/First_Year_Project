##
## EPITECH PROJECT, 2024
## Makefile
## File description:
## Makefile
##

SRC =     settingup.c \
	  map_information.c \
	  map_parsing.c \
	  map_route.c \
	  my_getnbr.c \
	  my_strncpy.c \
	  my_putstr.c \
	  my_putchar.c \
	  my_strlen.c \
	  my_strchr.c \
	  error_handling.c \

OBJ =     $(SRC:.c=.o)

NAME =    setting_up

CFLAGS = -Wall -Wextra

ALL = $(NAME)

$(NAME):    $(OBJ)
	gcc -o $(NAME) $(SRC)

clean:
	rm -f *.o;
	rm -f lib/my/*.o

fclean:     clean
	rm -f ./$(NAME)

re:    fclean all

debug:
	gcc -o $(NAME) $(SRC) -g

all: $(NAME)
