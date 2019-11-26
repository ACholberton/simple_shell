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
	char **command = NULL;
	size_t bufflen = 0;
	ssize_t loop = 0;
	int status = 0, i = 0, tally;
	(void) ac, (void) av;

	if (isatty(STDIN_FILENO))
		write(STDOUT_FILENO, "$ ", 2);
	while ((loop = getline(&buffer, &bufflen, stdin)))
	{
		i = 0;
		if (loop == EOF)
		{
			write(STDOUT_FILENO, "\n", 1);
			free(buffer);
			break;
		}
		if (_strcmp(buffer, "\n") == 0)
		{
			write(STDOUT_FILENO, "$ ", 2);
			continue;
		}
		if (_strcmp(buffer, "\t") == 0)
			continue;
		for (; buffer[i] != '\0'; i++)
		{
			if (buffer[i] == '\n')
				buffer[i] = '\0';
		}
		_env(buffer, env);
		exitshell(buffer);
		command = tokens(buffer);
		if (command == NULL)
			free (command);

		status = findpath(command, env);
		if (status == 1)
			execute(command, buffer);
/*		{
			if (fork() == 0)
			{
				execve(command[0], command, NULL);
				free(command);
				free(buffer);
				exit(EXIT_SUCCESS);
			}
			else
			{
				wait(NULL);
			}
		}
*/
		free(command);
		free(buffer);
		buffer = NULL;
		tally++;
		if (isatty(STDIN_FILENO))
			write(STDOUT_FILENO, "$ ", 2);
	}
	return (0);
}
