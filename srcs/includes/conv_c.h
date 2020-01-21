/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conv_c.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: damouyal <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/21 16:53:29 by damouyal          #+#    #+#             */
/*   Updated: 2020/01/21 16:53:31 by damouyal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONV_C_H
# define CONV_C_H
# include "conv_str.h"
# include <stdarg.h>

int	conv_c(t_pf_format *fmt, t_out_buffer *buf, va_list *pfargs);
#endif
