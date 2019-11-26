#include "holberton.h"

void execute(char **command, char *buffer)
{
	if (fork() == 0)
	{
		execve(command[0], command, NULL);
		free(command);
		free(buffer);
		exit(EXIT_SUCCESS);
	}
	else
		wait(NULL);
}
