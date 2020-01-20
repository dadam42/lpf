#include "pf_parser.h"
#include <stdio.h>

int main(int argc, char** argv)
{
	argv++;
	while (argc > 1)
	{
		printf("Parsing %s:\n", *argv);
		char buffer[3];
		t_pf_format fmt;
		pf_parse(&(*argv), &fmt, 0);
		if (fmt.flags & FMT_ZERO)
			buffer[0] = '0';
		if (fmt.flags & FMT_MINUS)
			buffer[1] = '-';
		buffer[3] = 0;
		printf("flags : %s\n", buffer);
		if (fmt.flags & FMT_WIDTH)
			printf("format was given a width\n");
		printf("fmt.width = %d\n", fmt.width);
		if (fmt.flags & FMT_PREC)
			printf("format was given a prec\n");
		printf("fmt.prec = %d\n", fmt.prec);
		printf("format char is %c\n-\n", fmt.char_conv);
		argc--;
		argv++;
	}	
}
