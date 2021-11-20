/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_token_utils_2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: droro <droro@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/16 22:54:15 by droro             #+#    #+#             */
/*   Updated: 2021/11/16 22:54:16 by droro            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int	simple_startend_check(int start, int end)
{
	if (start < 0 || end < 0 || (end - start) < 0)
		return (0);
	return (1);
}

int	fpf_strchr(const char *s, int c)
{
	size_t	i;
	size_t	len;

	i = 0;
	len = ft_strlen(s);
	while (i < len)
	{
		if (s[i] == c)
			return (1);
		i++;
	}
	return (0);
}

int	ft_spacekill(char *buf, int start, int end)
{
	int	new_start;

	if (simple_startend_check(start, end) == 0)
		return (-1);
	new_start = start;
	while (buf[new_start] == ' ' && new_start < end)
		new_start++;
	if (buf[new_start] == ' ')
		new_start++;
	return (new_start);
}

int	ft_spacekill_left(char *buf, int start, int end)
{
	int	new_end;

	if (simple_startend_check(start, end) == 0)
		return (-1);
	new_end = end;
	while (buf[new_end] == ' ' && new_end > start)
		new_end--;
	return (new_end);
}

int	ft_pretoken_check(char *string, int start, int end)
{
	if (start < 0 || end < 0 || string == NULL || end - start < 0)
		return (-1);
	if (&string[start] == NULL || &string[end] == NULL)
		return (-2);
	if (string[start] == '\0' || string[end] == '\0')
		return (0);
	if (string[start] == 34 || string[start] == 39)
		return (1);
	return (2);
}
