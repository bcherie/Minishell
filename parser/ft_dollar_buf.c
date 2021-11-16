/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dollar_buf.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: droro <droro@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/16 22:52:35 by droro             #+#    #+#             */
/*   Updated: 2021/11/16 22:52:36 by droro            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

t_dbuf	*ft_dbuf_create(void)
{
	t_dbuf	*dbuf;

	dbuf = NULL;
	dbuf = (t_dbuf *)malloc(sizeof(t_dbuf));
	if (dbuf == NULL)
		return (NULL);
	dbuf->next = NULL;
	dbuf->full = 0;
	ft_bzero(dbuf->buf, 201);
	return (dbuf);
}

t_dbuf	*ft_dbuf_add(t_dbuf **head)
{
	t_dbuf	*tmp;
	t_dbuf	*new;

	tmp = NULL;
	new = ft_dbuf_create();
	if (*head == NULL)
		*head = new;
	else
	{
		tmp = *head;
		while (tmp->next != NULL)
			tmp = tmp->next;
		tmp->next = new;
	}
	return (new);
}

int	ft_dbuf_clean(t_dbuf **head)
{
	t_dbuf	*tmp;

	if (!head || !(*head))
		return (0);
	tmp = NULL;
	while (*head)
	{
		tmp = (*head)->next;
		free(*head);
		*head = NULL;
		*head = tmp;
	}
	return (1);
}

void	ft_dfbuf_addchar(t_dbuf *dbuf, char sym)
{
	while (dbuf->next != NULL)
		dbuf = dbuf->next;
	if (dbuf->full == 200)
	{
		ft_dbuf_add(&dbuf);
		dbuf = dbuf->next;
	}
	dbuf->buf[dbuf->full] = sym;
	(dbuf->full)++;
}

int	ft_dfbuf_count(t_dbuf *dbuf)
{
	int	i;

	i = 0;
	while (dbuf)
	{
		i += dbuf->full;
		dbuf = dbuf->next;
	}
	return (i);
}
