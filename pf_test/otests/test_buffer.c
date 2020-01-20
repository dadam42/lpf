#include "t_out_buffer.h"
#include <stdio.h>

int main()
{
	int ret, oret;
	t_out_buffer buf;
	char text[] = "toto\n";

	t_out_buffer_init_simple(&buf, 1);
	buf.bufferize(&buf, text, sizeof(text));
	ret = t_out_buffer_flush(&buf);
	printf ("%d = %ld ?\n", ret, sizeof(text));
	//oret = printf("%s", text);
	//printf ("-> fret = %d, oret = %d\n", ret, oret);
}
