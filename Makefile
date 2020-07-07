##
## EPITECH PROJECT, 2019
## Makefile
## File description:
## Makefile
##

CC	=	gcc

NAME	=	FASTAtools

CFLAGS	=	-Werror -Wpedantic -Iinc -g  -fno-stack-protector

SRC	=	$(shell find src/ -name '*.c')\
		$(shell find lib/ -name '*.c')\
		main.c

OBJ	=	$(SRC:.c=.o)

all:	$(NAME) clean

$(NAME):	$(OBJ)
	$(CC) -o $(NAME) $(OBJ) $(CFLAGS)

clean:
		rm -f $(OBJ)
		rm -f *~ src/*~ include/*~ core/*~

fclean: clean
		rm -f $(NAME)
		rm -f a.out src/a.out core/a.out
		rm -rf test

re: fclean all

.PHONY:	fclean	clean	re
