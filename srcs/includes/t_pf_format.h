#ifndef T_PF_FORMAT_H
# define T_PF_FORMAT_H
# define FMT_ZERO 1
# define FMT_MINUS 2
# define FMT_PREC 4
# define FMT_WIDTH 8
# define STR_FLAGS "0-"

typedef unsigned short	t_flags;
typedef struct			s_pf_format
{
	t_flags flags;
	int		prec;
	int		width;
	char	char_conv;
}						t_pf_format;
#endif
