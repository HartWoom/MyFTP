/*
** EPITECH PROJECT, 2018
** myftp
** File description:
** unit tests for handle_error function
*/

#include <criterion/criterion.h>
#include "unit_tests.h"

Test(handle_error, no_args, .init = setup)
{
	char	*av[] = {"./server"};
	int	ac = 1;

	cr_assert(handle_error(ac, av) == 84);
}

Test(handle_error, missing_arg, .init = setup)
{
	char	*av[] = {"./server", "hello"};
	int	ac = 2;

	cr_assert(handle_error(ac, av) == 84);
}

Test(handle_error, help_arg, .init = setup)
{
	char	*av[] = {"./server", "-help"};
	int	ac = 2;

	cr_assert(handle_error(ac, av) == 0);
}

Test(handle_error, two_wrong_arg, .init = setup)
{
	char	*av[] = {"./server", "hello", "world"};
	int	ac = 3;

	cr_assert(handle_error(ac, av) == 84);
}

Test(handle_error, one_wrong_arg, .init = setup)
{
	char	*av[] = {"./server", "hi", "."};
	int	ac = 3;

	cr_assert(handle_error(ac, av) == 84);
}