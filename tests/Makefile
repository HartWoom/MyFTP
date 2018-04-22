##
## EPITECH PROJECT, 2018
## myftp
## File description:
## unit tests makefile
##

SRC	:=	setup.c	\
		ut_handle_error.c	\
		ut_is_numerical.c

OBJ	:=	$(SRC:.c=.o)

NAME	:=	tests_run

CC	:=	gcc

RM	:=	rm -rf

CFLAGS	:=	--coverage -W -Wall -Wextra -pedantic -Iinclude -lcriterion -ldl

all:	$(NAME)

$(NAME):	$(OBJ)
	$(CC) $(OBJ) -o $(NAME) $(CFLAGS)

clean:
	$(RM) $(OBJ)

fclean:	clean
	$(RM) $(NAME)

re:	fclean all