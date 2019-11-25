#include "holberton.h"

void printenvi(char **env)
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

void _env(char *str, char **env)
{
	if (_strcmp(str, "env") == 0)
	{
		printenvi(env);
	}
}
