/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: droro <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/19 04:44:15 by droro             #+#    #+#             */
/*   Updated: 2020/11/19 07:57:21 by droro            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	counter(int n)
{
	int		i;

	i = 1;
	n = (n / 10);
	while (n != 0)
	{
		i++;
		n = (n / 10);
	}
	return (i);
}

static char	discover(int n)
{
	int		nbr;

	nbr = n / 10;
	while (nbr != 0)
	{
		n = n % 10;
		nbr = n / 10;
	}
	if (n < 0)
		return (n * (-1));
	return (n);
}

static void	fill(char *string, int n, int num)
{
	int		j;

	j = 0;
	if (n < 0)
	{
		string[0] = '-';
		j = 1;
	}
	while (num >= j)
	{
		string[num] = discover(n) + '0';
		n = n / 10;
		num--;
	}
}

char	*ft_itoa(int n)
{
	int		len;
	char	*str;

	len = counter(n);
	if (n < 0)
		++len;
	str = (char *)malloc(len + 1);
	if (str == NULL)
		return (NULL);
	str[len] = '\0';
	fill(str, n, len - 1);
	return (str);
}
