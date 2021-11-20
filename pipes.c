/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: droro <droro@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/21 01:32:54 by droro             #+#    #+#             */
/*   Updated: 2021/11/21 01:35:20 by droro            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	count_pipe(t_all *mass)
{
	int	i;

	i = 0;
	while (mass->buf[i])
	{
		if (mass->buf[i] == '|')
			mass->u_mass.pipe++;
		i++;
	}
	mass->u_mass.l_pipe = mass->u_mass.pipe;
}

void	pipes(t_all *mass, t_tokens	*tmp, int *status)
{
	pid_t	pid;

	pid = fork();
	if (pid == 0)
	{
		if (ft_check_buildin(mass, tmp) == 0)
		{
			pid = fork();
			if (pid == 0)
				ft_execve(mass, tmp);
			else
				wait(NULL);
		}
		exit(0);
	}
	else
	{
		waitpid(pid, status, 0);
	}
}
