#include "conv_str.h"
#include "output_field.h"

int conv_str(t_pf_format *fmt, t_out_buffer *buf, t_conv_str_util *util)
{
	int ret;

	util->bg = ' ';
	if (fmt->flags & FMT_ZERO)
		util->bg = '0';
	if ((fmt->flags & FMT_PREC) && (fmt->prec < util->len))
		util->len = fmt->prec;
	if ((fmt->flags & FMT_WIDTH) && (fmt->width > util->len))
		util->lpad = fmt->width - util->len;
	if (fmt->flags & FMT_MINUS)
	{
		util->rpad = util->lpad;
		util->lpad = 0;
	}
	ret = output_field(buf, 3, 0, util->bg, util->lpad,
						1, util->str, util->len, 0, util->bg, util->rpad);
	return (ret);
}
