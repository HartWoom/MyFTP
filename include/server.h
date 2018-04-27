/*
** EPITECH PROJECT, 2018
** myftp
** File description:
** server functions declaration
*/

#ifndef SERVER_H_
# define SERVER_H_

# include "server_struct.h"

int	init_server(server_t *, char **);
int	loop_server(server_t *);

#endif