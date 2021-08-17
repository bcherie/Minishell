/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcherie <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/13 15:35:42 by bcherie           #+#    #+#             */
/*   Updated: 2020/11/23 14:39:40 by bcherie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*dest;
	int		i;
	int		j;
	int		k;

	i = 0;
	k = 0;
	if (!s1 || !set)
		return (NULL);
	if (ft_strlen(s1) == 0)
		return (ft_strdup(""));
	while ((s1[i] != '\0') && (ft_strchr(set, s1[i])))
		i++;
	j = ft_strlen(s1) - 1;
	while ((ft_strchr(set, s1[j])) && j > i)
		j--;
	if (!(dest = (char *)malloc(sizeof(char) * (j - i + 2))))
		return (NULL);
	while (k < j - i + 1)
	{
		dest[k] = s1[i + k];
		k++;
	}
	dest[k] = '\0';
	return (dest);
}
