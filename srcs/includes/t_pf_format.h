/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_pf_format.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: damouyal <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/21 16:08:34 by damouyal          #+#    #+#             */
/*   Updated: 2020/01/29 22:38:58 by damouyal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef T_PF_FORMAT_H
# define T_PF_FORMAT_H
# define FMT_ZERO 1
# define FMT_MINUS 2
# define FMT_SHARP 4
# define FMT_PLUS 8
# define FMT_SPACE 16
# define FMT_PREC 32
# define FMT_WIDTH 64
# define STR_FLAGS "0-#+ "
# define FMT_MOD_H 1
# define FMT_MOD_HH 2
# define FMT_MOD_L 3
# define FMT_MOD_LL 4

typedef unsigned short	t_flags;
typedef unsigned short	t_mod;
typedef struct			s_pf_format
{
	t_flags flags;
	t_mod	mod;
	int		prec;
	int		width;
	char	char_conv;
}						t_pf_format;
#endif
