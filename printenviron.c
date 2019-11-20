#include "holberton.h"

extern char **environ;

void printenviron(void)
{
	size_t i = 0;
	size_t len;

	while (environ[i])
	{
		len = _strlen(environ[i]);
		write(STDOUT_FILENO, environ[i], len);
		_putchar('\n');
		i++;
	}
}
