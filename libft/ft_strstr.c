/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: droro <droro@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/21 01:06:37 by droro             #+#    #+#             */
/*   Updated: 2021/11/21 01:06:39 by droro            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *haystack, const char *needle)
{
	size_t	n;
	size_t	num_n;
	size_t	num_h;

	num_n = ft_strlen(needle);
	num_h = ft_strlen(haystack);
	n = 0;
	if (haystack && num_h >= num_n)
	{
		if (num_n == 0)
			return ((char *)haystack);
		while ((num_h - n) >= num_n)
		{
			if (ft_strncmp(haystack + n, needle, num_n) == 0)
				return ((char *)(haystack + n));
			n++;
		}
	}
	return (NULL);
}
