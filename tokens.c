#include "holberton.h"

char **tokens(char *str)
{
	char *token;
	char **holder;
	char *strcopy = NULL;
	size_t j, counter;

	j = 0, counter = 0;
	strcopy = _strdup(str);

	token = strtok(strcopy, " ");
	while (token)
	{
		token = strtok(NULL, " ");
		counter++;
	}

	holder = malloc(sizeof(char *) * (counter + 1));

	token = strtok(str, " ");
	while (token)
	{
		holder[j] = token;
		token = strtok(NULL, " ");
		j++;
	}
	holder[counter] = NULL;

	free(strcopy);
	strcopy = NULL;

	return (holder);
}
