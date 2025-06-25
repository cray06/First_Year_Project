##
## EPITECH PROJECT, 2024
## Makefile
## File description:
## Makefile
##

SRC =     main.c \
	  parsing.c \
	  directory_manage.c \
	  printing_file.c \
	  sorting.c \
	  my_putstr.c \
	  my_putchar.c \
	  my_strdup.c \
	  my_strchr.c \
	  my_strlen.c \
	  printing_file_l.c \
	  my_strncpy.c \
	  my_strcat.c \
	  my_strcpy.c \
	  my_put_nbr.c \
	  parsing_checker.c \

OBJ =     $(SRC:.c=.o)

NAME =    my_ls

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

all: $(NAME)
