/*
** EPITECH PROJECT, 2018
** myftp
** File description:
** server functions definition
*/

#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <dirent.h>
#include <stdbool.h>
#include <stdio.h>
#include "serverStruct.h"
#include "process_command.h"
#include "utils.h"
#include "command_function_pointer.h"

int     check_ano_path(server_t *serverInfo, char *anoPath)
{
	DIR     *directory = opendir(anoPath);

	if (directory == NULL)
		return (84);
	serverInfo->anonymousPath = strdup(anoPath);
	closedir(directory);
	return (0);
}

void	handle_client(int clientSocket)
{
	FILE	*stream = fdopen(clientSocket, "r+");
	char	*buff = NULL;
	size_t	len = 0;
	command_t	commandInfo;

	commandInfo.logged = false;
	if (stream == NULL)
		exit(84);
	printf("New client\n");
	dprintf(clientSocket, "220 Welcome\n");
	while (getline(&buff, &len, stream) > 0)
		process_command(&commandInfo, clientSocket, buff);
	printf("Client leaved\n");
	dprintf(clientSocket, "221 Goodbye\n");
	exit(0);
}

int	loop_server(server_t *serverInfo)
{
	int	clientSocket;
	socklen_t	clientAddressSize = sizeof(struct sockaddr_in);
	struct sockaddr_in	clientAddress;
	int	pid;

	while (serverInfo->isOn){
		clientSocket = accept(serverInfo->socket,
			(struct sockaddr *) &clientAddress,
			&clientAddressSize);
		if (clientSocket == -1)
			continue;
		pid = fork();
		if (pid == -1)
			continue;
		if (pid == 0)
			handle_client(clientSocket);
	}
	return (0);
}

int     init_server(server_t *serverInfo, char **argv)
{
	int myTrue = 1;

	serverInfo->socket = socket(AF_INET, SOCK_STREAM, 0);
	if (serverInfo->socket == -1)
		return (84);
	if (check_ano_path(serverInfo, argv[2]) == 84)
		return (84);
	memset(&serverInfo->address, 0, sizeof(struct sockaddr_in));
	serverInfo->address.sin_family = AF_INET;
	serverInfo->address.sin_port = htons(atoi(argv[1]));
	serverInfo->address.sin_addr.s_addr = INADDR_ANY;
	setsockopt(serverInfo->socket, SOL_SOCKET, SO_REUSEADDR, &myTrue,
		sizeof(int));
	if (bind(serverInfo->socket, (struct sockaddr *)&serverInfo->address,
		sizeof(struct sockaddr_in)) == -1)
		return (84);
	if (listen(serverInfo->socket, 42) == -1)
		return (84);
	serverInfo->isOn = true;
	return (0);
}