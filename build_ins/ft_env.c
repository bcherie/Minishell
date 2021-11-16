/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_env.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: droro <droro@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/16 22:55:55 by droro             #+#    #+#             */
/*   Updated: 2021/11/16 22:55:56 by droro            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	ft_add_environment(t_all *mass, char **env)
{
	int	i;

	i = 0;
	while (env[i] != NULL)
	{
		ft_copy_mark_env_token(mass, env[i]);
		i++;
	}
	ft_update_environment(mass, NULL, "OLDPWD");
}

void	ft_env(t_all *mass, t_tokens *tok)
{
	t_tokens	*tmp;

	tmp = mass->environment;
	if (tok->count != 0)
		ft_print_report(tok->container, tok->args[1], REP_NOFDIR);
	else
	{
		while (tmp != NULL)
		{
			ft_print_env_token(tmp, ENV_TOK_FULL);
			tmp = tmp->next;
		}
	}
}
