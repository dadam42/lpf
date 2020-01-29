#include "ft_printf.h"
#include <stdio.h>

int main()
{
	int oret, fret;
	fret = ft_printf("%%\n");
	oret = printf("%%\n");
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
