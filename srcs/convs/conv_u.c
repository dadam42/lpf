#include "conv_u.h"
#include "libft.h"

int	conv_u(t_pf_format *fmt, t_out_buffer *buf, va_list *pfargs)
{
	unsigned int	u;
	t_conv_num_util util;
	int				ret;

	ft_bzero(&util, sizeof(util));
	u = va_arg(*pfargs, unsigned int);
	util.str = ft_itoa(u);
	util.lstr = ft_strlen(util.str);
	ret = conv_num(fmt, buf, &util);
	free(util.str);
	return (ret);
}

