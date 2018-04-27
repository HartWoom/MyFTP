##
## EPITECH PROJECT, 2018
## myftp
## File description:
## makefile
##

SRC	:=	$(addprefix src/,	\
		main.c	\
		handle_error.c	\
		server.c	\
		process_command.c	\
		unlogged_command.c	\
		logged_command.c	\
		logged_command_part2.c	\
		logged_command_part3.c	\
		logged_command_part4.c	\
		logged_command_part5.c	\
		utils.c)

OBJ	:=	$(SRC:.c=.o)

NAME	:=	server
##NAME	:=	libserver.so

CC	:=	gcc

RM	:=	rm -rf

CFLAGS	:=	-W -Wall -Wextra -pedantic -Iinclude
##CFLAGS	:=	-fpic -W -Wall -Wextra -Iinclude

DEFAULT	:=	"\033[00;0m"

GREEN	:=	"\033[0;32;1m"

RED	:=	"\033[0;31;1m"

all:	$(NAME)

tests_run:
	+$(MAKE) -C tests

$(NAME):	$(OBJ)
	$(CC) $(CFLAGS) $(OBJ) -o $(NAME) && \
		echo -e $(GREEN)"[BIN]"$(CYAN) $(NAME)$(DEFAULT) || \
		echo -e $(RED)"[XX]"$(DEFAULT) $(NAME)

clean:
	$(RM) $(OBJ)

fclean:	clean
	$(RM) $(NAME)

re:	fclean all

.PHONY:	all clean fclean re tests_run

.SILENT: all $(NAME) clean fclean re tests_run

.c.o:
	@$(CC) -c $< -o $@ $(CFLAGS) $(foreach dir, include, -I$(dir)) && \
		echo -e $(GREEN)"[OK]"$(DEFAULT) $< || \
		echo -e $(RED)"[KO]"$(DEFAULT) $<