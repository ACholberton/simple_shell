#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>

int _strlen(char *s)
{
	int i = 0;

	while (s[i] != '\0')
		i++;
	return (i);
}

int main (void)
{
	char *buffer = NULL;
	char *token;
	size_t bufflen = 0;

	while (1)
	{
		write(STDOUT_FILENO, "$ ", 2);
		getline(&buffer, &bufflen, stdin);

		token = strtok(buffer, " ");
		while (token != NULL)
		{
			write(STDOUT_FILENO, token, _strlen(token));
			token = strtok(NULL, " ");
		}
		free(token);
	}
	return (0);
}
