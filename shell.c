#include "holberton.h"
/**
 *_strdup - will return a pointer to a newly allocated space in memory
 *@str: is a string
 *Return: a pointer
 */
char *_strdup(char *str)
{
	char *point;

	if (str == '\0')
	{
		return ('\0');
	}

	point = malloc(_strlen(str) + 1);

	if (point == '\0')
	{
		return ('\0');
	}

	_strcpy(point, str);

	return (point);
}
/**
 **_strcpy - will copy a string to a buffer;
 *@dest: is a buffer
 *@src: is a string
 *Return: dest
 */
char *_strcpy(char *dest, char *src)
{
	int a, c;

	a = 0;

	while (src[a] != '\0')
	{
		a++;
	}
	for (c = 0; c <= a; c++)
	{
		dest[c] = src[c];
	}
	return (dest);
}
/**
 *_strlen - this function returns the lenght of  string
 *@s: is a string
 *Return: lenght
 */
int _strlen(char *s)
{
	int i = 0;

	while (s[i] != '\0')
		i++;
	return (i);
}

/**
 *main - is the entry point
 *@ac:
 *@av:
 *@env:
 *Return: always 0
 */
int main(int ac, char **av)
{
	char *buffer = NULL;
	char *token;
	char **holder;
	size_t bufflen = 0;
	size_t i, j;
	int count;
	char *buffer_cpy = NULL;

	while (1)
	{
		i = 0, j = 0, count = 0;
		write(STDOUT_FILENO, "$ ", 2);
		getline(&buffer, &bufflen, stdin); //prompt//

		for (; buffer[i] != '\0'; i++)
		{
			if (buffer[i] == '\n')
				buffer[i] = '\0';
		}
		buffer_cpy = _strdup(buffer);
		token = strtok(buffer_cpy, " ");
		while(token != NULL)
		{
			token = strtok(NULL, " ");
			count++;
		}
		holder = malloc(sizeof(char *) * (count + 1));
		token = strtok(buffer, " ");
		while (token != NULL)
		{
			holder[j] = token;
			token = strtok(NULL, " ");
			j++;
		}
		holder[count] = NULL;
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
