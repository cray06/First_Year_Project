##
## EPITECH PROJECT, 2024
## makefile
## File description:
## makefile
##

SRC 	=	src/my_str_to_word_array.c \
			src/my_strlen.c \
			src/my_strcat.c \
			src/my_strcpy.c \
			src/my_strncpy.c \
			src/my_strdup.c \
			src/my_strncmp.c \
			src/my_strcmp.c \
			src/my_str_is_number.c \
			src/my_compute_power_rec.c \
			src/main.c \
			src/list.c \
			src/header.c \
			src/op.c \
			src/line.c \
			src/file.c \
			src/binaire.c \
			src/global_write.c \
			src/my_getnbr.c \
			src/is_number.c \
			src/value_parsing.c \

NAME	=	asm

INCLUDE = ./include/

OBJ = $(SRC:.c=.o)

%.o : %.c
	gcc -I$(INCLUDE) -c -o $@ $<

all: $(OBJ)
	gcc -o $(NAME) $(OBJ) -W -Wall

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

debug: fclean
	gcc -g -o $(NAME) $(SRC) -I$(INCLUDE)
