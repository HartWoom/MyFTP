/*
** EPITECH PROJECT, 2018
** myftp
** File description:
** some of the logged command
*/

#include <string.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <dirent.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <pwd.h>
#include <grp.h>
#include <time.h>
#include "command_function_pointer.h"
#include "display_file.h"

void	display_file_info(struct dirent *dirStruct, int dataSocket)
{
	struct passwd	*pwd;
	struct group	*grp;
	struct stat	st;
	char	*buff;

	stat(dirStruct->d_name, &st);
	display_file_type(st, dataSocket);
	display_file_right100(st, dataSocket);
	display_file_right10(st, dataSocket);
	display_file_right1(st, dataSocket);
	pwd = getpwuid(st.st_uid);
	grp = getgrgid(st.st_gid);
	buff = ctime(&st.st_mtime);
	buff = strtok(buff, "\n");
	dprintf(dataSocket, " %2lu %s %s %7ld %s %s\n",
		st.st_nlink, pwd->pw_name, grp->gr_name,
		st.st_size, buff, dirStruct->d_name);
}

void	command_list_part2(DIR *directory, command_t *commandInfo)
{
	struct dirent	*dirStruct;

	dirStruct = readdir(directory);
	dprintf(commandInfo->clientSocket, "150 Here comes the"
		" directory listing.\n");
	while (dirStruct != NULL){
		display_file_info(dirStruct, commandInfo->dataSocket);
		dirStruct = readdir(directory);
	}
	dprintf(commandInfo->clientSocket, "250 Directory send OK.\n");
	shutdown(commandInfo->dataSocket, SHUT_RDWR);
	commandInfo->dataSocket = -1;
	closedir(directory);
}

void	command_list(command_t *commandInfo)
{
	char	*buff = malloc(sizeof(char) * 1024);
	DIR	*directory = opendir(getcwd(buff, 1024));

	if (!commandInfo->logged){
		dprintf(commandInfo->clientSocket, "530 Please login with USER"
			" and PASS.\n");
		return;
	}
	if (commandInfo->dataSocket == -1)
		dprintf(commandInfo->clientSocket, "450 Requested file action"
		" not taken. No data connection.\n");
	else if (directory)
		command_list_part2(directory, commandInfo);
	else
		dprintf(commandInfo->clientSocket, "451 Requested action"
			" aborted: local error in processing.\n");
}