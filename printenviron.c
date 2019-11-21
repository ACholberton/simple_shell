#include "holberton.h"

void printenv(char **env)
{
	size_t i = 0;
	size_t len;

	while (env[i])
	{
		len = _strlen(env[i]);
		write(STDOUT_FILENO, env[i], len);
		_putchar('\n');
		i++;
	}
}
