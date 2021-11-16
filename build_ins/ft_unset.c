/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_unset.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: droro <droro@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/16 22:56:27 by droro             #+#    #+#             */
/*   Updated: 2021/11/16 22:56:28 by droro            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	ft_unset(t_all *mass, t_tokens *tok)
{
	t_tokens	*tmp;
	int			iter;
	int			length;

	iter = 0;
	while (++iter < tok->count + 1)
	{
		length = ft_strlen(tok->args[iter]);
		tmp = mass->environment;
		while (tmp != NULL)
		{
			if (ft_strncmp(tok->args[iter], tmp->key, length) == 0)
			{
				tmp->type = ENV_TOK_UNSET;
				if (tmp->value != NULL)
					free(tmp->value);
				tmp->value = NULL;
				break ;
			}
			tmp = tmp->next;
		}
	}
}
