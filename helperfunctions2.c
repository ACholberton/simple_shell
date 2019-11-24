#include "holberton.h"

/**
 * cat - concatenates a string for path
 * @str: the buffer
 * @token: the bin to append command to
 * @command: command to append to bin
 * Return: concatenated string
 */
char *cat(char *str, char *token, char **command)
{
	_strcat(str, token);
	_strcat(str, "/");
	_strcat(str, *command);
	_strcat(str, "\0");

	return (str);
}

/**
 * _strcmp - will compare two strings
 * @s1: is a string
 * @s2: is a string
 * Return: a string
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
