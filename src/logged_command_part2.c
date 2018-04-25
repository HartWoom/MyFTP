/*
** EPITECH PROJECT, 2018
** myftp
** File description:
** [file description here]
*/

#include <stdio.h>
#include "command_function_pointer.h"

void	command_port(command_t *commandInfo)
{
	(void) commandInfo;
}

void	command_help(command_t *commandInfo)
{
	if (commandInfo->logged == true)
		dprintf(commandInfo->clientSocket, "214-The following commands are"
			" recognized.\n USER PASS QUIT CWD CDUP DELE PWD PASV PORT"
			" HELP NOOP RETR STOR LIST\n214 Help OK.\n");
	else
		dprintf(commandInfo->clientSocket, "530 Please login with USER"
			" and PASS.\n");	
}

void	command_noop(command_t *commandInfo)
{
	if (commandInfo->logged == true)
		dprintf(commandInfo->clientSocket, "200 NOOP ok.\n");
	else
		dprintf(commandInfo->clientSocket, "530 Please login with USER"
			" and PASS.\n");
}

void	command_retr(command_t *commandInfo)
{
	(void) commandInfo;
}

void	command_stor(command_t *commandInfo)
{
	(void) commandInfo;
}

void	command_list(command_t *commandInfo)
{
	(void) commandInfo;
}