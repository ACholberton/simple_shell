#include "holberton.h"

extern char **environ;

char *findpath(char *dup_copy)
{
	char *LV;
	char *RV;
	size_t i = 0;

	while (environ[i])
	{
		dup_copy = _strdup(environ[i]);
		LV = strtok(dup_copy, "=");
		RV = strtok(NULL, "=");
		if (strcmp(LV, "PATH") == 0)
		{
			while (RV)
			{
				strtok(RV, ":");
				strtok(NULL, ":");
			}
		}
		i++;
	}
	return (dup_copy);
}
