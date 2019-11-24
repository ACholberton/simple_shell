#include "holberton.h"
/**
 *main - is the entry point
 *@ac:  is the number of arguments passed
 *@av: is the argument passed
 *@env: is the enviroment
 *Return: always 0
 */
int main(int ac, char **av, char **env)
{
	char *buffer = NULL;
	char **command;
	size_t bufflen = 0, i;
	int status;
	(void) ac, (void) av;

	while (1)
	{
		i = 0;
		write(STDOUT_FILENO, "$ ", 2);
		getline(&buffer, &bufflen, stdin);
		if (_strcmp(buffer, "\n") == 0)
			continue;
/*		if (_strcmp(buffer, "\t") == 0)
		continue;*/
		for (; buffer[i] != '\0'; i++)
		{
			if (buffer[i] == '\n')
				buffer[i] = '\0';
		}
		if (_strcmp(buffer, "env") == 0)
		{
			printenvi(env);
			free(buffer);
		}
		if (_strcmp(buffer, "exit") == 0)
		{
			write(STDOUT_FILENO, "cya", 4);
			_putchar('\n');
			exit(EXIT_SUCCESS);
			free(buffer);
		}
		command = tokens(buffer);
		status = findpath(command, env);
		if (status == 1)
		{
			if (fork() == 0)
				execve(command[0], command,  NULL);
			else
				wait(NULL);
		}
		free(buffer);
		buffer = NULL;
	}
	return (0);
}
