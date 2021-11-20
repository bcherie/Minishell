/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: droro <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/03 04:15:40 by droro             #+#    #+#             */
/*   Updated: 2020/11/21 20:12:14 by droro            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	size_t				i;
	unsigned char		*dst_p;
	unsigned const char	*src_p;

	dst_p = dst;
	src_p = src;
	i = 0;
	while (n--)
	{
		dst_p[i] = src_p[i];
		if (src_p[i] == (unsigned char)c)
		{
			return (dst_p + i + 1);
		}
		i++;
	}
	return (NULL);
}
