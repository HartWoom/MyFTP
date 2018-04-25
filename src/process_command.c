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
	int clientSocket, char *command)
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
			choose_command(commandInfo, index);
			return;
		}
		index += 1;
	}
}

void	choose_command(command_t *commandInfo, int index)
{
	void	(*command[14])(command_t *);

	command[0] = &command_user;
	command[1] = &command_pass;
	command[2] = &command_quit;
	command[3] = &command_cwd;
	command[4] = &command_cdup;
	command[5] = &command_dele;
	command[6] = &command_pwd;
	command[7] = &command_pasv;
	command[8] = &command_port;
	command[9] = &command_help;
	command[10] = &command_noop;
	command[11] = &command_retr;
	command[12] = &command_stor;
	command[13] = &command_list;
	command[index] (commandInfo);
}