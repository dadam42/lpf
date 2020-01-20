#ifndef PF_EXEC_H
# define PF_EXEC_H
# include "t_out_buffer.h"
# include <stdarg.h>
# include "conv_pe.h"
# include "conv_s.h"
# include "conv_d.h"
# include "conv_u.h"
# include "conv_xl.h"
# include "conv_xu.h"
# include "conv_p.h"
# include "conv_c.h"
# include "conv_error.h"
# define PF_EXEC_ERROR -1
# define STR_CONV "%sdiuxXp"

typedef int (*t_exec_conv)(t_pf_format *, t_out_buffer *, va_list *);
int			pf_exec(t_pf_format *fmt,
					t_out_buffer *buf, va_list *pfargs);
#endif
