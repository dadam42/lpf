#include "t_out_buffer.h"
#include "libft.h"
#include <stdio.h>
#include <unistd.h>

int	test_bufferize_buf(char *str, int *lenput, int *lensize)
{
	t_out_buffer buf;
	t_out_buffer_init(&buf, 1, write);
	*lensize = ft_strlen(str);
	printf ("Out bufferized string : \n");
	bufferize_buf(&buf, str, *lensize);
	*lenput = t_out_buffer_flush(&buf);
	buf.count = 0;
	printf("\nGiven string : \n");
	printf("%s\n", str);
	if (*lenput == *lensize)
		return (1);
	return (0);
}

int test_bufferize_char(char c, int count, int *lenput)
{
	t_out_buffer buf;
	t_out_buffer_init(&buf, 1, write);

	printf("Out buffering %d times char %c :\n", count, c);
	bufferize_char(&buf, c, count);
	*lenput = t_out_buffer_flush(&buf);
	if (*lenput == count)
		return (1);
	return (0);
}

int main(int argc, char **argv)
{
	int tested;
	int passed;
	int lensize;
	int	lenput;
	int ret;

	tested = 0;
	passed = 0;
	while (argc > 1)
	{
		argc--;
		argv++;
		tested++;
		printf ("Test #%d :\n", tested);
		if ((ft_strlen(*argv) == 3) && (*argv)[0] == 39 && (*argv)[2] == 39 && argc > 1)
		{
			ret = test_bufferize_char((*argv)[1], (lensize = ft_atoi(*(argv + 1))), &lenput);
			argv ++;
			argc--;
		}
		else
			ret = test_bufferize_buf(*argv, &lenput, &lensize);
		if (ret)
		{
			printf("-> retd ok\n");
			passed++;
		}
		else
			printf("lensize : %d - outbufferized : %d\n", lensize, lenput);
		printf("---\n");
	}
	printf ("Abstract passed/tested : %d/%d\n", passed, tested);
	return (0);
}
