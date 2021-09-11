/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcherie <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/13 12:13:04 by bcherie           #+#    #+#             */
/*   Updated: 2020/11/23 14:51:27 by bcherie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	unsigned int	i;
	char			*dest;
	unsigned int	len_s;
	char			*s1;

	s1 = (char *)s;
	if (!s)
		return (0);
	len_s = ft_strlen(s);
	i = 0;
	dest = malloc(len + 1);
	if (dest == NULL)
		return (NULL);
	if (!s1)
		return (NULL);
	while (start < len_s && i < (unsigned int)len && *s1)
	{
		dest[i] = s1[start + i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}
