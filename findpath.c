#include "holberton.h"

char **findpath(char *input, char **env)
{
	char *left, *right, *bins = NULL, *token, **path = NULL;
	size_t i = 0;


	left = strtok(*env, "=");
	right = strtok(NULL, "=");
	if (_strcmp(left, "PATH") == 0)
	{
		bins = right;
 		token = strtok(bins, ":");
		while (bins)
		{
			token = strtok(NULL, ":");

			path = malloc(sizeof(char *) * _strlen(token));

			bins = _strcat(bins, "/");
			path = _strcat(bins, input);
			path = _strcat(*path, "\0");

			if (access(*path, F_OK) == 0)
			{
				if (fork() == 0)
					execve(path[0], path, NULL);
				else
					wait(NULL);
			}
		}
		path = NULL;
		i++;
		free(left);
		free(right);
	}
	return (0);
}
