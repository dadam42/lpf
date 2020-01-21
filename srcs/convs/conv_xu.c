/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conv_xu.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: damouyal <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/21 17:06:25 by damouyal          #+#    #+#             */
/*   Updated: 2020/01/21 17:06:28 by damouyal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "conv_xu.h"
#include "conv_ubase.h"
#include "libft.h"

int	conv_xu(t_pf_format *fmt, t_out_buffer *buf, va_list *pfargs)
{
	return (conv_ubase(fmt, buf, pfargs, "0123456789ABCDEF"));
}
