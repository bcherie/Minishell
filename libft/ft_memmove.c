/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: droro <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/03 04:33:43 by droro             #+#    #+#             */
/*   Updated: 2020/11/14 14:49:31 by droro            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	unsigned char		*dst_p;
	unsigned const char	*src_p;
	int					diff;

	dst_p = (unsigned char *)dst;
	src_p = (unsigned char *)src;
	if (!dst && !src)
		return (NULL);
	diff = dst_p - src_p;
	if (diff > 0 && len > (size_t)diff)
	{
		while (len != 0)
		{
			*(dst_p + len - 1) = *(src_p + len - 1);
			len--;
		}
	}
	else
		ft_memcpy(dst, src, len);
	return (dst_p);
}
