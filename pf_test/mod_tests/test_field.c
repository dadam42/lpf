#include "t_out_buffer.h"
#include "output_field.h"
#include <stdio.h>
#include <unistd.h>
#include "libft.h"



int main()
{
	t_out_buffer buf;

	
	t_out_buffer_init(&buf, 1, write);
	output_field(&buf, 3, 0, 'c', 3, 0, '\n', 1, 1, "Ta mere en short sur la plage\n", ft_strlen("Ta mere en short sur la plage\n"));
	t_out_buffer_flush(&buf);
	return (0);
}
