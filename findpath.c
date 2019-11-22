#include "holberton.h"

int findpath(char **command, char **env)
{
	char *left = NULL, *right = NULL, *bins, *token, *envdup, *path = NULL;
	size_t i, j, len1, len2;
	int a;

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

				path = malloc(sizeof(char *) * (len1 + len2));

				_strcat(path, token);
				_strcat(path, "/");
				_strcat(path, *command);
				_strcat(path, "\0");

				a = fork();
				if (access(path, X_OK) == 0)
				{
					if (a == 0)
					{
						execve(path, command, NULL);
						break;
					}
					else
						wait(NULL);
				}

			}
		}
		env++;
		free(path);
		path = NULL;
	}
	return (0);
}
