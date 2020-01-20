#include "conv_pe.h"

int	conv_pe(t_pf_format *fmt, t_out_buffer *buf, va_list *pfargs)
{
	(void)fmt;
	(void)buf;
	(void)pfargs;
	return (bufferize_char(buf, '%', 1));
}
