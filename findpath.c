#include "holberton.h"

char *findpath(char **command, char **env)
{
	char *left = NULL, *right = NULL, *bins, *token, *envdup, *path = NULL;
	size_t i, j, len1 = 0, len2 = 0;

	for (i = 0; env[i]; i++)
	{
		envdup = _strdup(env[i]);
		left = strtok(envdup, "=");

		right = strtok(NULL, "=");

		if (_strcmp(left, "PATH") == 0)
		{
			bins = right;
			token = strtok(bins, ":");
			for (j = 0; bins; j++)
			{
				token = strtok(NULL, ":");
				len1 = _strlen(token);
				len2 = _strlen(command[0]);

				path = malloc(sizeof(char) * (len1 + len2));
				_strcat(path, token);
				_strcat(path, "/");
				_strcat(path, *command);
				_strcat(path, "\0");

				if (access(path, X_OK) == 0)
				{
					return (path);
				}
				else
				{
					free(path);
				}
			}
		}
		env++;
		free(envdup);
		envdup = NULL;
		path = NULL;
	}
	return (*command);
}
