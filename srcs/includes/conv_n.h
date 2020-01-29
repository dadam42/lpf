/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conv_n.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: damouyal <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/29 19:51:44 by damouyal          #+#    #+#             */
/*   Updated: 2020/01/29 19:54:29 by damouyal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONV_N_H
# define CONV_N_H
# include <stdarg.h>
# include "t_pf_format.h"
# include "t_out_buffer.h"

int	conv_n(t_pf_format *fmt, t_out_buffer *buf, va_list *pfargs);
#endif
