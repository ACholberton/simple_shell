#include "holberton.h"

void *findpath(char *input, char **env)
{
	char *left, *right, *bin;
	size_t i = 0;


	while (environ[i])
	{
		env_copy = _strdup(environ[i]);
		left = strtok(env_copy, "=");
		right = strtok(NULL, "=");
		if (strcmp(left, "PATH") == 0)
		{

			bins = right
			while (bins)
			{
				strtok(NULL, ":");
			}
		}
		i++;
		free(left);
		free(right);
	}
	return (dup_copy);
}
