/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_parser.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: damouyal <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/21 16:07:45 by damouyal          #+#    #+#             */
/*   Updated: 2020/01/21 16:07:47 by damouyal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PF_PARSER_H
# define PF_PARSER_H
# include "t_pf_format.h"
# include <stdarg.h>

void pf_parse(char const **str, t_pf_format *fmt, va_list *pfargs);
#endif
