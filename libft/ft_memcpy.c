/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: droro <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/29 21:02:37 by droro             #+#    #+#             */
/*   Updated: 2020/11/21 19:13:11 by droro            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	size_t				i;
	unsigned char		*k1;
	unsigned const char	*k2;

	i = 0;
	k1 = dst;
	k2 = src;
	if (!dst && !src)
		return (NULL);
	while (i < n)
	{
		k1[i] = k2[i];
		i++;
	}
	return (k1);
}
