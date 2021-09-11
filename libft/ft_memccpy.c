/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcherie <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/29 17:45:47 by bcherie           #+#    #+#             */
/*   Updated: 2020/11/23 14:53:07 by bcherie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *d, const void *s, int c, size_t num)
{
	unsigned char		*s1;
	unsigned char		*s2;

	s1 = (unsigned char *)d;
	s2 = (unsigned char *)s;
	while (num--)
	{
		*s1++ = *s2++;
		if (*(s1 - 1) == (unsigned char)c)
			return (s1);
	}
	return (NULL);
}
