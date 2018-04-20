##
## EPITECH PROJECT, 2018
## myftp
## File description:
## makefile
##

SRC	:=	$(addprefix src/,	\
		main.c	\
		server.c	\
		utils.c)

OBJ	:=	$(SRC:.c=.o)

NAME	:=	server

CC	:=	gcc $(CFLAGS)

RM	:=	rm -rf

CPPFLAGS	:=	-W -Wall -Wextra -pedantic -Iinclude

DEFAULT	:=	"\033[00;0m"

GREEN	:=	"\033[0;32;1m"

RED	:=	"\033[0;31;1m"

all:	$(NAME)

$(NAME):	$(OBJ)
	$(CC) $(OBJ) -o $(NAME) && \
		echo -e $(GREEN)"[BIN]"$(CYAN) $(NAME)$(DEFAULT) || \
		echo -e $(RED)"[XX]"$(DEFAULT) $(NAME)

clean:
	$(RM) $(OBJ)

fclean:	clean
	$(RM) $(NAME)

re:	fclean all

.PHONY:	all clean fclean re

.SILENT: all $(NAME) clean fclean re

.c.o:
	@$(CC) -c $< -o $@ $(CFLAGS) $(foreach dir, include, -I$(dir)) && \
		echo -e $(GREEN)"[OK]"$(DEFAULT) $< || \
		echo -e $(RED)"[KO]"$(DEFAULT) $<