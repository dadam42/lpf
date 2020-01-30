#include "ft_printf.h"
#include <stdio.h>
#include <limits.h>
#define PF_TEST_CONV "tuiyo %lln\n"
#define PF_TEST_ARGF &pf
#define PF_TEST_ARGO &po
int main()
{
	int oret, fret;
	long long pf, po; // useful for n conv.
	(void)pf;
	(void)po;
	fret = ft_printf(PF_TEST_CONV, PF_TEST_ARGF);
	oret = printf(PF_TEST_CONV, PF_TEST_ARGO);
	printf("%lld = %lld ?", pf, po);
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
