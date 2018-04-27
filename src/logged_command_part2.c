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
}

void	command_stor(command_t *commandInfo)
{
	if (!commandInfo->logged){
		dprintf(commandInfo->clientSocket, "530 Please login with USER"
			" and PASS.\n");
		return;
	}
}