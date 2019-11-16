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

char *strtokarray(char *str)
{
	char *token;
	char *singletoken;
	size_t len = 0;
	int counter;

	len = _strlen(str);
	token = malloc(sizeof(char) * len);
	token = strtok(str, ", ");

	write(STDOUT_FILENO, token, len);
	counter++;

	return (singletoken);
}

int main()
{
	char *buffer;
	size_t n = 0;
	ssize_t in;

	while (1)
	{
		write(STDOUT_FILENO, "$ ", 2);
		in = getline(&buffer,&n,stdin);
		write(STDOUT_FILENO, strtokarray(buffer), in);
	}

	return(0);
}
