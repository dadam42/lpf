/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conv_xl.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: damouyal <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/21 17:03:56 by damouyal          #+#    #+#             */
/*   Updated: 2020/01/21 17:06:05 by damouyal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "conv_xl.h"
#include "conv_ubase.h"
#include "libft.h"

int	conv_xl(t_pf_format *fmt, t_out_buffer *buf, va_list *pfargs)
{
	return (conv_ubase(fmt, buf, pfargs, "0123456789abcdef"));
}
