/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_parser.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: damouyal <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/21 15:48:44 by damouyal          #+#    #+#             */
/*   Updated: 2020/01/29 22:42:24 by damouyal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pf_parser.h"
#include "libft.h"
#include <stdarg.h>
#include "format_rules.h"

static void	set_value(int *val, char const **str, va_list *pfargs)
{
	if (**str == '*')
	{
		*val = va_arg(*pfargs, int);
		(*str)++;
	}
	else
		*val = ft_otg_atoi(str);
}

static void	parse_flags(char const **str, t_pf_format *fmt)
{
	static char	*str_flags = STR_FLAGS;
	char		*cur;
	t_flags		setter;

	while (1)
	{
		cur = str_flags;
		while (*cur)
			if (**str == *cur)
			{
				setter = 1 << (cur - str_flags);
				fmt->flags |= setter;
				(*str)++;
				break ;
			}
			else
				cur++;
		if (!*cur)
			break ;
	}
}

static void	parse_modifiers(char const **str, t_pf_format *fmt)
{
	char mem;

	fmt->mod = 0;
	if (**str == 'h' || **str == 'l')
	{
		mem = **str;
		(*str)++;
		if (**str == mem)
		{
			(*str)++;
			fmt->mod = 1;
		}
		fmt->mod += (mem = 'h' ? FMT_MOD_H : FMT_MOD_L);
	}
}

void		pf_parse(char const **str, t_pf_format *fmt, va_list *pfargs)
{
	(*str)++;
	fmt->flags = 0;
	parse_flags(str, fmt);
	if (ft_isdigit(**str))
	{
		fmt->flags |= FMT_WIDTH;
		set_value(&fmt->width, str, pfargs);
	}
	if (**str == '.')
	{
		fmt->flags |= FMT_PREC;
		(*str)++;
		set_value(&fmt->prec, str, pfargs);
	}
	parse_modifiers(str, fmt);
	fmt->char_conv = **str;
	if (**str)
		(*str)++;
	format_general_rule(fmt);
}
