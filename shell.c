#include "holberton.h"
/**
 *main - is the entry point
 *Return: always 0
 */
int main(int ac, char **av, char **env)
{
	char *buffer = NULL;
	char **command;
	char *new;
	size_t bufflen = 0, i;
	int status = 1;
	(void) ac, (void) av;

	while (status)
	{
		i = 0;
		if (buffer != NULL)
		{
			perror("Invalid task, try again");
			exit(1);
		}
		write(STDOUT_FILENO, "$ ", 2);
		getline(&buffer, &bufflen, stdin);
		for (; buffer[i] != '\0'; i++)
		{
			if (buffer[i] == '\n')
				buffer[i] = '\0';
		}
		if (strcmp(buffer, "env") == 0)
		{
			printenv(env);
		}
		if (strcmp(buffer, "exit") == 0)
		{
			write(STDOUT_FILENO, "cya", 4);
			_putchar('\n');
			exit(EXIT_SUCCESS);
			free(buffer);
		}

		command = tokens(buffer);
		new = findpath(command, env);
		if (new)
		{
			if (fork() == 0)
				execve(new, command,  NULL);
			else
				wait(NULL);
		}
		else
		{
			if(fork() == 0)
				execve(command[0], command, NULL);
			else
				wait(NULL);
		}
		free(buffer);
		buffer = NULL;
	}
	return (0);
}
