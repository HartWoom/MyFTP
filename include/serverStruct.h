/*
** EPITECH PROJECT, 2018
** myftp
** File description:
** server_t
*/

#ifndef SERVERSTRUCT_H_
# define SERVERSTRUCT_H_

# include <sys/socket.h>
# include <netinet/in.h>
# include <netinet/ip.h>
# include <stdbool.h>

typedef struct server
{
	int socket;
	struct sockaddr_in address;
	char    *anonymousPath;
	bool	isOn;
} server_t;

#endif