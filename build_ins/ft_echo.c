/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_echo.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: droro <droro@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/16 22:55:45 by droro             #+#    #+#             */
/*   Updated: 2021/11/16 23:15:28 by droro            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

static int	n_test(char *str)
{
	int	i;
	int	len;

	i = 0;
	len = ft_strlen(str);
	if (str[0] != '-')
		return (0);
	while (++i < len)
	{
		if (str[i] != 'n')
			return (0);
	}
	return (1);
}

void	echo_n(t_tokens *tok, int *flag)
{
	int	i;
	int	j;

	i = 1;
	j = 1;
	if (tok->count == 1 && n_test(tok->args[1]) == 1)
	{
		printf("");
		return ;
	}
	if (tok->count >= 1)
	{
		while (tok->args[i] != NULL && n_test(tok->args[i]) == 1)
			i++;
		if (i > 1)
			*flag = 1;
		while (tok->args[i] != NULL)
		{
			if (tok->out_n != 0 && i != 1)
				printf("\n");
			write(1, tok->args[i], ft_strlen(tok->args[i]));
			if (tok->args[i + 1] != NULL)
				write(1, " ", 1);
			i++;
		}
	}
}

void	ft_echo(t_tokens *tok)
{
	int	flag;

	flag = 0;
	if (tok->count == 0)
	{
		if (ft_strlen(tok->container) == 4)
			printf("\n");
	}
	if (tok->count >= 1)
	{
		echo_n(tok, &flag);
		if (flag != 1)
			printf("\n");
	}
}
