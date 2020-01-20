#include "pf_exec.h"

int	pf_exec(t_pf_format *fmt, t_out_buffer *buf, va_list *pfargs)
{
	static t_exec_conv	conv[] = {conv_pe, conv_s, conv_d, conv_d, conv_u
								, conv_xl, conv_xu, conv_p, conv_c
								, conv_error};
	static char			*str_conv = STR_CONV;
	char				*cur;

	cur = str_conv;
	while (*cur)
		if (*cur == fmt->char_conv)
			break;
		else
			cur++;
	return (conv[cur - str_conv](fmt, buf, pfargs));
}
