/*
** EPITECH PROJECT, 2018
** myftp
** File description:
** useful functions definition
*/

#include <stdbool.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>

int	convert_10_to_8(int number)
{
	int	index = 1;
	int	result = 0;

	while (number != 0){
		result += ((number % 8) * index);
		number /= 8;
		index *= 10;
	}
	return (result);
}

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