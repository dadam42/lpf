/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   output_field.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: damouyal <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/29 16:12:45 by damouyal          #+#    #+#             */
/*   Updated: 2020/01/29 18:49:13 by damouyal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "output_field.h"

static ssize_t	output_char(t_out_buffer *buf, va_list *pargs)
{
	char	mychar;
	int		count;

	mychar = (char)va_arg(*pargs, int);
	count = va_arg(*pargs, int);
	return (bufferize_char(buf, mychar, count));
}

static ssize_t	output_buf(t_out_buffer *buf, va_list *pargs)
{
	char	*str;
	int		len;

	str = va_arg(*pargs, char*);
	len = va_arg(*pargs, int);
	return (bufferize_buf(buf, str, len));
}

int				output_field(t_out_buffer *buf, int n, ...)
{
	static t_output	output[2] = {output_char, output_buf};
	va_list			args;
	char			type;
	int				ret;

	va_start(args, n);
	ret = 1;
	while (n > 0)
	{
		type = (char)va_arg(args, int);
		if (output[(int)type](buf, &args) == T_OUT_BUFFER_ERROR)
		{
			ret = OUTPUT_FIELD_ERROR;
			break ;
		}
		n--;
	}
	va_end(args);
	return (ret);
}
