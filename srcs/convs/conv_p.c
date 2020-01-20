#include "conv_p.h"
#include "libft.h"

int	conv_p(t_pf_format *fmt, t_out_buffer *buf, va_list *pfargs)
{
	intptr_t 		intp;
	t_conv_num_util util;
	static char		*prefix = "0x";
	int				ret;

	ft_bzero(&util, sizeof(util));
	intp = va_arg(*pfargs, intptr_t);
	util.str = ft_uitoa_base(intp, "0123456789abcdef");
	util.lstr = ft_strlen(util.str);
	util.prefix = prefix;
	util.lprefix = 2;
	ret = conv_num(fmt, buf, &util);
	free(util.str);
	return (ret);
}
