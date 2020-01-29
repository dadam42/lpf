/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_uitoa_base.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: damouyal <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/12 21:41:23 by damouyal          #+#    #+#             */
/*   Updated: 2020/01/29 18:33:03 by damouyal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*ft_setup(unsigned long d, unsigned short mbase
						, unsigned long *div)
{
	size_t	len;

	*div = 1;
	len = 0;
	while (d / *div >= mbase)
	{
		*div *= mbase;
		len++;
	}
	return (malloc((len + 1) * sizeof(char)));
}

char		*ft_uitoa_base(unsigned long d, char const *base)
{
	unsigned short	mbase;
	unsigned long	div;
	char			*fwd_ret;
	char			*ret;
	unsigned int	q;

	if (!base)
		return (NULL);
	mbase = ft_strlen(base);
	if (mbase > 1 && (ret = ft_setup(d, mbase, &div)))
	{
		fwd_ret = ret;
		while (div > 0)
		{
			q = d / div;
			*fwd_ret++ = base[q];
			d -= q * div;
			div /= mbase;
		}
		*fwd_ret = 0;
		return (ret);
	}
	return (NULL);
}
