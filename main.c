/*
** EPITECH PROJECT, 2018
** myftp
** File description:
** main file
*/

#include <stdio.h>
#include <string.h>

void	displayHelp(void)
{
	printf("USAGE: ./server port path\n");
	printf("\tport\tis the port number on which the server"
	" socket listens\n");
	printf("\tpath\tis the path to the home directory"
	" for the Anonymous user\n");
}

int	handleError(int ac, char **av)
{
	if (ac == 2 && strcmp(av[1], "-help") == 0){
		displayHelp();
		return (0);
	}
	if (ac != 3){
		printf("See '-help' for usage.\n");
		return (84);
	}
	return (0);
}

int	main(int ac, char **av)
{
	if (handleError(ac, av) == 84)
		return (84);
	return (0);
}