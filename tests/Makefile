##
## EPITECH PROJECT, 2018
## myftp
## File description:
## unit tests makefile
##

SRC	:=	setup.c	\
		ut_handle_error.c	\
		ut_is_numerical.c

PROJECT_SRC	:=	$(addprefix ../src/,	\
			handle_error.c	\
			server.c	\
			utils.c)

OBJ	:=	$(SRC:.c=.o)

NAME	:=	tests_run

CC	:=	gcc

LIB_COMPIL	:=	gcc -W -Wall -Wextra -pedantic -I../include

RM	:=	rm -rf

CFLAGS	:=	--coverage -W -Wall -Wextra -pedantic -Iinclude -lcriterion -ldl

DEFAULT	:=	"\033[00;0m"

GREEN	:=	"\033[0;32;1m"

RED	:=	"\033[0;31;1m"

all:	$(NAME)

$(NAME):	$(OBJ)
	$(LIB_COMPIL) -shared -fpic $(PROJECT_SRC) -o libserver.so
	$(CC) $(OBJ) -o $(NAME) $(CFLAGS)

clean:
	$(RM) $(OBJ)
	$(RM) *.gcno
	$(RM) *.gcda

fclean:	clean
	$(RM) $(NAME)
	$(RM) libserver.so

re:	fclean all

.PHONY:	all clean fclean re

.SILENT: all $(NAME) clean fclean re

.c.o:
	@$(CC) -c $< -o $@ $(CFLAGS) $(foreach dir, include, -I$(dir)) && \
		echo -e $(GREEN)"[OK]"$(DEFAULT) $< || \
		echo -e $(RED)"[KO]"$(DEFAULT) $<