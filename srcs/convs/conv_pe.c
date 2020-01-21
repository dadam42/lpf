/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conv_pe.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: damouyal <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/21 16:48:18 by damouyal          #+#    #+#             */
/*   Updated: 2020/01/21 16:48:21 by damouyal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "conv_pe.h"

int	conv_pe(t_pf_format *fmt, t_out_buffer *buf, va_list *pfargs)
{
	(void)fmt;
	(void)buf;
	(void)pfargs;
	return (bufferize_char(buf, '%', 1));
}
