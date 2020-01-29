/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conv_num.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: damouyal <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/21 17:20:15 by damouyal          #+#    #+#             */
/*   Updated: 2020/01/29 17:28:31 by damouyal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "conv_num.h"
#include "output_field.h"
#include "format_rules.h"

int			conv_num(t_pf_format *fmt, t_out_buffer *buf, t_conv_num_util *util)
{
	format_numeric_rule(fmt);
	util->rbg = ' ';
	util->lbg = ' ';
	util->mbg = '0';
	if (fmt->flags & FMT_ZERO)
		util->lbg = '0';
	if ((fmt->flags & FMT_PREC) && (fmt->prec > util->lstr))
		util->mpad = fmt->prec - util->lstr;
	if ((fmt->flags & FMT_WIDTH)
			&& (fmt->width > util->lstr + util->mpad + util->lprefix))
	{
		if ((fmt->flags & FMT_ZERO) && util->lprefix > 0)
			util->mpad += fmt->width - util->lstr - util->lprefix;
		else
			util->lpad += fmt->width - util->lstr - util->lprefix - util->mpad;
	}
	if (fmt->flags & FMT_MINUS)
	{
		util->rpad = util->lpad;
		util->lpad = 0;
	}
	return (output_field(buf, 5, 0, util->lbg, util->lpad,
				1, util->prefix, util->lprefix, 0, util->mbg, util->mpad,
				1, util->str, util->lstr, 0, util->rbg, util->rpad));
}
