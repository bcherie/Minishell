/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exit.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: droro <droro@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/16 22:56:02 by droro             #+#    #+#             */
/*   Updated: 2021/11/16 22:56:02 by droro            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	ft_exit(t_all *mass, t_tokens *tok)
{
	long long	exit_number;
	errno_t		ex;

	exit_number = 0;
	if (tok->count > 0)
	{
		if (ft_ms_atoi_checksyms(tok->args[1]) == 0)
		{
			printf("exit\n");
			ft_print_report(tok->container, tok->args[1], REP_NUMARG);
		}
		else
		{	
			exit_number = ft_atolonglong(tok->args[1]);
			printf("exit\n");
		}
	}
	else
		printf("exit\n");
	global_cleaner(mass, 1);
	ex = 2;
	errno = ex;
	exit(errno);
}
