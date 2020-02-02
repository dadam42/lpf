/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_functions.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: damouyal <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/21 15:30:18 by damouyal          #+#    #+#             */
/*   Updated: 2020/02/02 17:28:34 by damouyal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ftprintf.h"
#include "t_out_buffer.h"
#include <unistd.h>
#include <stdarg.h>
#include "pf_parser.h"
#include "t_pf_format.h"
#include "pf_exec.h"

static int	ft_pvadprintf(int fd, char const *str, va_list *pfargs)
{
	char const		*ostr;
	t_out_buffer	buffer;
	t_pf_format		format;

	t_out_buffer_init(&buffer, fd, write);
	while (1)
	{
		if (*str == '%')
		{
			pf_parse(&str, &format, pfargs);
			if (format.char_conv)
				if (pf_exec(&format, &buffer, pfargs) == PF_EXEC_ERROR)
					break ;
		}
		ostr = str;
		while (*str && (*str != '%'))
			str++;
		if (ostr != str)
			if (bufferize_buf(&buffer, ostr, str - ostr) == T_OUT_BUFFER_ERROR)
				break ;
		if (!*str)
			return (t_out_buffer_flush((&buffer)));
	}
	return (FT_PRINTF_ERROR);
}

int			ft_printf(char const *str, ...)
{
	va_list	pfargs;
	int		ret;

	va_start(pfargs, str);
	ret = ft_pvadprintf(1, str, &pfargs);
	va_end(pfargs);
	return (ret);
}
