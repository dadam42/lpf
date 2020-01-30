/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conv_n.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: damouyal <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/29 19:51:44 by damouyal          #+#    #+#             */
/*   Updated: 2020/01/30 18:17:14 by damouyal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONV_N_H
# define CONV_N_H
# include <stdarg.h>
# include "t_pf_format.h"
# include "t_out_buffer.h"
# include "conv_d.h"

typedef t_conv_d_mod_no	*t_conv_n_mod_no;
typedef t_conv_d_mod_h	*t_conv_n_mod_h;
typedef t_conv_d_mod_hh	*t_conv_n_mod_hh;
typedef t_conv_d_mod_l	*t_conv_n_mod_l;
typedef t_conv_d_mod_ll	*t_conv_n_mod_ll;
typedef union			u_conv_n_arg
{
	t_conv_n_mod_no	no;
	t_conv_n_mod_h	h;
	t_conv_n_mod_hh	hh;
	t_conv_n_mod_l	l;
	t_conv_n_mod_ll	ll;
}						t_conv_n_arg;
int						conv_n(t_pf_format *fmt, t_out_buffer *buf
								, va_list *pfargs);
#endif
