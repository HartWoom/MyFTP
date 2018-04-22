/*
** EPITECH PROJECT, 2018
** myftp
** File description:
** unit tests for is_numerical function
*/

#include <criterion/criterion.h>
#include <stdbool.h>
#include "unit_tests.h"

Test(is_numerical, not_a_number, .init = setup)
{
	char	*str = "1m3";

	cr_assert(is_numerical(str) == false);
}

Test(is_numerical, is_a_number, .init = setup)
{
	char	*str = "42";

	cr_assert(is_numerical(str) == true);
}