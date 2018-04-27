/*
** EPITECH PROJECT, 2018
** myftp
** File description:
** unit tests for handle_error function
*/

#include <criterion/criterion.h>
#include "unit_tests.h"

Test(handle_error, correct_arg, .init = setup)
{
	char	*av[] = {"./server", "1234", "."};
	int	ac = 3;

	cr_assert(handle_error(ac, av) == 0);
}