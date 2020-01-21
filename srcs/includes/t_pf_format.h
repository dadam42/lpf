/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_pf_format.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: damouyal <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/21 16:08:34 by damouyal          #+#    #+#             */
/*   Updated: 2020/01/21 16:08:40 by damouyal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef T_PF_FORMAT_H
# define T_PF_FORMAT_H
# define FMT_ZERO 1
# define FMT_MINUS 2
# define FMT_PREC 4
# define FMT_WIDTH 8
# define STR_FLAGS "0-"

typedef unsigned short	t_flags;
typedef struct			s_pf_format
{
	t_flags flags;
	int		prec;
	int		width;
	char	char_conv;
}						t_pf_format;
#endif
