/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conv_pe.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: damouyal <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/21 16:47:58 by damouyal          #+#    #+#             */
/*   Updated: 2020/01/21 16:52:15 by damouyal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONV_PE_H
# define CONV_PE_H
# include <stdarg.h>
# include "t_pf_format.h"
# include "t_out_buffer.h"

int	conv_pe(t_pf_format *fmt, t_out_buffer *buf, va_list *pfargs);
#endif
