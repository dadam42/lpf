#ifndef CONV_XL_H
# define CONV_XL_H
# include "pf_exec.h"
# include "t_pf_format.h"
# include "t_out_buffer.h"
# include <stdarg.h>
# include "conv_num.h"

int	conv_xl(t_pf_format *fmt, t_out_buffer *buf, va_list *pfargs);
#endif
