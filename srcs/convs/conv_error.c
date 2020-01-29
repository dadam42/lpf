/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conv_error.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: damouyal <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/29 18:47:25 by damouyal          #+#    #+#             */
/*   Updated: 2020/01/29 18:47:30 by damouyal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "conv_error.h"

int	conv_error(t_pf_format *fmt, t_out_buffer *buf, va_list *pfargs)
{
	(void)(fmt);
	(void)(buf);
	(void)(pfargs);
	return (PF_EXEC_ERROR);
}
