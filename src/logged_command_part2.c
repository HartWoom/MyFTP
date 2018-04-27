/*
** EPITECH PROJECT, 2018
** myftp
** File description:
** some of the logged command
*/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "command_function_pointer.h"

void	command_port(command_t *commandInfo)
{
	if (!commandInfo->logged){
		dprintf(commandInfo->clientSocket, "530 Please login with USER"
			" and PASS.\n");
		return;
	}
	dprintf(commandInfo->clientSocket, "502 Command not implemented.\n");
}

void	command_noop(command_t *commandInfo)
{
	if (commandInfo->logged)
		dprintf(commandInfo->clientSocket, "200 NOOP ok.\n");
	else
		dprintf(commandInfo->clientSocket, "530 Please login with USER"
			" and PASS.\n");
}

void	command_retr(command_t *commandInfo)
{
	if (!commandInfo->logged){
		dprintf(commandInfo->clientSocket, "530 Please login with USER"
			" and PASS.\n");
		return;
	}
	dprintf(commandInfo->clientSocket, "502 Command not implemented.\n");
}

void	command_stor(command_t *commandInfo)
{
	if (!commandInfo->logged){
		dprintf(commandInfo->clientSocket, "530 Please login with USER"
			" and PASS.\n");
		return;
	}
	dprintf(commandInfo->clientSocket, "502 Command not implemented.\n");
}

void	command_help(command_t *commandInfo)
{
	if (commandInfo->logged)
		dprintf(commandInfo->clientSocket, "214-The following commands"
			" are recognized.\n USER PASS QUIT CWD CDUP DELE PWD"
			" PASV PORT HELP NOOP RETR STOR LIST\n214 Help OK.\n");
	else
		dprintf(commandInfo->clientSocket, "530 Please login with USER"
			" and PASS.\n");
}