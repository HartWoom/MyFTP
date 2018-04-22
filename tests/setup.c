/*
** EPITECH PROJECT, 2018
** myftp
** File description:
** setup file for unit tests
*/

#include <criterion/criterion.h>
#include <dlfcn.h>
#include <unistd.h>
#include <stdio.h>

#include "unit_tests.h"

void	setup(void)
{
	void		*handle;

	handle = dlopen("./libserver.so", RTLD_LAZY);
	if (!handle) {
		fprintf(stderr, "./libserver.so: No such file\n");
		exit(1);
	}
	*(void **) (&handle_error) = dlsym(handle, "handle_error");
	*(void **) (&is_numerical) = dlsym(handle, "is_numerical");
}