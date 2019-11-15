#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>

int main(void)
{

	int PID;

	PID = getppid();

	write(1, PID, 10);
	return (0);
}
