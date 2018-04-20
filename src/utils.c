/*
** EPITECH PROJECT, 2018
** myftp
** File description:
** useful functions definition
*/

#include <stdbool.h>

bool	is_numerical(char *number)
{
	int	i = 0;

	while (number[i] != '\0'){
		if (number[i] < '0' || number[i] > '9')
			return (false);
		i += 1;
	}
	return (true);
}