#include "conv_error.h"

int	conv_error(t_pf_format *fmt, t_out_buffer *buf, va_list *pfargs)
{
	(void)(fmt);
	(void)(buf);
	(void)(pfargs);
	return (PF_EXEC_ERROR);
}
