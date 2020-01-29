#include "ft_printf.h"
#include <stdio.h>

int main()
{
	int oret, fret;
	fret = ft_printf("%d\n", -12345);
	oret = printf("%d\n", -12345);
	if (oret == fret)
	{
		printf("ret Ok.\n");
	}
	else
	{
		printf("fret = %d\noret = %d\n", fret, oret);
	}
	return (0);
}
