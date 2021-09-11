/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcherie <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/23 14:32:25 by bcherie           #+#    #+#             */
/*   Updated: 2020/11/23 14:52:31 by bcherie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t num)
{
	size_t		i;
	char		*s1;
	const char	*s2;

	s1 = (char *)dest;
	s2 = (char *)src;
	i = 0;
	if (!s2 && !s1)
		return (NULL);
	while (i < num)
	{
		s1[i] = s2[i];
		i++;
	}
	return (s1);
}
