/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conv_u.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: damouyal <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/21 17:02:07 by damouyal          #+#    #+#             */
/*   Updated: 2020/01/29 17:48:24 by damouyal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "conv_u.h"
#include "libft.h"

int	conv_u(t_pf_format *fmt, t_out_buffer *buf, va_list *pfargs)
{
	unsigned int	u;
	t_conv_num_util util;
	int				ret;

	ft_bzero(&util, sizeof(util));
	u = va_arg(*pfargs, unsigned int);
	util.str = ft_itoa(u);
	if ((fmt->flags & FMT_PREC) && (fmt->prec == 0) && (u == 0))
		util.lstr = 0;
	else
		util.lstr = ft_strlen(util.str);
	ret = conv_num(fmt, buf, &util);
	free(util.str);
	return (ret);
}
