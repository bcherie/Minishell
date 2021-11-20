/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   buildin_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: droro <droro@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/16 23:17:42 by droro             #+#    #+#             */
/*   Updated: 2021/11/16 23:18:11 by droro            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_tokens	*ft_lstnew(char *key, char *value)
{
	t_tokens	*new;

	new = (t_tokens *)malloc(sizeof(t_tokens));
	if (!new)
		return (NULL);
	ft_bzero(new, sizeof(t_tokens));
	new->key = key;
	new->value = value;
	new->type = '0';
	new->index = -1;
	new->next = NULL;
	return (new);
}

void	ft_lstadd_back(t_tokens **list, t_tokens *new)
{
	t_tokens	*last;

	last = ft_lstlast(*list);
	if (!new)
		return ;
	else if (!*list)
	{
		*list = new;
		return ;
	}
	last->next = new;
}

t_tokens	*ft_lstlast(t_tokens *lst)
{
	if (lst == NULL)
		return (NULL);
	while (lst->next != NULL)
		lst = lst->next;
	return (lst);
}
