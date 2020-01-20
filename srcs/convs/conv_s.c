#include "conv_s.h"
#include "libft.h"

int	conv_s(t_pf_format *fmt, t_out_buffer *buf, va_list *pfargs)
{
	t_conv_str_util util;

	ft_bzero(&util, sizeof(util));
	util.str = va_arg(*pfargs, char*);
	if (!util.str)
		util.str = DEFAULT_STR;
	util.len = ft_strlen(util.str);
	
	return (conv_str(fmt, buf, &util)); 
}
