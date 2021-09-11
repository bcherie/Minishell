/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcherie <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/05 17:19:35 by bcherie           #+#    #+#             */
/*   Updated: 2020/11/21 17:47:14 by bcherie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dest, const char *src, size_t destsize)
{
	size_t i;
	size_t j;

	i = 0;
	j = 0;
	while (dest[i] != '\0' && i < destsize)
		i++;
	while (src[j] && (j + i) + 1 < destsize)
	{
		dest[i + j] = src[j];
		j++;
	}
	if (i + j < destsize)
		dest[j + i] = '\0';
	return (i + ft_strlen(src));
}
