#ifndef CONV_NUM_H
# define CONV_NUM_H
# include "pf_exec.h"
# include "t_pf_format.h"
# include "t_out_buffer.h"
# include <stdarg.h>

typedef struct	s_conv_num_util
{
	char	lbg;
	int		lpad;
	char	*prefix;
	int		lprefix;
	char	mbg;
	int		mpad;
	char	*str;
	int		lstr;
	char	rbg;
	int		rpad;
}				t_conv_num_util;

int	conv_num(t_pf_format *fmt, t_out_buffer *buf, t_conv_num_util *util);
#endif
