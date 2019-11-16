#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <string.h>

/**
 * _strlen - returns the length of a string
 * @s: the character string being measured
 * Return: i
 */
int _strlen(char *s)
{
	int i = 0;

	while (s[i] != '\0')
		i++;
	return (i);
}

/**
 * *_strncpy - copies a string
 * @dest: second string
 * @src: first string
 * @n: size
 * Return: copied string
 */

char *_strncpy(char *dest, char *src, int n)
{
	int i;

	for (i = 0; i < n && src[i] != '\0'; i++)
		dest[i] = src[i];
	for ( ; i < n; i++)
		dest[i] = '\0';
	return (dest);
}

void *strtokarray(char *str)
{
	char *token;
	size_t len = 0;
	int counter = 0;

	len = _strlen(str);
	token = malloc(sizeof(char) * len);
	token = strtok(str, ", ");

	while (token != NULL)
	{
	write(STDOUT_FILENO, token, len);
	token = strtok(NULL, ", ");
	}
	free(token);
}

int main()
{
	char *buffer;
	char *token;
	size_t n = 0;
	ssize_t in;
	int len;

	while (1)
	{
		write(STDOUT_FILENO, "$ ", 2);
		in = getline(&buffer,&n,stdin);
		write(STDOUT_FILENO, buffer, in);
	}

	return(0);
}
