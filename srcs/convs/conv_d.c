/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conv_d.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: damouyal <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/21 16:59:03 by damouyal          #+#    #+#             */
/*   Updated: 2020/01/30 15:22:27 by damouyal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "conv_d.h"
#include "conv_num.h"
#include "libft.h"

static void	handling_conv_d_mod(t_conv_d_arg *d, va_list *pfargs
								, t_conv_num_util *util, t_pf_format *fmt)
{
	if (fmt->mod == 0 || fmt->mod == FMT_MOD_H || fmt->mod == FMT_MOD_HH)
	{
		d->no_h_hh = va_arg(*pfargs, t_conv_d_mod_no_h_hh);
		util->str = ft_itoa(d->no_h_hh);
	}
	if (fmt->mod == FMT_MOD_L)
	{
		d->l = va_arg(*pfargs, t_conv_d_mod_l);
		util->str = ft_ltoa(d->l);
	}
	if (fmt->mod == FMT_MOD_LL)
	{
		d->ll = va_arg(*pfargs, t_conv_d_mod_ll);
		util->str = ft_lltoa(d->ll);
	}
}

static int	conv_d_arg_is_nul(t_conv_d_arg *d, t_pf_format *fmt)
{
	if ((fmt->mod == FMT_MOD_NO && d->no_h_hh == 0)
		|| (fmt->mod == FMT_MOD_H && d->no_h_hh == 0)
		|| (fmt->mod == FMT_MOD_HH && d->no_h_hh == 0)
		|| (fmt->mod == FMT_MOD_L && d->l == 0)
		|| (fmt->mod == FMT_MOD_LL && d->ll == 0))
		return (1);
	return (0);
}

static int	conv_d_arg_is_neg(t_conv_d_arg *d, t_pf_format *fmt)
{
	if ((fmt->mod == FMT_MOD_NO && d->no_h_hh < 0)
		|| (fmt->mod == FMT_MOD_H && d->no_h_hh < 0)
		|| (fmt->mod == FMT_MOD_HH && d->no_h_hh < 0)
		|| (fmt->mod == FMT_MOD_L && d->l < 0)
		|| (fmt->mod == FMT_MOD_LL && d->ll < 0))
		return (1);
	return (0);
}

static void	setup_conv_d(t_conv_d_arg *d, va_list *pfargs
						, t_conv_num_util *util, t_pf_format *fmt)
{
	handling_conv_d_mod(d, pfargs, util, fmt);
	if ((fmt->flags & FMT_PREC) && (fmt->prec == 0)
		&& conv_d_arg_is_nul(d, fmt))
		util->lstr = 0;
	else
		util->lstr = ft_strlen(util->str);
	if ((fmt->flags & (FMT_PLUS | FMT_SPACE))
		|| conv_d_arg_is_neg(d, fmt))
	{
		util->lprefix = 1;
		util->prefix = (fmt->flags & FMT_PLUS ? "+" : " ");
		if (conv_d_arg_is_neg(d, fmt))
		{
			util->prefix = util->str;
			util->lstr--;
			util->str++;
		}
	}
}

int			conv_d(t_pf_format *fmt, t_out_buffer *buf, va_list *pfargs)
{
	t_conv_d_arg	d;
	int				ret;
	t_conv_num_util util;

	ft_bzero(&util, sizeof(util));
	setup_conv_d(&d, pfargs, &util, fmt);
	ret = conv_num(fmt, buf, &util);
	free(util.str - (conv_d_arg_is_neg(&d, fmt) ? 1 : 0));
	return (ret);
}
