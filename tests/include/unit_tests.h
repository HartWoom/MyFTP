/*
** EPITECH PROJECT, 2018
** myftp
** File description:
** unit_tests functions re-definition
*/

#ifndef UNIT_TESTS_H_
# define UNIT_TESTS_H_

# include <stdbool.h>

void	setup(void);
int	(*handle_error)(int ac, char **av);
bool	(*is_numerical)(char *number);

#endif