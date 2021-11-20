/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: droro <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/14 16:46:03 by droro             #+#    #+#             */
/*   Updated: 2020/11/19 04:38:15 by droro            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	i;
	int		j;

	i = 0;
	while (i < n)
	{
		j = (unsigned char)s1[i] - (unsigned char)s2[i];
		if (j != 0 || \
				((unsigned char)s1[i] == '\0' && (unsigned char)s2[i] == '\0'))
			return (j);
		i++;
	}
	return (0);
}
