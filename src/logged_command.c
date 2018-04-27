/*
** EPITECH PROJECT, 2018
** myftp
** File description:
** some of the logged command
*/

#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#include "command_function_pointer.h"

void	command_cwd_part2(command_t *commandInfo,
	char *newPath, char *oldPath)
{
	char	*buff = malloc(sizeof(char) * 1024);

	if (newPath == NULL)
		dprintf(commandInfo->clientSocket, "501 Specify path.\n");
	else if (chdir(newPath) == -1)
		dprintf(commandInfo->clientSocket, "501 Path incorrect.\n");
	else if (strncmp(getcwd(buff, 1024), commandInfo->home,
		strlen(commandInfo->home)) != 0){
		dprintf(commandInfo->clientSocket, "501 Path incorrect.\n");
	chdir(oldPath);
}
else
	dprintf(commandInfo->clientSocket, "250 Succesfully change working"
		" directory.\n");
}

void	command_cwd(command_t *commandInfo)
{
	char	*oldPath = malloc(sizeof(char) * 1024);
	char	*newPath;

	if (!commandInfo->logged){
		dprintf(commandInfo->clientSocket, "530 Please login with USER"
			" and PASS.\n");
		return;
	}
	oldPath = getcwd(oldPath, 1024);
	strtok(commandInfo->usefullString, " \r\n");
	newPath = strdup(strtok(NULL, "\r\n"));
	command_cwd_part2(commandInfo, newPath, oldPath);
}

void	command_cdup(command_t *commandInfo)
{
	char	*buff = malloc(sizeof(char) * 1024);

	if (!commandInfo->logged)
		dprintf(commandInfo->clientSocket, "530 Please login with USER"
			" and PASS.\n");
	if (strlen(getcwd(buff, 1024)) == strlen(commandInfo->home))
		dprintf(commandInfo->clientSocket, "550 Requested action not"
			" taken.\nYou may not have permission.\n");
	else if (chdir("..") == -1)
		dprintf(commandInfo->clientSocket, "550 Failed to change"
			" directory.\n");
	else
		dprintf(commandInfo->clientSocket, "200 Succesfully changed"
			" directory.\n");
}

void	command_dele(command_t *commandInfo)
{
	char	*file;
	if (!commandInfo->logged){
		dprintf(commandInfo->clientSocket, "530 Please login with USER"
			" and PASS.\n");
		return;
	}
	strtok(commandInfo->usefullString, " \n\r");
	file = strtok(NULL, "\n\r");
	if (file == NULL)
		dprintf(commandInfo->clientSocket, "501 Please specify the"
			" file path.\n");
	if (remove(file) == -1)
		dprintf(commandInfo->clientSocket, "550 File not found.\n");
	else
		dprintf(commandInfo->clientSocket, "250 File has been"
			" deleted.\n");
}

void	command_pwd(command_t *commandInfo)
{
	char	*buff = malloc(sizeof(char) * 1024);

	if (commandInfo->logged){
		buff = getcwd(buff, 1024);
		if (strlen(buff) > strlen(commandInfo->home))
			dprintf(commandInfo->clientSocket, "257 \"%s\"\n",
				buff + strlen(commandInfo->home));
		else
			dprintf(commandInfo->clientSocket, "257 \"/\"\n");
	}
	else
		dprintf(commandInfo->clientSocket, "530 Please login with USER"
			" and PASS.\n");
}