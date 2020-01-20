#ifndef CONV_C_H
# define CONV_C_H
# include "conv_str.h"
# include <stdarg.h>

int	conv_c(t_pf_format *fmt, t_out_buffer *buf, va_list *pfargs);
#endif
