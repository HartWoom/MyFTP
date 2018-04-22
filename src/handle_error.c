/*
** EPITECH PROJECT, 2018
** myftp
** File description:
** handle_error function with it's display_help
*/

#include <stdio.h>
#include <string.h>
#include "utils.h"

void	display_help(void)
{
	printf("USAGE: ./server port path\n");
	printf("\tport\tis the port number on which the server"
	" socket listens\n");
	printf("\tpath\tis the path to the home directory"
	" for the Anonymous user\n");
}

int	handle_error(int ac, char **av)
{
	if (ac == 2 && strcmp(av[1], "-help") == 0){
		display_help();
		return (0);
	}
	if (ac != 3){
		fprintf(stderr, "See '-help' for usage.\n");
		return (84);
	}
	if (!is_numerical(av[1])){
		fprintf(stderr, "'port' argument is not numerical."
			" See '-help' for usage\n");
		return (84);
	}
	return (0);
}