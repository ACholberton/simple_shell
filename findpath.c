#include "holberton.h"

extern char **environ;

char *findpath()
{
	char *dup_copy;
	char *location;
	char *LV;
	char *RV;
	size_t i;

	while (environ)
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
	return (location);
}
