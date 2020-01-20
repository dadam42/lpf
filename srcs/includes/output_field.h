#ifndef OUTPUT_FIELD_H
# define OUTPUT_FIELD_H
# include "t_out_buffer.h"
# include <stdarg.h>
# include <unistd.h>
# define OUTPUT_FIELD_ERROR -1

typedef	ssize_t	(*t_output)(t_out_buffer *, va_list *);
int				output_field(t_out_buffer *buf, int n, ...);
#endif
