#include "holberton.h"
/**
 *main - is the entry point
   *Return: always 0
 */
int main(void)
{
	char *buffer = NULL, *buffer_cpy = NULL, *token, **holder;
	size_t bufflen = 0, i, j, counter;

	while (1)
	{
		i = 0, j = 0, counter = 0;
		write(STDOUT_FILENO, "$ ", 2);
		getline(&buffer, &bufflen, stdin);
		for (; buffer[i] != '\0'; i++)
		{
			if (buffer[i] == '\n')
				buffer[i] = '\0';
		}
		buffer_cpy = _strdup(buffer);
		token = strtok(buffer_cpy, " ");
		for (; token != NULL; counter++)
		{
			token = strtok(NULL, " ");
		}
		holder = malloc(sizeof(char *) * (counter + 1));
		token = strtok(buffer, " ");
		for (; token != NULL; j++)
		{
			holder[j] = token;
			token = strtok(NULL, " ");
		}
		holder[counter] = NULL;
		if (fork() == 0)
			execve(holder[0], holder,  NULL);
		else
			wait(NULL);
		free(holder);
		free(buffer_cpy);
		free(buffer);
		buffer = NULL;
		buffer_cpy = NULL;
	}
	return (0);
}
