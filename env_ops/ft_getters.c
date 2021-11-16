/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_getters.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: droro <droro@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/16 22:52:19 by droro             #+#    #+#             */
/*   Updated: 2021/11/16 22:52:20 by droro            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

char	*ft_envops_getval(t_all *mass, char *key)
{
	t_tokens	*token;

	token = NULL;
	if (key == NULL)
		return (NULL);
	token = ft_is_in_enviroment(mass, key);
	if (token == NULL)
		return (NULL);
	return (token->value);
}

char	*ft_envops_setval(t_all *mass, char *key, char *val)
{
	t_tokens	*token;

	token = NULL;
	if (key == NULL)
		return (NULL);
	token = ft_is_in_enviroment(mass, key);
	if (token == NULL)
		return (NULL);
	if (token->value != NULL)
		free(token->value);
	if (val == NULL)
	{
		token->value = NULL;
		token->type = ENV_TOK_PARTIAL;
	}
	else
	{
		token->value = ft_strdup(val);
		token->type = ENV_TOK_FULL;
	}
	return (token->value);
}
