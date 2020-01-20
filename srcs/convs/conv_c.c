#include "conv_c.h"
#include "libft.h"

int	conv_c(t_pf_format *fmt, t_out_buffer *buf, va_list *pfargs)
{
	t_conv_str_util util;
	char			c;

	ft_bzero(&util, sizeof(util));
	c = (char)va_arg(*pfargs, int);
	util.str = &c;
	util.len = 1;
	
	return (conv_str(fmt, buf, &util)); 
}
