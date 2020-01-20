#include "ft_printf.h"
#include <stdio.h>

int main()
{
	int oret, fret;
	oret = printf("toto\n");
	fret = ft_printf("toto\n");
	printf("%d = %d ?\n", oret, fret);
	return (0);
}
