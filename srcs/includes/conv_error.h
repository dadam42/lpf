/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conv_error.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: damouyal <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/29 18:47:43 by damouyal          #+#    #+#             */
/*   Updated: 2020/01/29 18:47:45 by damouyal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONV_ERROR_H
# define CONV_ERROR_H
# include "pf_exec.h"
# include "t_pf_format.h"
# include "t_out_buffer.h"

int	conv_error(t_pf_format *fmt, t_out_buffer *buf, va_list *pfargs);
#endif
