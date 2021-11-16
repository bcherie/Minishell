/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dollar_ops_2.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: droro <droro@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/16 22:53:48 by droro             #+#    #+#             */
/*   Updated: 2021/11/16 22:53:49 by droro            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	ft_dfbuf_collect(t_dbuf *head, char *newline, int len)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (i < len && head != NULL)
	{
		newline[i] = head->buf[j];
		i++;
		j++;
		if (j == 200)
		{
			head = head->next;
			j = 0;
		}
	}
}
