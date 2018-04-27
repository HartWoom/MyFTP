/*
** EPITECH PROJECT, 2018
** myftp
** File description:
** some of the logged command
*/

#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netinet/ip.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include "command_function_pointer.h"

void	command_pasv_part2(command_t *commandInfo, int newSocket,
	struct sockaddr_in newAddress, int newPort)
{
	socklen_t	addrSize = sizeof(struct sockaddr_in);
	int	clientSocket;

	while (bind(newSocket, (struct sockaddr *) &newAddress,
		sizeof(struct sockaddr_in)) == -1)
	{
		newPort += 1;
		newAddress.sin_port = htons(newPort);
	}
	if (listen(newSocket, 42) == -1)
		exit(84);
	dprintf(commandInfo->clientSocket, "227 Entering passive"
		" mode(127,0,0,1,4,%d)\n", newPort - 1024);
	clientSocket = accept(newSocket,
		(struct sockaddr *) &newAddress, &addrSize);
	commandInfo->dataSocket = clientSocket;
}

void	command_pasv(command_t *commandInfo)
{
	int	newPort = 1024;
	int	newSocket;
	struct	sockaddr_in	newAddress;

	if (!commandInfo->logged){
		dprintf(commandInfo->clientSocket, "530 Please login with USER"
			" and PASS.\n");
		return;
	}
	newSocket = socket(AF_INET, SOCK_STREAM, 0);
	memset(&newAddress, 0, sizeof(struct sockaddr_in));
	newAddress.sin_family = AF_INET;
	newAddress.sin_port = htons(newPort);
	newAddress.sin_addr.s_addr = INADDR_ANY;
	command_pasv_part2(commandInfo, newSocket, newAddress, newPort);
}