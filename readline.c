#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <stdlib.h>

int main()
{
	char *buffer = NULL;
	size_t n = 0;
	ssize_t in;

	while (1)
	{
 		write (STDOUT_FILENO, "$ ", 2);
		in = getline(&buffer,&n,stdin);
		write(STDOUT_FILENO, buffer, in);
	}
	if (buffer)
	{
		free(buffer);
	}
	return(0);
}
