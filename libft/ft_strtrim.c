/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: droro <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/15 19:38:35 by droro             #+#    #+#             */
/*   Updated: 2020/11/20 06:59:03 by droro            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static unsigned int	search(char const *string, char const *set)
{
	unsigned int	i;
	int				j;
	int				check;

	i = 0;
	check = 1;
	while (string[i] && *set && check != 0)
	{
		j = 0;
		check = 0;
		while (*(set + j) && check != 1)
		{
			if (*(set + j) == string[i])
				check = 1;
			j++;
		}
		if (check != 0)
			i++;
	}
	return (i);
}

static size_t	count(char const *s, char const *set, size_t l)
{
	size_t			i;

	if (l == 0)
		return (0);
	i = 0;
	while (s[l - i - 1] && ft_strchr(set, s[l - i - 1]))
	{
		i++;
	}
	return (i);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	unsigned int	start;
	size_t			len;
	size_t			length_s1;

	if (!s1 || !set)
		return (NULL);
	length_s1 = ft_strlen(s1);
	start = search(s1, set);
	len = length_s1 - start - count(s1, set, length_s1);
	return (ft_substr(s1, start, len));
}
