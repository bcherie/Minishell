/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcherie <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/03 00:49:52 by bcherie           #+#    #+#             */
/*   Updated: 2020/11/21 17:43:34 by bcherie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t num)
{
	size_t				i;
	unsigned char		*s1;
	unsigned const char	*s2;

	s1 = (unsigned char *)dest;
	s2 = (unsigned const char *)src;
	i = 0;
	if (!s2 && !s1)
		return (s1);
	if (s1 < s2)
		while (i != num)
		{
			s1[i] = s2[i];
			i++;
		}
	else
	{
		while (num)
		{
			s1[num - 1] = s2[num - 1];
			num--;
		}
	}
	return (s1);
}
