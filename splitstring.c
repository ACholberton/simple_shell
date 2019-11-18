#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>

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

int main (int argc, char **argv)
{
	char *token;
	char **singletoken;
	int len;
	int counter;

	len = _strlen(*argv);
	singletoken = malloc(sizeof(char *) * len);
	token = strtok(*argv, " ");

	while (token != NULL)
	{
		_strncpy(singletoken[counter], token, _strlen(token));
		write(STDOUT_FILENO, singletoken, 10);
		counter++;
	}
	return (0);
}
