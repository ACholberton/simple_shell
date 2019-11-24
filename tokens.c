#include "holberton.h"
/**
 *tokens - will tokenize the arguments passed by the user
 *@str: is the argument passed by the user
 *Return: holder
 */
char **tokens(char *str)
{
	char *token;
	char **holder;
	char *strcopy = NULL;
	size_t j, counter;

	j = 0, counter = 0;
	strcopy = _strdup(str);

	token = strtok(strcopy, "\t");
	while (token)
	{
		token = strtok(NULL, "\t");
		counter++;
	}

	holder = malloc(sizeof(char *) * (counter + 1));

	token = strtok(str, "\t");
	while (token)
	{
		holder[j] = token;
		token = strtok(NULL, "\t");
		j++;
	}
	holder[counter] = NULL;

	free(strcopy);
	strcopy = NULL;

	return (holder);
}
