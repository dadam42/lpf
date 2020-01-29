/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   output_field.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: damouyal <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/29 18:48:18 by damouyal          #+#    #+#             */
/*   Updated: 2020/01/29 18:48:20 by damouyal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef OUTPUT_FIELD_H
# define OUTPUT_FIELD_H
# include "t_out_buffer.h"
# include <stdarg.h>
# include <unistd.h>
# define OUTPUT_FIELD_ERROR -1

typedef	ssize_t	(*t_output)(t_out_buffer *, va_list *);
int				output_field(t_out_buffer *buf, int n, ...);
#endif
