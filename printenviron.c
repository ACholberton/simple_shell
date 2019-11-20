#include "holberton.h"

extern char **environ;

void printenviron(void)
{
	size_t i = 0;

	while (environ[i])
	{
		printf("%s", environ[i]);
		putchar('\n');
		i++;
	}
}
