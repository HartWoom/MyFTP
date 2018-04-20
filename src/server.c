/*
** EPITECH PROJECT, 2018
** myftp
** File description:
** server functions definition
*/

#include <string.h>
#include <stdlib.h>
#include <sys/types.h>
#include <dirent.h>
#include "serverStruct.h"

int     check_ano_path(server_t *serverInfo, char *anoPath)
{
	DIR     *directory = opendir(anoPath);

	if (directory == NULL)
		return (84);
	serverInfo->anonymousPath = strdup(anoPath);
	closedir(directory);
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
	return (0);
}