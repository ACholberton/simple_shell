#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <stdlib.h>

int main()
{
	char *buffer = NULL;
	size_t n;
	size_t in;

	printf("$ ");
	in = getline(&buffer,&n,stdin);
	printf("$ %s", buffer);
	return(0);
}
