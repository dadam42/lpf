#include "ft_printf.h"
#include <stdio.h>
#include "unistd.h"
#include <string.h>
#include <stdlib.h>
#define MY_PREFIX "<"
#define MY_SUFFIX ">"
#define MY_PREC ".3"
#define MY_WIDTH "25"
#define MY_FLAGS "-"
#ifdef TEST_FAKE
# ifdef TEST_ORIG
#  undef TEST_ORIG
# endif
# define TEST_SINGLE
# define fret ret
#endif
#ifdef TEST_ORIG
# define TEST_SINGLE
# define oret ret
#endif

int main(int argc, char **argv)
{
#ifdef TEST_SINGLE
	int ret;
#else	
	int oret;
	int fret;
#endif
	char format[50];
	char mformat[50];
	char message[100];
#ifdef CONV_S
	char	*str[] = {"Toto", "", 0};
	char	*strfmt = "s";
#define PFARG str
#define TPFARG char*
#endif
#ifdef CONV_U
	unsigned int u[] = {12, -123, 2345};
	char *strfmt= "u";
#define PFARG u
#define TPFARG unsigned int
#endif
#ifdef CONV_D
	int d[] = {12, -42, 458, 0};
	char *strfmt= "d";
#define PFARG d
#define TPFARG int
#endif
#ifdef CONV_XU
	unsigned int xu[] = {0,123456,-12};
	char *strfmt = "X";
#define PFARG xu
#define TPFARG unsigned int
#endif
#ifdef CONV_XL
	unsigned int xl[] = {0,123456,-12};
	char *strfmt = "x";
#define PFARG xl
#define TPFARG unsigned int
#endif
#ifdef CONV_P
	void* p[] = {"x", "y"};
	char *strfmt = "p";
#define PFARG p
#define TPFARG void*
#endif

	int cpfarg = sizeof(PFARG) / sizeof(TPFARG);
	int pfargdx = 0;

	while (pfargdx < cpfarg)
	{
	
	bzero(format, sizeof(format));
	bzero(message, sizeof(message));
	bzero(mformat, sizeof(mformat));
	strcat(format,MY_PREFIX);
	strcat(format,"%");
	strcat(mformat,format);
	strcat(mformat,"%");
	strcat(format, MY_FLAGS);
	strcat(mformat, MY_FLAGS);
	strcat(format,MY_WIDTH);
	strcat(mformat,MY_WIDTH);
	strcat(format, MY_PREC);
	strcat(mformat, MY_PREC);
	strcat(format, strfmt);
	strcat(mformat, strfmt);
	strcat(format, MY_SUFFIX);
	strcat(mformat, MY_SUFFIX);
	strcat(message,"-> Testing |");
	strcat(message,mformat);
	strcat(message, "| with arg = |%");
	strcat(message, strfmt);
	strcat(message, "| :\n");
	printf(message, PFARG[pfargdx]);
	strcat(format, "\n");
#ifndef TEST_ORIG	
	fret = ft_printf(format,PFARG[pfargdx]);
#endif
#ifndef TEST_FAKE
	oret = printf(format, PFARG[pfargdx]);
#endif
#ifdef TEST_SINGLE
	printf ("->ret = %d\n<-\n", ret);
#else
	if (fret == oret)
		printf("-> retok\n");
	else
		printf("-> fret = %d\n-> oret = %d\n",fret,oret);
#endif
	pfargdx++;
	}
	return (0);
}
