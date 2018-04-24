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
#include "command_function_pointer.h"

static char *commandTable[] = {"USER", "PASS", "QUIT", "CWD", "CDUP", "DELE",
"PWD", "PASV", "PORT", "HELP", "NOOP", "RETR", "STOR", "LIST"};

void	process_command(command_t *commandInfo,
	int clientSocket, char *command, bool *logged)
{
	int	index = 0;

	if (strlen(command) < 2)
		return;
	while (commandTable[index] != NULL){
		if (strcasecmp(commandTable[index],
			strtok(strdup(command), " \n")) == 0)
		{
			printf("Command received (%s)\n", commandTable[index]);
			commandInfo->usefullString = strdup(command);
			commandInfo->clientSocket = clientSocket;
			commandInfo->logged = logged;
			choose_command(commandInfo, index);
			return;
		}
		index += 1;
	}
}

void	choose_command(command_t *commandInfo, int index)
{
	void	(*command[3])(command_t *);

	command[0] = &command_user;
	command[1] = &command_pass;
	command[2] = &command_quit;
	command[index] (commandInfo);
}