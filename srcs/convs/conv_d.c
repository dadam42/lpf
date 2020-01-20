#include "conv_d.h"
#include "libft.h"

int	conv_d(t_pf_format *fmt, t_out_buffer *buf, va_list *pfargs)
{
	int				d;
	t_conv_num_util util;

	ft_bzero(&util, sizeof(util));
	d = va_arg(*pfargs, int);
	util.str = ft_itoa(d);
	util.lstr = ft_strlen(util.str);
	if (d < 0)
	{
		util.prefix = util.str;
		util.lprefix = 1;
		util.str++;
		util.lstr--;
	}
	d = conv_num(fmt, buf, &util);
	util.str -= util.lprefix;
	free(util.str);
	return (d);
}
