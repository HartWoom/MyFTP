/*
** EPITECH PROJECT, 2018
** myftp
** File description:
** some of the logged command
*/

#include <string.h>
#include <unistd.h>
#include <stdio.h>
#include <sys/wait.h>
#include <sys/socket.h>
#include "command_function_pointer.h"

void	command_list_part2(command_t *commandInfo)
{
	char	*arg;
	int	oldFd;
	int	pid;

	strtok(commandInfo->usefullString, " \n\r");
	dprintf(commandInfo->clientSocket, "150 Here comes the"
		" directory listing.\n");
	arg = strtok(NULL, "\n\r");
	oldFd = dup(1);
	dup2(commandInfo->dataSocket, 1);
	pid = fork();
	if (pid == 0)
		execl("/bin/ls", "ls", "-l", arg, NULL);
	else
		waitpid(pid, 0, WSTOPPED);
	dup2(oldFd, 1);
	shutdown(commandInfo->dataSocket, SHUT_RDWR);
	commandInfo->dataSocket = -1;
	dprintf(commandInfo->clientSocket, "226 Directory send OK.\n");
}

void	command_list(command_t *commandInfo)
{
	if (!commandInfo->logged){
		dprintf(commandInfo->clientSocket, "530 Please login with USER"
			" and PASS.\n");
		return;
	}
	if (commandInfo->dataSocket == -1){
		dprintf(commandInfo->clientSocket, "450 Requested file action"
			" not taken. No data connection.\n");
		return;
	}
	command_list_part2(commandInfo);
}