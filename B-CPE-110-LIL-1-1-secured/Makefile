##
## EPITECH PROJECT, 2024
## Makefile
## File description:
## Makefile
##

SRC =	hash.c \
		error_handling.c \
		hashtable_base.c \
		ht_dump.c \
		ht_insert.c \
		ht_search.c \
		ht_delete.c \
		lib/my_getnbr.c \
		lib/my_put_nbr.c \
		lib/my_putstr.c \
		lib/my_strlen.c \
		lib/my_putchar.c \
		lib/my_strdup.c \

OBJ =     $(SRC:.c=.o)

NAME =    libhashtable.a

CFLAGS = -Wall -Wextra

ALL = $(NAME)
$(NAME):    $(OBJ)
	ar rc $(NAME) $(OBJ)

clean:
	rm -f $(OBJ)

fclean:     clean
	rm -f $(OBJ)

re:    fclean all

all: $(NAME)
