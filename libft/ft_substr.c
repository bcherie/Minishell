/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: droro <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/15 18:19:39 by droro             #+#    #+#             */
/*   Updated: 2020/11/19 23:45:40 by droro            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	util(unsigned int start, size_t len, size_t	s_len, size_t *subs_len)
{
	if (start >= s_len + 1)
		*subs_len = 0;
	else
	{
		if (s_len < len)
			*subs_len = s_len - start;
		else
			*subs_len = len;
	}
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	s_len;
	size_t	i;
	size_t	subs_len;
	char	*substr;

	i = 0;
	if (!s)
		return (NULL);
	s_len = ft_strlen(s);
	util(start, len, s_len, &subs_len);
	substr = (char *)malloc(subs_len + 1);
	if (!substr)
		return (NULL);
	while (start + i < s_len && subs_len--)
	{
		substr[i] = s[start + i];
		i++;
	}
	substr[i] = '\0';
	return (substr);
}
