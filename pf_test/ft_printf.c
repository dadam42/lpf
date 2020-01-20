#include "ft_printf.h"
#include <string.h>
#include <stdio.h>

#undef CONV_SELECTED
#if defined(CONV_S) && !defined(CONV_SELECTED)
# define CONV_SELECTED
# define FLAGS_A {"", "-", "0"}
# define WIDTH_A {"", "3", "8", "10", "-1"}
# define PREC_A {"", ".", ".1", ".12", ".-4"}
# define PFARG_A {0, "", "12345"}
# define TPFARG char*
# define STRFMT "s"
#endif

#if defined(CONV_D) && !defined(CONV_SELECTED)
# define CONV_SELECTED
# define FLAGS_A {"", "-", "0"}
# define WIDTH_A {"", "3", "8", "10", "-1"}
# define PREC_A {"", ".", ".1", ".12", ".-4"}
# define PFARG_A {0, 42, -12345687}
# define TPFARG int
# define STRFMT "d"
#endif

void tpfargtoa(TPFARG pfarg, char *buf)
{
	char format[4];

	bzero(format, 4);
	strcat(format,"%");
	strcat(format, STRFMT);
	sprintf(buf, format, pfarg);
}


typedef struct	s_test_util
{
	char *flag;
	char *width;
	char *prec;
	TPFARG pfarg;
}				t_test_util;

t_test_util* looper()
{
	static t_test_util util;
	static int fdx = 0;
	static int wdx = 0;
	static int pdx = 0;
	static int adx = 0;
	static char *flag_a[] = FLAGS_A;
	static char *width_a[] = WIDTH_A;
	static char *prec_a[] = PREC_A;
	static TPFARG pfarg_a[] = PFARG_A;
	int mf, mw, mp, ma;
	mf = sizeof(flag_a)/sizeof(char*);
	mw = sizeof(width_a)/sizeof(char*);
	mp = sizeof(prec_a)/sizeof(char*);
	ma = sizeof(pfarg_a)/sizeof(TPFARG);
	util.flag = flag_a[fdx];
	util.width = width_a[wdx];
	util.prec = prec_a[pdx];
	util.pfarg = pfarg_a[adx];
	if (++adx < ma)
		return &util;
	adx = 0;
	if (++pdx < mp)
		return &util;
	pdx = 0;
	if (++wdx < mw)
		return &util;
	wdx = 0;
	if (++fdx < mf)
		return &util;
	adx = 0;
	pdx = 0;
	wdx = 0;
	fdx = 0;
	return NULL;
}

int main()
{
#if defined(FAKE) || defined(ORIG)
	char message[100];
	char format[30];
	t_test_util *util;
	int tested = 0;
	int passed = 0;
	int oret;
	int fret;

	(void)oret;
	(void)fret;
	(void)passed;
	while ((util = looper()))
	{
		tested++;
		printf ("Test #%d : \"<", tested);
		bzero(format, 30);
		strcat(format, util->flag);
		strcat(format, util->width);
		strcat(format, util->prec);
		strcat(format, STRFMT);
		printf("%s", format);
		bzero(message, 100);
		tpfargtoa(util->pfarg, message);
		printf(">\" with |arg| ~ |%s| :\n", message);
		bzero(message,100);
		strcat(message,"<%");
		strcat(message,format);
		strcat(message, ">");
#if defined(FAKE) && defined(ORIG)
		printf("fake : "); fflush(stdout);
		fret = ft_printf(message, util->pfarg);
		printf("\norig : "); fflush(stdout);
		oret = printf(message, util->pfarg); printf("\n");
		if (oret != fret)
			printf("oret : %d != %d : fret\n", oret, fret);
		else
			passed++;
# else
printf("output : "); fflush(stdout);
# ifdef FAKE
oret = ft_printf(message, util->pfarg);
# endif
# ifdef ORIG
oret = printf(message, util->pfarg);
# endif
printf(" : %d\n",oret);
#endif
	}
#if defined(FAKE) && defined(ORIG)
	printf("***** ABSTRACT ******\n");
	printf("%d/%d", passed, tested);
#endif
#endif
	return (0);
}
