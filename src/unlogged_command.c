/*
** EPITECH PROJECT, 2018
** myftp
** File description:
** definition of the unlogged command
*/

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <sys/socket.h>
#include <string.h>
#include "command_function_pointer.h"

void	command_user(command_t *commandInfo)
{
	char	*login;

	strtok(commandInfo->usefullString, " ");
	login = strtok(NULL, "\n\r");
	if (commandInfo->logged == true){
		dprintf(commandInfo->clientSocket, "530 Can't change from"
			" guest user.\n");
		return;
	}
	if (login == NULL)
		commandInfo->login = NULL;
	else{
		commandInfo->login = malloc(sizeof(char) * strlen(login) + 1);
		commandInfo->login = strdup(login);
	}
	dprintf(commandInfo->clientSocket, "331 Please specify"
		" the password.\n");
}

void	command_pass(command_t *commandInfo)
{
	char	*password;

	if (commandInfo->logged == true){
		dprintf(commandInfo->clientSocket, "230 Already logged in.\n");
		return;
	}
	strtok(commandInfo->usefullString, " ");
	password = strtok(NULL, "\r\n");
	if (strcmp(commandInfo->login, "Anonymous") == 0 && password == NULL){
		dprintf(commandInfo->clientSocket, "230 Login succesful.\n");
		commandInfo->logged = true;
		printf("Login succesful\n");
	}
	else{
		dprintf(commandInfo->clientSocket, "530 Login incorrect.\n");
		printf("Failed login\n");
	}
}

void	command_quit(command_t *commandInfo)
{
	dprintf(commandInfo->clientSocket, "221 Goodbye\n");
	shutdown(commandInfo->clientSocket, SHUT_RDWR);
}

