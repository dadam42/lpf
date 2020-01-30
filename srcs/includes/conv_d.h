/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conv_d.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: damouyal <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/21 16:58:54 by damouyal          #+#    #+#             */
/*   Updated: 2020/01/30 18:15:52 by damouyal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONV_D_H
# define CONV_D_H
# include "t_pf_format.h"
# include "t_out_buffer.h"
# include <stdarg.h>

typedef int			t_conv_d_mod_no_h_hh;
typedef int			t_conv_d_mod_no;
typedef short		t_conv_d_mod_h;
typedef signed char	t_conv_d_mod_hh;
typedef long		t_conv_d_mod_l;
typedef	long long	t_conv_d_mod_ll;
typedef union		u_conv_d_arg
{
	t_conv_d_mod_no_h_hh	no_h_hh;
	t_conv_d_mod_l			l;
	t_conv_d_mod_ll			ll;
}					t_conv_d_arg;
int					conv_d(t_pf_format *fmt, t_out_buffer *buf
							, va_list *pfargs);
#endif
