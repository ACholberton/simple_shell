#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>

int main(__attribute__((unused))int ac, char **av)
{
	for (; *av; av++)
		printf("%s\n", *av);
	return (0);
}
