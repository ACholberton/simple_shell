#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <string.h>

int main(void)
{
	char str[] = ;
	char *split;

	printf("select one of these commands: ");
	split = strtok(str, " ,.-");
	while (split != NULL)
	{
		printf("%s\n", split);
		split = strtok (NULL, " ,.-");
	}
	return (0);
}
