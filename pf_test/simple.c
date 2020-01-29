#include "ft_printf.h"
#include <stdio.h>

int main()
{
	int oret, fret;
	int no, nf;
	fret = ft_printf("uyi %n\n", &nf);
	oret = printf("uyi %n\n", &no);
	printf("nf : %d no : %d\n", nf, no);
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
