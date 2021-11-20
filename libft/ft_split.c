/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: droro <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/19 04:02:35 by droro             #+#    #+#             */
/*   Updated: 2020/11/21 10:49:04 by droro            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	likvidator(char **p, int c)
{
	int		i;

	i = 0;
	while (i < c)
	{
		free(p[i]);
		i++;
	}
	free(p);
	return (0);
}

static int	counter(const char *str, char c)
{
	int			count;
	int			diff;
	const char	*p1;
	const char	*p2;

	p1 = str;
	p2 = str;
	count = 0;
	if (c == '\0')
		return (1);
	while (p2 && *p1)
	{
		p2 = ft_strchr(p1, c);
		diff = p2 - p1;
		p1 = p2 + 1;
		if (diff > 0 || !p2)
			count++;
	}
	return (count);
}

static int	fill(char **ar, const char *p1, int count, char c)
{
	int			diff;
	int			i;
	int			range;
	const char	*p2;

	p2 = p1;
	i = 0;
	while (p2 && *p1 && i < count)
	{
		p2 = ft_strchr(p1, c);
		diff = p2 - p1;
		if (diff > 0 || !p2)
		{
			range = diff;
			if (!p2)
				range = ft_strlen(p1);
			ar[i] = (char *)malloc(range + 1);
			if (!ar[i])
				return (likvidator(ar, i));
			ft_strlcpy(ar[i], p1, range + 1);
			i++;
		}
		p1 = p2 + 1;
	}
	return (1);
}

char	**ft_split(char const *s, char c)
{
	const char	*p1;
	char		**array;
	int			size;

	if (!s)
		return (NULL);
	size = counter(s, c);
	array = (char **)malloc((size + 1) * sizeof(char *));
	if (!array)
		return (NULL);
	array[size] = 0;
	p1 = s;
	if (fill(array, p1, size, c) == 0)
		return (NULL);
	return (array);
}
