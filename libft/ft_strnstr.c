/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: droro <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/15 14:43:24 by droro             #+#    #+#             */
/*   Updated: 2020/11/21 20:30:29 by droro            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	n;
	size_t	num_n;
	size_t	num_h;

	num_n = ft_strlen(needle);
	num_h = ft_strlen(haystack);
	n = 0;
	if (haystack && num_h >= num_n && len >= num_n)
	{
		if (num_n == 0)
			return ((char *)haystack);
		while ((num_h - n) >= num_n && (len - n) >= num_n)
		{
			if (ft_strncmp(haystack + n, needle, num_n) == 0)
				return ((char *)(haystack + n));
			n++;
		}
	}
	return (NULL);
}
