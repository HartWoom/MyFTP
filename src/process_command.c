/*
** EPITECH PROJECT, 2018
** myftp
** File description:
** function declaration for command processing
*/

#include <unistd.h>
#include <strings.h>
#include <string.h>
#include <stdio.h>

static char *unloged_command[] = {"USER", "PASS", "QUIT"};
static char *loged_command[] = {"CWD", "CDUP", "DELE", "PWD", "PASV", "PORT",
"HELP", "NOOP", "RETR", "STOR", "LIST"};

void	process_logged_command(int clientSocket, char *command)
{
	(void)clientSocket;
	(void)command;
}

void	process_unlogged_command(int clientSocket, char *command)
{
	int	index = 0;

	while (unloged_command[index] != NULL){
		if (strcasecmp(unloged_command[index],
			strtok(command, " \n")) == 0)
		{
			printf("Command received (%s)\n", unloged_command[index]);
			return;
		}
		index += 1;
	}
}