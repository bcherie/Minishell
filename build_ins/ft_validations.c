/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_validations.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: droro <droro@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/16 22:56:35 by droro             #+#    #+#             */
/*   Updated: 2021/11/16 22:56:35 by droro            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int	ft_is_valid_env_token(char *command, char *val)
{
	int	i;

	i = 1;
	if (ft_isalpha(val[0]) == 1 || val[0] == '_')
	{
		while (val[i] != '\0' && val[i] != '=')
		{
			if (!ft_isalnum(val[i]) && !(val[i] == '_'))
			{
				ft_print_report(command, val, REP_IDENT);
				return (0);
			}
			i++;
		}
		return (1);
	}
	ft_print_report(command, val, REP_IDENT);
	return (0);
}
