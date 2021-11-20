/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: droro <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/15 15:25:12 by droro             #+#    #+#             */
/*   Updated: 2020/11/20 05:10:00 by droro            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	char	*reserved;
	size_t	length;

	length = ft_strlen(s1);
	reserved = (char *)malloc(length + 1);
	if (reserved == NULL)
		return (NULL);
	ft_strlcpy(reserved, s1, length + 1);
	return (reserved);
}
