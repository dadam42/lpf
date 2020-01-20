#ifndef PF_PARSER_H
# define PF_PARSER_H
# include "t_pf_format.h"
# include <stdarg.h>

void pf_parse(char const **str, t_pf_format *fmt, va_list *pfargs);
#endif
