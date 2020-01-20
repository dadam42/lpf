#include "conv_xu.h"
#include "conv_ubase.h"
#include "libft.h"

int	conv_xu(t_pf_format *fmt, t_out_buffer *buf, va_list *pfargs)
{
	return (conv_ubase(fmt, buf, pfargs, "0123456789ABCDEF"));
}
