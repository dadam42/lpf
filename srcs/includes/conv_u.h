#ifndef CONV_U_H
# define CONV_U_H
# include "pf_exec.h"
# include "t_pf_format.h"
# include "t_out_buffer.h"
# include <stdarg.h>
# include "conv_num.h"

int	conv_u(t_pf_format *fmt, t_out_buffer *buf, va_list *pfargs);
#endif
