/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: droro <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/03 08:31:55 by droro             #+#    #+#             */
/*   Updated: 2020/11/14 15:08:30 by droro            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	unsigned const char	*s1_p;
	unsigned const char	*s2_p;

	s1_p = s1;
	s2_p = s2;
	while (n--)
	{
		if (*s1_p != *s2_p)
		{
			return (*s1_p - *s2_p);
		}
		s1_p++;
		s2_p++;
	}
	return (0);
}
