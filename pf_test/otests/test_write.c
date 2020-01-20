#include <unistd.h>
#include <stdio.h>

int main()
{
	int wret = 0;

	wret = write(1, "12345\n", 5);
	printf ("wret = %d", wret);
	return (0);
}
