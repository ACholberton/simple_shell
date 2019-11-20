#include "holberton.h"
/**
 *_strcmp - will compare two strings
 *@s1: is a string
 *@s2: is a string
 *Return: a string
 */
int _strcmp(char *s1, char *s2)
{
	while (*s1 && *s2 && *s1 == *s2)
	{
		s1++;
		s2++;
	}
	return (*s1 - *s2);
}
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
 * _putchar - writes the character c to stdout
 * @c: The character to print
 *
 * Return: On success 1.
 * On error, -1 is returned, and errno is set appropriately.
 */
int _putchar(char c)
{
	return (write(1, &c, 1));
}
