#ifndef CONV_STR_H
# define CONV_STR_H
# include "pf_exec.h"
# include "t_pf_format.h"
# include "t_out_buffer.h"
# define DEFAULT_STR "(null)"

typedef struct	s_conv_str_util
{
	char		bg;
	int			lpad;
	int			rpad;
	int			len;
	char		*str;
}				t_conv_str_util;

int conv_str(t_pf_format *fmt, t_out_buffer *buf, t_conv_str_util *util);
#endif
