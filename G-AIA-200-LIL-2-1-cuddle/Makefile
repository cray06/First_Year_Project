##
## EPITECH PROJECT, 2024
## makefile
## File description:
## makefile
##

SRC 	=	src/command/read_csv.c \
			src/command/free_csv.c \
			src/command/utilities.c \
			src/command/apply.c \
			src/command/to_type.c \
			src/types/types.c \
			src/types/check_types.c \
			src/types/change_types.c \
			src/types/type_to_type.c \
			src/my_strdup.c \
			src/my_str_to_word_array.c \
			src/my_strlowcase.c \
			src/command/write_csv.c \
			src/command/shape.c \
			src/command/copy.c \
			src/command/copy_head_value.c \
			src/command/head.c \
			src/command/tail.c \
			src/command/info.c \
			src/command/describe.c \
			src/command/filter.c \
			src/command/sorting.c \
			src/command/aggregation.c \
			src/command/aggregation_utilities.c \

NAME	=	libcuddle.a

INCLUDE = ./include/ -lm

OBJ = $(SRC:.c=.o)

%.o : %.c
	gcc -g -I$(INCLUDE) -c -o $@ $<

all: $(OBJ)
	ar rc $(NAME) $(OBJ)
	$(MAKE) clean

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

debug: re
	gcc -g main.c libcuddle.a -lm
