/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: droro <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/14 19:42:55 by droro             #+#    #+#             */
/*   Updated: 2020/11/20 06:48:29 by droro            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	util(size_t dstsize, size_t dstlen)
{
	if (dstsize > 0)
	{
		if (dstsize - 1 < dstlen)
			return (dstsize);
		else
			return (dstlen);
	}
	return (0);
}

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	i;
	size_t	dstlen;
	size_t	srclen;
	size_t	begin;
	int		maxadd;

	i = 0;
	dstlen = ft_strlen(dst);
	srclen = ft_strlen(src);
	begin = util(dstsize, dstlen);
	maxadd = dstsize - dstlen - 1;
	if (maxadd > 0)
	{
		while (i < srclen && i < (size_t)maxadd)
		{
			dst[begin + i] = src[i];
			i++;
		}
		dst[begin + i] = '\0';
	}
	return (begin + srclen);
}
