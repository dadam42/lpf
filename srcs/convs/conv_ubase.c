/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conv_ubase.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: damouyal <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/21 17:12:40 by damouyal          #+#    #+#             */
/*   Updated: 2020/01/29 21:45:45 by damouyal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "conv_ubase.h"
#include "libft.h"

int	conv_ubase(t_pf_format *fmt, t_out_buffer *buf,
				va_list *pfargs, char const *base)
{
	unsigned int	u;
	t_conv_num_util util;
	int				ret;

	ft_bzero(&util, sizeof(util));
	u = va_arg(*pfargs, unsigned int);
	util.str = ft_uitoa_base(u, base);
	if ((fmt->flags & FMT_PREC) && (fmt->prec == 0) && (u == 0))
		util.lstr = 0;
	else
		util.lstr = ft_strlen(util.str);
	if (fmt->flags & FMT_SHARP)
	{
		if (fmt->char_conv == 'x' || fmt->char_conv == 'X')
		{
			util.lprefix = 2;
			util.prefix = "0X";
			if (fmt->char_conv == 'x')
				util.prefix = "0x";
		}
	}
	ret = conv_num(fmt, buf, &util);
	free(util.str);
	return (ret);
}
