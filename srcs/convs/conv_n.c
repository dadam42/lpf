/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conv_n.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: damouyal <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/29 19:42:17 by damouyal          #+#    #+#             */
/*   Updated: 2020/01/29 19:58:04 by damouyal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "conv_n.h"
#include "t_out_buffer.h"

int	conv_n(t_pf_format *fmt, t_out_buffer *buf, va_list *pfargs)
{
	int	*pint;

	(void)fmt;
	pint = va_arg(*pfargs, int*);
	*pint = t_out_buffer_flush(buf);
	return (0);
}
