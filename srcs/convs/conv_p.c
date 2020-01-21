/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conv_p.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: damouyal <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/21 17:08:49 by damouyal          #+#    #+#             */
/*   Updated: 2020/01/21 17:10:39 by damouyal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "conv_p.h"
#include "libft.h"

int	conv_p(t_pf_format *fmt, t_out_buffer *buf, va_list *pfargs)
{
	intptr_t		intp;
	t_conv_num_util util;
	static char		*prefix = "0x";
	int				ret;

	ft_bzero(&util, sizeof(util));
	intp = va_arg(*pfargs, intptr_t);
	util.str = ft_uitoa_base(intp, "0123456789abcdef");
	util.lstr = ft_strlen(util.str);
	util.prefix = prefix;
	util.lprefix = 2;
	ret = conv_num(fmt, buf, &util);
	free(util.str);
	return (ret);
}
