#include "holberton.h"

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
	char **str;
	size_t counter = 0;

	while (1)
	{
		write(STDOUT_FILENO, "$ ", 2);
		getline(&buffer, &bufflen, stdin);

		token = strtok(buffer, " ");

		str = malloc(sizeof(char *) * (counter + 1));
		while (token != NULL)
		{
			str[counter] = token;
			write(STDOUT_FILENO, token, _strlen(token));
			token = strtok(NULL, " ");
			counter++;
		}
		if (fork() == 0)
			execve(str[0], str,  NULL);
		else
			wait(NULL);

		free(token);
	}
	return (0);
}
