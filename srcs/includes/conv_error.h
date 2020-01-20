#ifndef CONV_ERROR_H
# define CONV_ERROR_H
# include "pf_exec.h"
# include "t_pf_format.h"
# include "t_out_buffer.h"

int	conv_error(t_pf_format *fmt, t_out_buffer *buf, va_list *pfargs);
#endif
