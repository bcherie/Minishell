/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcherie <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/08 18:58:10 by bcherie           #+#    #+#             */
/*   Updated: 2020/11/21 17:48:41 by bcherie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t			x;
	unsigned char	*p;
	unsigned char	*b;

	p = (unsigned char *)s1;
	b = (unsigned char *)s2;
	x = 0;
	while (x < n && (p[x] || b[x]))
	{
		if (p[x] != b[x])
			return (p[x] - b[x]);
		x++;
	}
	return (0);
}
