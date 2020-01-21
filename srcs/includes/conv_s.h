/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conv_s.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: damouyal <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/21 16:56:40 by damouyal          #+#    #+#             */
/*   Updated: 2020/01/21 16:56:44 by damouyal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONV_S_H
# define CONV_S_H
# include "conv_str.h"
# include <stdarg.h>
# include "t_pf_format.h"
# include "t_out_buffer.h"

int	conv_s(t_pf_format *fmt, t_out_buffer *buf, va_list *pfargs);
#endif
