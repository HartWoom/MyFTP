/*
** EPITECH PROJECT, 2018
** myftp
** File description:
** declaration of all the function for the function pointer table
*/

#ifndef COMMAND_FUNCTION_POINTER_H_
# define COMMAND_FUNCTION_POINTER_H_

# include <stdbool.h>

typedef struct	command
{
	char	*usefullString;
	int	clientSocket;
	bool	*logged;
	char	*login;
}	command_t;

void	choose_command(command_t *, int);
void	command_user(command_t *);
void	command_pass(command_t *);
void	command_quit(command_t *);

#endif