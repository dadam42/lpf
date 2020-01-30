/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conv_n.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: damouyal <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/29 19:42:17 by damouyal          #+#    #+#             */
/*   Updated: 2020/01/30 18:26:34 by damouyal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "conv_n.h"
#include "t_out_buffer.h"

static void	set_conv_n_arg(t_conv_n_arg *ptr, t_pf_format *fmt
							, t_out_buffer *buf, va_list *pfargs)
{
	if (fmt->mod == FMT_MOD_NO)
	{
		ptr->no = va_arg(*pfargs, t_conv_n_mod_no);
		*(ptr->no) = (t_conv_d_mod_no)t_out_buffer_flush(buf);
	}
	else if (fmt->mod == FMT_MOD_H)
	{
		ptr->h = va_arg(*pfargs, t_conv_n_mod_h);
		*(ptr->h) = (t_conv_d_mod_h)t_out_buffer_flush(buf);
	}
	else if (fmt->mod == FMT_MOD_HH)
	{
		ptr->hh = va_arg(*pfargs, t_conv_n_mod_hh);
		*(ptr->hh) = (t_conv_d_mod_hh)t_out_buffer_flush(buf);
	}
	else if (fmt->mod == FMT_MOD_L)
	{
		ptr->l = va_arg(*pfargs, t_conv_n_mod_l);
		*(ptr->l) = (t_conv_d_mod_l)t_out_buffer_flush(buf);
	}
	else if (fmt->mod == FMT_MOD_LL)
	{
		ptr->ll = va_arg(*pfargs, t_conv_n_mod_ll);
		*(ptr->ll) = (t_conv_d_mod_ll)t_out_buffer_flush(buf);
	}
}

int			conv_n(t_pf_format *fmt, t_out_buffer *buf, va_list *pfargs)
{
	t_conv_n_arg pint;

	(void)fmt;
	set_conv_n_arg(&pint, fmt, buf, pfargs);
	return (0);
}
