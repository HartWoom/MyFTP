/*
** EPITECH PROJECT, 2018
** myftp
** File description:
** main file
*/

#include <stdio.h>
#include <string.h>
#include "server_struct.h"
#include "server.h"
#include "handle_error.h"

int	main(int ac, char **av)
{
	server_t	serverInfo;

	if (handle_error(ac, av) == 84)
		return (84);
	if (init_server(&serverInfo, av) == 84){
		fprintf(stderr, "Failed to init the FTP server\n");
		return (84);
	}
	if (loop_server(&serverInfo) == 84){
		fprintf(stderr, "Failed to start the server\n");
		return (84);
	}
	return (0);
}