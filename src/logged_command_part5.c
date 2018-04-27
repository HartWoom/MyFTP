/*
** EPITECH PROJECT, 2018
** myftp
** File description:
** some of the logged command
*/

#include <stdio.h>
#include <sys/stat.h>
#include <sys/types.h>
#include "utils.h"

void	display_file_type(struct stat st, int dataSocket)
{
	if (S_ISREG(st.st_mode))
		dprintf(dataSocket, "-");
	if (S_ISDIR(st.st_mode))
		dprintf(dataSocket, "d");
	if (S_ISCHR(st.st_mode))
		dprintf(dataSocket, "c");
	if (S_ISBLK(st.st_mode))
		dprintf(dataSocket, "b");
	if (S_ISLNK(st.st_mode))
		dprintf(dataSocket, "l");
	if (S_ISSOCK(st.st_mode))
		dprintf(dataSocket, "s");
}

void    display_file_right100(struct stat sb, int dataSocket)
{
	int   chmod = convert_10_to_8(sb.st_mode & (S_IRWXU));

	switch (chmod){
		case (0) :
			dprintf(dataSocket, "---");
			return;
		case (700) :
			dprintf(dataSocket, "rwx");
			return;
		case (600) :
			dprintf(dataSocket, "rw-");
			return;
		case (500) :
			dprintf(dataSocket, "r-x");
			return;
		case (400) :
			dprintf(dataSocket, "r--");
			return;
		case (300) :
			dprintf(dataSocket, "-wx");
			return;
		case (200) :
			dprintf(dataSocket, "-w-");
			return;
		case (100) :
			dprintf(dataSocket, "--x");
			return;
	}
}

void    display_file_right10(struct stat sb, int dataSocket)
{
	int   chmod = convert_10_to_8(sb.st_mode & (S_IRWXG));

	switch (chmod){
		case (0) :
			dprintf(dataSocket, "---");
			return;
		case (70) :
			dprintf(dataSocket, "rwx");
			return;
		case (60) :
			dprintf(dataSocket, "rw-");
			return;
		case (50) :
			dprintf(dataSocket, "r-x");
			return;
		case (40) :
			dprintf(dataSocket, "r--");
			return;
		case (30) :
			dprintf(dataSocket, "-wx");
			return;
		case (20) :
			dprintf(dataSocket, "-w-");
			return;
		case (10) :
			dprintf(dataSocket, "--x");
			return;
	}
}

void    display_file_right1(struct stat sb, int dataSocket)
{
	int   chmod = convert_10_to_8(sb.st_mode & (S_IRWXO));

	switch (chmod){
		case (0) :
			dprintf(dataSocket, "---");
			return;
		case (7) :
			dprintf(dataSocket, "rwx");
			return;
		case (6) :
			dprintf(dataSocket, "rw-");
			return;
		case (5) :
			dprintf(dataSocket, "r-x");
			return;
		case (4) :
			dprintf(dataSocket, "r--");
			return;
		case (3) :
			dprintf(dataSocket, "-wx");
			return;
		case (2) :
			dprintf(dataSocket, "-w-");
			return;
		case (1) :
			dprintf(dataSocket, "--x");
			return;
	}
}