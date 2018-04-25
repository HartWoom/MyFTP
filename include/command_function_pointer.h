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
	bool	logged;
	char	*login;
	char	*home;
}	command_t;

void	choose_command(command_t *, int);
void	command_user(command_t *);
void	command_pass(command_t *);
void	command_quit(command_t *);
void	command_cwd(command_t *);
void	command_cdup(command_t *);
void	command_dele(command_t *);
void	command_pwd(command_t *);
void	command_pasv(command_t *);
void	command_port(command_t *);
void	command_help(command_t *);
void	command_noop(command_t *);
void	command_retr(command_t *);
void	command_stor(command_t *);
void	command_list(command_t *);

#endif