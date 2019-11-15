#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <stdlib.h>

int main()
{
	char *buffer = NULL;
	size_t n;
	size_t in;

	while (1)
	{
		write (STDOUT_FILENO, "$ ", 2);
		in = getline(&buffer,&n,stdin);
		write(STDOUT_FILENO, buffer, sizeof(char *));
	}

	return(0);
}
